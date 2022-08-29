#ifndef SPM22_ACCIARO_PROJECT_FAST_FLOW_H
#define SPM22_ACCIARO_PROJECT_FAST_FLOW_H

#include <vector>
#include "../utils/utimer.h"
#include <thread>
#include <barrier>
#include <iostream>
#include "../utils/utility.h"
#include "../setup/runtime_steps.h"
#include "../utils/useful_classes/SolutionResult.h"

using namespace std;

SolutionResult solve_jacobi_with_fastflow(vector<vector<float>> A, vector<float>B, int num_of_worker,
                                          int number_of_iteration = NUMBER_OF_ITERATION,
                                          bool early_stopping = EARLY_STOPPING);


#endif //SPM22_ACCIARO_PROJECT_FAST_FLOW_H
