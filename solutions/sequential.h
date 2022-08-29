#ifndef SPM22_ACCIARO_PROJECT_SEQUENTIAL_H
#define SPM22_ACCIARO_PROJECT_SEQUENTIAL_H

#include <vector>
#include "../setup/constants.h"
#include "../setup/runtime_steps.h"
#include "../utils/utimer.h"
#include "../utils/utility.h"
#include "../utils/useful_classes/SolutionResult.h"

using namespace std;

SolutionResult solve_jacobi_sequentially(vector<vector<float>> A, vector<float>B,
                                         int number_of_iteration = NUMBER_OF_ITERATION,
                                         bool early_stopping = EARLY_STOPPING
                                         );

#endif //SPM22_ACCIARO_PROJECT_SEQUENTIAL_H
