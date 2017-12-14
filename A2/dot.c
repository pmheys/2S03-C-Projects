double dotproduct (int n , double x[] , double y[]){

  double output = 0;

  for(int i = 0; i < n; i++){

    output = output + x[i] * y[i];
  }

  return output;

}
