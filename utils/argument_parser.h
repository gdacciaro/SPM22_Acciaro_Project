#ifndef SPM22_ACCIARO_PROJECT_ARGUMENT_PARSER_H
#define SPM22_ACCIARO_PROJECT_ARGUMENT_PARSER_H

#include "iostream"
#include "../setup/constants.h"

using namespace std;

class ArgumentValues {
    public:
        int n;
        int num_of_worker;
        int calc_results;
        int num_of_iteration;
        int early_stopping;
        int execute_unit_test;
};
class ArgumentParser {
public:
    static ArgumentValues parse_arguments(int argc, char** argv);
};

#endif //SPM22_ACCIARO_PROJECT_ARGUMENT_PARSER_H
