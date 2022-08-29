#ifndef SPM22_ACCIARO_PROJECT_SOLUTIONRESULT_H
#define SPM22_ACCIARO_PROJECT_SOLUTIONRESULT_H

#include <utility>
#include "vector"

using namespace std;

class SolutionResult { //Class that stores the results of a solution
    public:
        vector<float> result;
        long long time; //The time of the solution
        float total_barrier_time; //Overhead of the barrier
};

#endif //SPM22_ACCIARO_PROJECT_SOLUTIONRESULT_H

