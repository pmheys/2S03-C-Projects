#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"



RGB *readPPM (const char *file , int *width , int *height , int *max){

  FILE *input;

  input = fopen(file, "r");

  if(!input){
    fprintf(stderr, "Unable to open file '%s'\n", file);
    exit(1);
  }

  fscanf(input, "P3 %d %d %d\n", width, height, max);

  RGB *data = (RGB*)malloc((*width) * (*height) * sizeof(RGB));

  for(int i = 0; i < (*width) * (*height); i++){
    fscanf(input, "%hhu%hhu%hhu", &data[i].r , &data[i].g, &data[i].b);
  }

  fclose(input);

  return data;


}/*Read PPM */


void writePPM (const char *file, int width, int height,  int max, const RGB *image){

  FILE *output;

  output = fopen(file, "w");

  if (!output) {
    fprintf(stderr, "Unable to open file '%s'\n", file);
    exit(1);
  }

  fprintf(output, "P3\n");

  fprintf(output, "%d %d\n", width, height);

  fprintf(output, "%d\n", max);

  for(int i = 0; i < width * height; i++){
    fprintf(output, "%d %d %d ", image[i].r, image[i].g, image[i].b);
  }

  fclose(output);

}/*WRITE PPM*/


int cmp(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

RGB *denoiseImage (int width, int height, const RGB *image, int n, filter f){

  int size, counter;
  RGB *modified = (RGB*)malloc(width * height * sizeof(RGB));
  int *red = malloc(n*n*sizeof(int));
  int *green = malloc(n*n*sizeof(int));
  int *blue = malloc(n*n*sizeof(int));

  int k = n/2;

    for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){

        int curX = j;
        int curY = i;

        int xWin = k;
        int yWin = k;

        for(int p = 1; p <= k; p++){

          if(j - p >= 0){
            curX = j - p;
            xWin = k + 1;
          }

          if(i - p >= 0){
            curY = i - p;
            yWin = k + 1;
          }
        }//get window

        size = xWin * yWin;

        counter = 0;

        for(int x = 0; x < xWin; x++){
          for(int y = 0; y < yWin; y++){
            red[counter] = image[(curY + y) * width + (curX + x)].r;
            green[counter] = image[(curY + y) * width + (curX + x)].g;
            blue[counter] = image[(curY + y) * width + (curX + x)].b;
            counter++;
          }
        }

        if(f == MEAN){

          int sumR = 0;
          int sumG = 0;
          int sumB = 0;

          for(int q = 0; q < size; q++){
            sumR += red[q];
            sumG += green[q];
            sumB += blue[q];
          }//for

          modified[i * width + j].r = sumR/counter;
          modified[i * width + j].g = sumG/counter;
          modified[i * width + j].b = sumB/counter;



        }else{

          qsort(red, size, sizeof(int), cmp);
          qsort(green, size, sizeof(int), cmp);
          qsort(blue, size, sizeof(int), cmp);

          if (size%2 == 0){
            modified[i * width + j].r = (red[size/2] + red[size/2-1])/2;
            modified[i * width + j].g = (green[n/2] + green[n/2-1])/2;
            modified[i * width + j].b = (blue[n/2] + blue[n/2-1])/2;
          } else {
            modified[i * width + j].r = red[size/2];
            modified[i * width + j].g = green[size/2];
            modified[i * width + j].b = blue[size/2];
          }

        }//else

      }//secondloop
    }//firstloop

    return modified;



}//DENOISEIMAGE
