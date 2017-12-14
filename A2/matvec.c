#include "dot.h"

void matrix_times_vector (int m , int n , double A[] , double x[] , double y[]){

  double temp[n];

  for(int i = 0; i < m; i++){

    for(int j = 0; j < n; j++){
      temp[j] = A[i * n + j];
    }

    y[i] = dotproduct(n, temp, x);

  }


}
