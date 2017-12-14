#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"
extern double getTime();


int main(int argc, char **argv){

  int width, height, max, n;
  filter f;
  char *msg;

  if(*argv[4] == 'A'){
    f = MEAN;
    msg = "mean";
  }else{
    f = MEDIAN;
    msg = "median";
  }

  const char *filterNum = argv[3];

  n = atoi(filterNum);

  RGB *image;

  double time = getTime();



  printf("Reading file %s\n", argv[1]);

  image = readPPM(argv[1], &width, &height, &max);

  time = getTime()-time;

  printf("***   %s read in: %.1e seconds\n", argv[1], time);



  printf("Processing a %d x %d window using %d x %d window and a %s filter\n", width, height, n, n, msg);

  image = denoiseImage(width, height, image, n, f);

  time = getTime()-time;

  printf("***   image processed in: %.1e seconds\n", time);



  printf("Writing file %s\n", argv[2]);

  writePPM(argv[2], width, height, max, image);

  time = getTime()-time;

  printf("***   %s written in: %.1e seconds\n", argv[2], time);



  free(image);
  //free(modified);


  return 0;



}/*MAIN*/
