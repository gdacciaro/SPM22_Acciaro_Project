#include "fast_flow.h"
#include <ff/ff.hpp>
#include <ff/parallel_for.hpp>

using namespace std;

SolutionResult solve_jacobi_with_fastflow(vector<vector<float>> A, vector<float> B,
                                         int num_of_worker, int number_of_iteration, bool early_stopping) {
    const int n = (int) A.size();
    long long time = 0;
    vector<float> x(n, 0);
    vector<float> tmp_x(n, 0);

    { // scope start
        uTimer utimer("FastFlow"); // start FastFlow timer

        if (!IS_UNIT_TEST_RUNNING && !IS_METRICS_RUNNING) {
            cout << "[FF] Running with " << num_of_worker << " worker(s)..." << endl;
        }

        ff::ParallelFor pf(num_of_worker);            //declaration of a ParallelFor object with nthread workers

        for (int k = 0; k < number_of_iteration; k++) {     //loop over the number of iterations

            auto jacobi_function = [&](const long i) {
                float first_term = 1 / A[i][i]; // The first term of the jacobi equation.
                float second_term = B[i];       // The second term of the jacobi equation.
                float third_term = 0;

                for (int j = 0; j < n; j++) {   // Calculates the third term of the jacobi equation.
                    if (j != i)
                        third_term += A[i][j] * x[j];
                }

                float diff = (second_term - third_term);
                tmp_x[i] = first_term * diff;
            };

            pf.parallel_for(0, n, 1, 0, jacobi_function, num_of_worker);

            float dist = eucl_dist(x, tmp_x); // Calculate the distance between the two vectors with the euclidean distance.

            if (dist < CONVERGENCE_THRESHOLD && early_stopping) { // If the distance is smaller than the threshold, stop the loop.
                break;
            } else { // If the distance is bigger than the threshold, continue the loop.
                x = tmp_x; // Update the x vector.
            }

        }

        if (!IS_UNIT_TEST_RUNNING && !IS_METRICS_RUNNING) {
            cout << "[FF] Done." << endl;
            if (DEBUG) {
                cout << "[FF] num_of_worker: " << num_of_worker << "" << endl;
                cout << "[FF] norm2(x): " << norm2(x) << "" << endl;
                cout << "[FF] Time: " << time << " ms" << endl;
                cout << endl;
            }
        }

        time = utimer.stop_timer(); // stop FastFlow timer
    }

    SolutionResult result;
    result.result = x;
    result.time = time;
    return result;
}