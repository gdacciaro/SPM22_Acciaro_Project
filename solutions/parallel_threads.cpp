#include "parallel_threads.h"

using namespace std;

std::mutex mtx;
void print(const string& msg) {
    mtx.lock();
    cout << msg;
    mtx.unlock();
}

SolutionResult solve_jacobi_with_threads(vector<vector<float>> A, vector<float>B,
                                         int num_of_worker, int number_of_iteration, bool early_stopping) {
    const int n = (int)A.size();
    long long time;
    vector<float> x(n, 0);
    vector<float> tmp_x(n, 0);
    float total_barrier_time = 0;
    vector<thread> threads;

    { // scope start
        uTimer utimer("Par");

        if(!IS_UNIT_TEST_RUNNING && !IS_METRICS_RUNNING){
            cout<<"[PTH] Running with "<<num_of_worker<<" worker(s)..."<<endl;
        }

        bool break_the_loop = false; // Flag to break the loop.
        int iteration = number_of_iteration; // When iteration is 0, the loop will break.

        function<void()> update = [&]() -> void { // Lambda function used into the barrier.
            iteration = iteration - 1;

            float dist = eucl_dist(x,tmp_x); // Calculate the distance between the two vectors with the euclidean distance.

            if (dist < CONVERGENCE_THRESHOLD && early_stopping){ // If the distance is smaller than the threshold, stop the loop.
                break_the_loop = true;
                iteration = 0;
            }else{  // If the distance is bigger than the threshold, continue the loop.
                x = tmp_x; // Update the x vector.
            }
        };
        barrier barrier(num_of_worker, update); // barrier for the threads

        auto jacobi_function = [&](int id, int start, int end) {
            while (true) {
                if (iteration == 0) // if the iteration is 0, the thread should stop.
                    break;
                for (int i = start; i < end; i++) {
                    float first_term = 1 / A[i][i]; // The first term of the jacobi equation.
                    float second_term = B[i];       // The second term of the jacobi equation.
                    float third_term = 0;

                    for (int j = 0; j < n; j++) {   // Calculates the third term of the jacobi equation.
                        if (j != i)
                            third_term += A[i][j] * x[j];
                    }

                    float diff = (second_term - third_term);
                    tmp_x[i] = first_term * diff;
                }

                { // The barrier introduces an overhead.
                    uTimer barrier_time("Barrier time");                // Start the timer
                    barrier.arrive_and_wait();
                    total_barrier_time += (float)barrier_time.stop_timer(); // Stop the timer
                }

                if (break_the_loop) // If the flag is true, the thread should stop.
                    break;
            }
            return;
        };

        int chunk = (int) ceil(n / num_of_worker); // Calculate the chunk size

        for (int i = 0; i < num_of_worker-1; i++){ // Create the threads
            int start = i * chunk;
            int end = (i + 1) * chunk;
            threads.emplace_back(jacobi_function, i, start, end);
        }
        threads.emplace_back(jacobi_function, num_of_worker, (num_of_worker-1) * chunk, n); // Create the last thread

        for (auto& thread : threads) { // Wait for all the threads to finish.
            thread.join();
        }
        threads.clear();

        time = utimer.stop_timer(); // Stop the timer.
    }

    if(!IS_UNIT_TEST_RUNNING && !IS_METRICS_RUNNING){
        cout<<"[PTH] Done."<<endl;
        if(DEBUG) {
            cout << "[PTH] num_of_worker: " << num_of_worker << "" << endl;
            cout << "[PTH] overhead: " << total_barrier_time << "" << endl;
            cout << "[PTH] norm2(x): " << norm2(x) << "" << endl;
            cout << "[PTH] Time: " << time << " ms" << endl;
            cout << endl;
        }
    }

    SolutionResult result;
    result.result = x;
    result.time = time;
    result.total_barrier_time = (float)total_barrier_time;
    return result;
}

