void fill_random (int m , int n , int p , double A[] , double B[]){

  for(int i = 0; i < m*n; i++){
      A[i] = drand48() * 10;
  }

  for(int i = 0; i < n*p; i++){
      B[i] = drand48() * 10;
  }

}
