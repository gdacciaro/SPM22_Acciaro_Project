#ifndef SPM22_ACCIARO_PROJECT_PLOT_3_EFFICIENCY_H
#define SPM22_ACCIARO_PROJECT_PLOT_3_EFFICIENCY_H

#include "vector"
#include "iostream"
#include "../utils/initializations.h"
#include "../solutions/sequential.h"
#include "../solutions/fast_flow.h"
#include "../solutions/parallel_threads.h"
#include "../setup/runtime_steps.h"
#include <fstream>

using namespace std;

void plot_3_efficiency(int n, int max_num_of_workers=32, int num_of_trial=10 /*per la media*/);

#endif //SPM22_ACCIARO_PROJECT_PLOT_3_EFFICIENCY_H
