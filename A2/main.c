#include "dot.h"
#include "matvec.h"
#include "matmat.h"
#include "fillrand.h"
#include "checkres.h"
#include <stdio.h>

int main(){


  int m, n, p;

  printf("Enter m, n, p :");
  scanf("%d%d%d", &m, &n, &p);

  double A[m*n], B[n*p], C[m*p];

  fill_random(m, n, p, A, B);

  matrix_times_matrix(m, n, p, A, B, C);

  check_result(m, n, p, A, B, C);


  /*

  int m, n, p;
  m = 2; n = 3; p = 2;

  double A[m*n], B[n*p], C[m*p];

  for(int i = 0; i < 6; i++){
    A[i] = i;
  }

  for(int i = 0; i < 6; i++){
    B[i] = i;
  }



  matrix_times_matrix(m, n, p, A, B, C);

  printf("Output:\n");

  for(int i = 0; i < 4; i++){
    printf("%lf\n", C[i]);
  }

  */


  return 0;
}
