#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "assignment3.h"

void generateRandomIntArray(int N, int *A, int NMAX){

  srand(time(NULL));
  int i;

  for(i = 0; i < N; i++){
    *(A+i) = rand() % NMAX;
  }

}//generateRandomIntArray

void printArray (int n, int *A){

  int i;

  for(i = 0; i < n; i++){
    printf("%d ", *(A+i));
  }

}//printArray

void printBSTinorder(TreeNodePtr root){

  if(root == NULL){
    return;
  }

  printBSTinorder(root -> left);
  printf("%d ", root -> key);
  printBSTinorder(root -> right);

}//printBSTinorder

void printList(ListNodePtr head){

  printf("%d ", head -> key);

  if(head -> next != NULL){
    printList(head -> next);
  }

}//printList
