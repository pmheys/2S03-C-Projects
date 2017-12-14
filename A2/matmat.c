#include "matvec.h"
#include <stdio.h>

void matrix_times_matrix (int m , int n , int p , double A[] , double B[] , double C[]){

  double tempB[n], tempC[n];

  for(int i = 0; i < p; i++){

    for(int j = 0; j < n; j++){  //Pulls the col out of B
      tempB[j] = B[i + j * p];
    }

    matrix_times_vector(m, n, A, tempB, tempC); //Multiplies A by vector in tempB, stores in tempC

    for(int k = 0; k < m; k++){  //Puts contents of tempC into C in the correct place
      C[i + k * p] = tempC[k];
    }

  }//outer for


}//function
