#include "UnitTestManager.h"

using namespace std;

UnitTestManager::UnitTestManager(bool execute_unit_test) {
    if(execute_unit_test){ //if the user wants to execute the unit test, then we execute it
        IS_UNIT_TEST_RUNNING = true;
        cout<< "[UT] Running unit tests..." << endl;
        run_unit_test();
    }
}

UnitTestManager::~UnitTestManager() {
    IS_UNIT_TEST_RUNNING = false;
}

void UnitTestManager::run_unit_test() { //Runs all unit tests
    test_all_norm2();
    test_all_eucl_dist();
    test_all_init_matrix_random_strictly_dominant();

    //Solution tests
    test_all_sol_sequential();
    test_all_sol_parallel_threads();
    test_all_sol_fast_flow();

    cout<< "[UT] Unit tests completed." << endl;
}
