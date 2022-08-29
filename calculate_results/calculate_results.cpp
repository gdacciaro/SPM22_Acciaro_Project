#include "calculate_results.h"


void calculate_results(){
    cout<< "[RESULTS] Writing results..." << endl;

    IS_METRICS_RUNNING = true;

    plot_1_speedup(1024, 120,10);
    plot_1_speedup(4096, 120,10);
    plot_1_speedup(16384, 120,10);
    //
    plot_2_scalability(1024, 120,10);
    plot_2_scalability(4096, 120,10);
    plot_2_scalability(16384, 120,10);

    plot_3_efficiency(1024, 120,10);
    plot_3_efficiency(4096, 120,10);
    plot_3_efficiency(16384, 120,10);

    plot_4_barrier_overhead(1024, 120,10);
    plot_4_barrier_overhead(4096, 120,10);
    plot_4_barrier_overhead(16384, 120,10);

    plot_5_theads_overhead(1024, 120,10);
    plot_5_theads_overhead(4096, 120,10);
    plot_5_theads_overhead(16384, 120,10);

    IS_METRICS_RUNNING = false;
}