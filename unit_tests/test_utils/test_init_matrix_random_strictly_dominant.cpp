#include "test_init_matrix_random_strictly_dominant.h"

// Check if the matrix is strictly dominant
bool is_strictly_dominant(vector<vector<float>> m, int n){
    for (int i = 0; i < n; i++){
        // for each column, finding sum of each row.
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += abs(m[i][j]);

        // removing the diagonal element.
        sum -= abs(m[i][i]);

        // checking if diagonal element is less
        // than sum of non-diagonal element.
        if (abs(m[i][i]) < sum)
            return false;
    }

    return true;
}

void test_init_matrix_random_strictly_dominant_n_2(){
    int n = 2;
    auto m = init_matrix_random_strictly_dominant(n);
    assert(is_strictly_dominant(m, n));
}
void test_init_matrix_random_strictly_dominant_n_3(){
    int n = 3;
    auto m = init_matrix_random_strictly_dominant(n);
    assert(is_strictly_dominant(m, n));
}
void test_init_matrix_random_strictly_dominant_n_100(){
    int n = 100;
    auto m = init_matrix_random_strictly_dominant(n);
    assert(is_strictly_dominant(m, n));
}
void test_init_matrix_random_strictly_dominant_n_0(){ // n must be greater than 0
    int n = 0;
    try {
        auto m = init_matrix_random_strictly_dominant(n);
        assert(false);
    } catch (const invalid_argument& e) {
        assert(true);
    }
}

void test_init_matrix_random_strictly_dominant_negative_n(){ // n must be greater than 0
    int n = -10;
    try {
        auto m = init_matrix_random_strictly_dominant(n);
        assert(false);
    } catch (const invalid_argument& e) {
        assert(true);
    }
}

void test_all_init_matrix_random_strictly_dominant(){
    test_init_matrix_random_strictly_dominant_negative_n();
    test_init_matrix_random_strictly_dominant_n_0();
    test_init_matrix_random_strictly_dominant_n_2();
    test_init_matrix_random_strictly_dominant_n_3();
    test_init_matrix_random_strictly_dominant_n_100();
}