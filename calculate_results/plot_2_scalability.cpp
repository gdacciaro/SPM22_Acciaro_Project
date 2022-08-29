#include "plot_2_scalability.h"

void plot_2_scalability(int n, int max_num_of_workers, int num_of_trial /*per la media*/){
    string TAG = "[RESULTS][PLOT_2][n="+to_string(n)+"]";
    string file_name = "./plot_2_scalability_"+ to_string(n)+".csv";

    ofstream csv;
    csv.open (file_name);

    int index = 0;
    csv << "num of workers\tScalability Threads\tScalability Fast Flow\tThread time\tFF time\n";

    vector<vector<float>> A = init_matrix_random_strictly_dominant(n);
    vector<float> b = init_vector_random(n);

    auto result_thread_one_worker = solve_jacobi_with_threads(A, b, 1, NUMBER_OF_ITERATION, true);
    auto result_fast_flow_one_worker = solve_jacobi_with_fastflow(A, b, 1, NUMBER_OF_ITERATION, true);

    for(int nw = 1; nw <= max_num_of_workers; nw++){
        float mean_threads_time = 0;
        float mean_ff_time = 0;
        float mean_scalability_threads = 0;
        float mean_scalability_ff = 0;

        for(int trial = 1; trial <= num_of_trial; trial++) {
            auto result_parallel = solve_jacobi_with_threads(A, b, nw, NUMBER_OF_ITERATION, true);
            auto result_parallel_fastflow = solve_jacobi_with_fastflow(A, b, nw, NUMBER_OF_ITERATION, true);

            float scalability_threads = ((float) result_thread_one_worker.time) / ((float) result_parallel.time);
            float scalability_ff = ((float) result_fast_flow_one_worker.time) / ((float) result_parallel_fastflow.time);
            mean_scalability_threads += scalability_threads;
            mean_scalability_ff += scalability_ff;

            mean_threads_time += (float) result_parallel.time;
            mean_ff_time += (float) result_parallel_fastflow.time;
        }
        mean_scalability_threads /= (float)num_of_trial;
        mean_scalability_ff /= (float)num_of_trial;
        mean_threads_time /= (float)num_of_trial;
        mean_ff_time /= (float)num_of_trial;

        csv << nw << "\t" << mean_scalability_threads << "\t" << mean_scalability_ff
                              << "\t" << mean_threads_time
                              << "\t" << mean_ff_time
                              << "\n";

        cout <<TAG<< " Writing result "<<index+1<<"/"<<max_num_of_workers<<" done."<< endl;
        index++;
    }
    csv.close();
}