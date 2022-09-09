#include "sequential.h"

using namespace std;

SolutionResult solve_jacobi_sequentially(vector<vector<float>> A, vector<float>B,
                                         int number_of_iteration, bool early_stopping){
    const int n = (int)A.size();
    if(!IS_UNIT_TEST_RUNNING && !IS_METRICS_RUNNING){
        cout<<"[SEQ] Running..."<<endl;
    }

    vector<float> x(n, 0);
    int iteration = number_of_iteration;
    long long time;
    vector<float> tmp_x(n, 0);

    { // scope start
        uTimer utimer("Seq"); // start sequential timer

        while(true) { // loop over the number of iterations
            if (iteration == 0) // if the number of iterations is 0, stop the loop.
                break;
            iteration = iteration - 1;

            for (int i = 0; i < n; i++) {
                float first_term = 1/A[i][i];   // The first term of the jacobi equation.
                float second_term = B[i];       // The second term of the jacobi equation.

                float third_term = 0;
                for (int j = 0; j < n; j++) {   // Calculates the third term of the jacobi equation.
                    if(j!=i)
                        third_term += A[i][j] * x[j];
                }

                tmp_x[i] = first_term * (second_term - third_term);
            }

            float dist = eucl_dist(x,tmp_x); // Calculate the distance between the two vectors with the euclidean distance.
            if (dist < CONVERGENCE_THRESHOLD && early_stopping){ // If the distance is smaller than the threshold, stop the loop.
                break;
            }   // If the distance is bigger than the threshold, continue the loop.
            x = tmp_x; // Update the x vector.
        }

        time = utimer.stop_timer();
    } // scope end

    // Write the metrics
    if(!IS_UNIT_TEST_RUNNING && !IS_METRICS_RUNNING){
        cout<<"[SEQ] Number of iterations: "<<number_of_iteration<<endl;
        cout<<"[SEQ] Time: "<<time<<" ms"<<endl;
    }


    if(!IS_UNIT_TEST_RUNNING and !IS_METRICS_RUNNING){
        cout<<"[SEQ] Done."<<endl;
        if(DEBUG) {
            cout << "[SEQ] norm2(x): " << norm2(x) << "" << endl;
            cout << "[SEQ] iteration required: " << number_of_iteration - iteration << "" << endl;
            cout << "[SEQ] Time: " << time << " ms" << endl;
            cout << endl;
        }
    }

    SolutionResult result; // Create the result object.
    result.result = x;
    result.time = time;
    return result;
}