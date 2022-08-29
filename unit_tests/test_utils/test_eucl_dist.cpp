#include "test_eucl_dist.h"


void test_eucl_dist_valid_case_3d(){ // Test the euclidean distance between two vectors of size 3
    vector<float> A = {1.0,2.0,3.0};
    vector<float> B = {4.0,5.0,6.0};
    float result = eucl_dist(A,B);
    auto true_result = (float)5.196152;
    assert(result == true_result);
}

void test_eucl_dist_empty_array(){ // Test the case when both vectors are empty
    vector<float> A = {};
    vector<float> B = {};
    float result = eucl_dist(A,B);
    auto true_result = (float)0;
    assert(result == true_result);
}

void test_all_eucl_dist(){
    test_eucl_dist_valid_case_3d();
    test_eucl_dist_empty_array();
}