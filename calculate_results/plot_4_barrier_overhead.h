#ifndef SPM22_ACCIARO_PROJECT_PLOT_4_BARRIER_OVERHEAD_H
#define SPM22_ACCIARO_PROJECT_PLOT_4_BARRIER_OVERHEAD_H

#include "vector"
#include "iostream"
#include "../utils/initializations.h"
#include "../solutions/sequential.h"
#include "../solutions/fast_flow.h"
#include "../solutions/parallel_threads.h"
#include "../setup/runtime_steps.h"
#include <fstream>

using namespace std;

void plot_4_barrier_overhead(int n, int max_num_of_workers=120, int num_of_trial=10 /*per la media*/);

#endif //SPM22_ACCIARO_PROJECT_PLOT_4_BARRIER_OVERHEAD_H
