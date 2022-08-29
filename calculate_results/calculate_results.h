#ifndef SPM22_ACCIARO_PROJECT_CALCULATE_RESULTS_H
#define SPM22_ACCIARO_PROJECT_CALCULATE_RESULTS_H

#include "vector"
#include "iostream"
#include "../utils/initializations.h"
#include "../solutions/sequential.h"
#include "../solutions/parallel_threads.h"
#include "../setup/runtime_steps.h"
#include <fstream>
#include "./plot_1_speedup.h"
#include "./plot_2_scalability.h"
#include "./plot_3_efficiency.h"
#include "./plot_4_barrier_overhead.h"
#include "./plot_5_theads_overhead.h"
using namespace std;

void calculate_results();

#endif //SPM22_ACCIARO_PROJECT_CALCULATE_RESULTS_H
