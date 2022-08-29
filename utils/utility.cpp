#include "utility.h"

float norm2(vector<float> v){ // Compute the norm2 of a vector
    int n = (int)v.size();
    float sum = 0;

    for (int i=0; i<n; i++) {
        float item = v[i];
        sum += pow(item, 2);
    }

    return sqrt(sum);
}

float eucl_dist(vector<float> x, vector<float> y){// Compute the euclidean distance between two vectors
    int n = (int)x.size();
    vector<float> z(n,0);

    for (int i=0; i<n; i++) {
        z[i] = x[i] - y[i];
    }
    return norm2(z);
}
