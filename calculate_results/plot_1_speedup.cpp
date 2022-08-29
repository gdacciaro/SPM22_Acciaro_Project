#include "plot_1_speedup.h"

void plot_1_speedup(int n, int max_num_of_workers, int num_of_trial /*per la media*/){
    string TAG = "[RESULTS][PLOT_1][n="+to_string(n)+"]";
    string file_name = "./plot_1_speedup_"+ to_string(n)+".csv";

    ofstream csv;
    csv.open (file_name);

    int index = 0;
    csv << "num of workers\tSpeedup Threads\tSpeedup Fast Flow\tSeq time\tThread time\tFF time\n";

    vector<vector<float>> A = init_matrix_random_strictly_dominant(n);
    vector<float> b = init_vector_random(n);

    auto result_sequential= solve_jacobi_sequentially(A, b, NUMBER_OF_ITERATION, true);

    for(int nw = 1; nw <= max_num_of_workers; nw++){

        float mean_threads_time = 0;
        float mean_ff_time = 0;
        float mean_speed_up_threads = 0;
        float mean_speed_up_ff = 0;

        for(int trial = 1; trial <= num_of_trial; trial++) {
            auto result_parallel = solve_jacobi_with_threads(A, b, nw, NUMBER_OF_ITERATION, true);
            auto result_parallel_fastflow = solve_jacobi_with_fastflow(A, b, nw, NUMBER_OF_ITERATION, true);

            float speed_up_threads = ((float) result_sequential.time) / ((float) result_parallel.time);
            float speed_up_ff = ((float) result_sequential.time) / ((float) result_parallel_fastflow.time);
            mean_speed_up_threads += speed_up_threads;
            mean_speed_up_ff += speed_up_ff;

            mean_threads_time += (float) result_parallel.time;
            mean_ff_time += (float) result_parallel_fastflow.time;
        }
        mean_speed_up_threads /= (float)num_of_trial;
        mean_speed_up_ff /= (float)num_of_trial;
        mean_threads_time /= (float)num_of_trial;
        mean_ff_time /= (float)num_of_trial;

        csv << nw << "\t" << mean_speed_up_threads << "\t" << mean_speed_up_ff
                    << "\t" << result_sequential.time
                    << "\t" << mean_threads_time
                    << "\t" << mean_ff_time
                    << "\n";

        cout <<TAG<< " Writing result "<<index+1<<"/"<<max_num_of_workers<<" done."<< endl;
        index++;
    }
    csv.close();
}