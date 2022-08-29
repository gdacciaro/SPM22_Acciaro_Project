#include "test_norm2.h"

void test_norm2_valid_case(){
    vector<float> A = {1.0,2.0,3.0,4.0,5.0};
    float result = norm2(A);
    auto true_result = (float)sqrt(1+4+9+16+25);
    assert(result == true_result);
}

void test_norm2_empty_array(){
    vector<float> A = {};
    float result = norm2(A);
    auto true_result = (float)0;
    assert(result == true_result);
}

void test_all_norm2(){
    test_norm2_valid_case();
    test_norm2_empty_array();
}