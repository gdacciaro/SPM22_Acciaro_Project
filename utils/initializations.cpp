#include "initializations.h"

// Generate a random strictly dominant matrix because we like convergence
vector<vector<float>> init_matrix_random_strictly_dominant(int n){
    if (n <= 0){
        throw invalid_argument("n must be greater than 0");
    }
    vector<vector<float>> matrix;
    vector<float> sum_of_all_abs_elements_that_are_not_on_the_diagonal(n,0); // This vector will store the sum of all abs(elements) that are not on the diagonal

    for(int i = 0; i < n; i++){
        vector<float> row;
        for(int j = 0; j < n; j++){
            if( i == j ){ // Diagonal elements are calculated after
                row.push_back(0);
            }else{
                float random_value = get_random_number(RAND_LOW_VALUE, RAND_HIGH_VALUE); // Generate a random number between RAND_LOW_VALUE and RAND_HIGH_VALUE
                row.push_back(random_value);
                sum_of_all_abs_elements_that_are_not_on_the_diagonal[i] += abs(random_value); // Update the sum of all abs(elements) that are not on the diagonal
            }
        }
        matrix.push_back(row);
    }

    for(int i = 0; i < n; i++){ // Update the diagonal elements
        matrix[i][i] = sum_of_all_abs_elements_that_are_not_on_the_diagonal[i]+1;
    }
    return matrix;
}

// Generate a random vector
vector<float> init_vector_random(int n){
    if (n <= 0){
        throw invalid_argument("n must be greater than 0");
    }
    vector<float> row;
    for(int j = 0;  j < n; j++){
        float random_value = get_random_number(RAND_LOW_VALUE, RAND_HIGH_VALUE);
        row.push_back(random_value);
    }
    return row;
}

// Generate a random number between low and high
float get_random_number(float low, float high){
    //check parameters
    if (low >= high){
        throw invalid_argument("low must be lower than high");
    }

    return (float)low + (float)(rand()) / ( (float) (RAND_MAX/(high-low)));
}