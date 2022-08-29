#include "unit_test_utils.h"

void assert_vector_equals(vector<float> v1, vector<float> v2){
    float threshold = 0.000001;
    if(v1.size() != v2.size()){ //if the two vectors have different size, they are not equal
        cout << "[assert_vector_equals] Error: vector size not equal" << endl;
        assert(false);
    }
    for(int i = 0; i < v1.size(); i++){
        if(abs(v1[i] - v2[i]) > threshold){ //if the difference is greater than the threshold, then the vectors are not equal
            cout << "[assert_vector_equals] Error: vector element not equal:"<< v1[i] << " " << v2[i] << endl;
            assert(false);
        }
    }
}