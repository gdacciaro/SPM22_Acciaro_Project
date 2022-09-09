#include "argument_parser.h"

string get_key(const string& s){
    string delimiter = "=";
    return s.substr(0, s.find(delimiter));
}
string get_value(string s){
    size_t pos;
    string token;
    string delimiter = "=";
    while ((pos = s.find(delimiter)) != std::string::npos) {
        s.erase(0, pos + delimiter.length());
    }
    return s;
}

ArgumentValues ArgumentParser::parse_arguments(int argc, char** argv){
    ArgumentValues values{N,NUM_OF_WORKER,CALCULATE_RESULTS,
                          NUMBER_OF_ITERATION, EARLY_STOPPING, EXECUTE_UNIT_TEST};

    for (int i = 1; i < argc; ++i){
        string s = argv[i];

        if(get_key(s) == "n" || get_key(s) == "N"){
            values.n = stoi(get_value(s));
            if(values.n<0){
                throw invalid_argument("n must be greater than 0");
            }
        }
        if(get_key(s) == "num_of_worker" || get_key(s) == "n_w" || get_key(s) == "nw" || get_key(s) == "n_workers" || get_key(s) == "num_of_workers"){
            values.num_of_worker = stoi(get_value(s));
            if(values.num_of_worker<0){
                throw invalid_argument("num_of_worker must be greater than 0");
            }
        }
        if(get_key(s) == "num_of_iterations" || get_key(s) == "it" || get_key(s) == "iteration" || get_key(s) == "num_of_iteration"){
            values.num_of_iteration = stoi(get_value(s));
            if(values.num_of_iteration<0){
                throw invalid_argument("num_of_iteration must be greater than 0");
            }
        }
        if(get_key(s) == "calculate_results"  || get_key(s) == "results"  || get_key(s) == "calc_results" ){
            values.calc_results = stoi(get_value(s));
            if(values.calc_results != 0 && values.calc_results != 1){
                throw invalid_argument("calc_results must be 0 or 1");
            }
        }
        if(get_key(s) == "early_stopping" || get_key(s) == "early_stop" || get_key(s) == "early_stopping_enabled" || get_key(s) == "early_stopping_enabled"){
            values.early_stopping = stoi(get_value(s));
            if(values.early_stopping != 0 && values.early_stopping != 1){
                throw invalid_argument("early_stopping must be 0 or 1");
            }
        }
        if(get_key(s) == "execute_unit_test" || get_key(s) == "u_t" || get_key(s) == "unit_test" || get_key(s) == "execute_unit_tests"){
            values.execute_unit_test = stoi(get_value(s));
            if(values.execute_unit_test != 0 && values.execute_unit_test != 1){
                throw invalid_argument("execute_unit_test must be 0 or 1");
            }
        }
    }

    return values;
}