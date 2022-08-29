#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include "test_sequential.h"

static const vector<vector<float>> A = {{5.0,-2.0,3.0},
                                        {-3.0,9.0,1.0},
                                        {2.0,-1.0,-7.0}};
static const vector<float> b = {-1.0,2.0,3.0};
static const vector<float> true_x = {0.18612 , 0.33123 , -0.422713};
static const int num_of_iteration = 12; //This problem converges in 12 iterations

void test_seq_valid_case_n3_with_early_stopping(){
    auto result = solve_jacobi_sequentially(A, b, 100, true);

    assert_vector_equals(result.result, true_x);
}

void test_seq_valid_case_n3_without_early_stopping(){
    auto result = solve_jacobi_sequentially(A, b, num_of_iteration, false);
    assert_vector_equals(result.result, true_x);
}


void test_all_sol_sequential(){
    test_seq_valid_case_n3_without_early_stopping();
    test_seq_valid_case_n3_with_early_stopping();
}
#pragma clang diagnostic pop