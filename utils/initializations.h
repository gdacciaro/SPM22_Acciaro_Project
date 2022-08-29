#ifndef SPM22_ACCIARO_PROJECT_INITIALIZATIONS_H
#define SPM22_ACCIARO_PROJECT_INITIALIZATIONS_H
#include <iostream>
#include "../setup/constants.h"
#include "random"
using namespace std;

vector<vector<float>> init_matrix_random_strictly_dominant(int n);
vector<float> init_vector_random(int n);
float get_random_number(float low, float high);

#endif //SPM22_ACCIARO_PROJECT_INITIALIZATIONS_H
