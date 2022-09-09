#include "calculate_results.h"

void calculate_results(){
    cout<< "[RESULTS] Writing results..." << endl;

    IS_METRICS_RUNNING = true;

    const int max_num_of_worker = 32;
    const int num_of_trial = 10;

    plot_1_speedup(1024, max_num_of_worker,num_of_trial);
    plot_1_speedup(4096, max_num_of_worker,num_of_trial);
    plot_1_speedup(16384, max_num_of_worker,num_of_trial);

    plot_2_scalability(1024, max_num_of_worker,num_of_trial);
    plot_2_scalability(4096, max_num_of_worker,num_of_trial);
    plot_2_scalability(16384, max_num_of_worker,num_of_trial);

    plot_3_efficiency(1024, max_num_of_worker,num_of_trial);
    plot_3_efficiency(4096, max_num_of_worker,num_of_trial);
    plot_3_efficiency(16384, max_num_of_worker,num_of_trial);

    plot_4_barrier_overhead(1024, max_num_of_worker,num_of_trial);
    plot_4_barrier_overhead(4096, max_num_of_worker,num_of_trial);
    plot_4_barrier_overhead(16384, max_num_of_worker,num_of_trial);

    plot_5_threads_overhead(4096, max_num_of_worker, num_of_trial);

    IS_METRICS_RUNNING = false;

    cout<< "[RESULTS] Done." << endl;
}