#include "test_fastflow.h"

static const vector<vector<float>> A = {{5.0,-2.0,3.0},
                                        {-3.0,9.0,1.0},
                                        {2.0,-1.0,-7.0}};
static const vector<float> b = {-1.0,2.0,3.0};
static const vector<float> true_x = {0.18612 , 0.33123 , -0.422713};
static const int num_of_iteration = 12; //This problem converges in 12 iterations

void test_all_sol_fast_flow_n3_with_early_stopping(){
    auto result = solve_jacobi_with_fastflow(A, b, 3, 100, true);
    assert_vector_equals(result.result, true_x);
}

void test_all_sol_fast_flow_n3_without_early_stopping(){
    auto result = solve_jacobi_with_fastflow(A, b, 3, num_of_iteration, false);
    assert_vector_equals(result.result, true_x);
}

void test_all_sol_fast_flow_n3_with_nw1(){
    auto result = solve_jacobi_with_fastflow(A, b, 1, 100, true);
    assert_vector_equals(result.result, true_x);
}

void test_all_sol_fast_flow_n3_with_nw2(){
    auto result = solve_jacobi_with_fastflow(A, b, 2, 100, true);
    assert_vector_equals(result.result, true_x);
}

void test_all_sol_fast_flow(){
    test_all_sol_fast_flow_n3_with_early_stopping();
    test_all_sol_fast_flow_n3_without_early_stopping();
    test_all_sol_fast_flow_n3_with_nw1();
    test_all_sol_fast_flow_n3_with_nw2();
}
