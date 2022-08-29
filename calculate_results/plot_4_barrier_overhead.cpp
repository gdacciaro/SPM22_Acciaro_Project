#include "plot_4_barrier_overhead.h"

void plot_4_barrier_overhead(int n, int max_num_of_workers, int num_of_trial /*per la media*/){
    string TAG = "[RESULTS][PLOT_4][n="+to_string(n)+"]";
    string file_name = "./plot_4_barrier_overhead_"+ to_string(n)+".csv";

    ofstream csv;
    csv.open (file_name);

    int index = 0;
    csv << "num of workers\tmean_barrier_time\n";

    vector<vector<float>> A = init_matrix_random_strictly_dominant(n);
    vector<float> b = init_vector_random(n);

    for(int nw = 1; nw <= max_num_of_workers; nw++){
        float mean_barrier_time = 0;

        for(int trial = 1; trial <= num_of_trial; trial++) {
            auto result_parallel = solve_jacobi_with_threads(A, b, nw, NUMBER_OF_ITERATION, true);
            mean_barrier_time += (float) result_parallel.total_barrier_time;
        }
        mean_barrier_time /= (float)num_of_trial;

        csv << nw << "\t" << mean_barrier_time << "\n";

        cout <<TAG<< " Writing result "<<index+1<<"/"<<max_num_of_workers<<" done."<< endl;
        index++;
    }
    csv.close();

}