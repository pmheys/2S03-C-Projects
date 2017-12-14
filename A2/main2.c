#include <stdio.h>
#include "dot.h"
#include "matvec.h"
#include "matmat.h"
#include "fillrand.h"
#include "checkres.h"

int main(){

  int flag = 1;
  int m = 1;

  while(flag == 1){

    double A[m*m], B[m*m], C[m*m];

    fill_random(m, m, m, A, B);

    matrix_times_matrix(m, m, m, A, B, C);

    check_result(m, m, m, A, B, C);

    printf("%d\n", m);

    m++;

  }

  return 0;
}
