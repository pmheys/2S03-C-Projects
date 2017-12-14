#include <stdlib.h>
#include <stdio.h>
#include "assignment3.h"

ListNodePtr reverseList (ListNodePtr head){

  ListNodePtr current = head;
  ListNodePtr previous = NULL;
  ListNodePtr next = NULL;

  while(current != NULL){
    next = current -> next;
    current -> next = previous;
    previous = current;
    current = next;
  }

  return previous;

}//reverseList


void deallocateList(ListNodePtr head){

  if(head != NULL){
    deallocateList(head -> next);
  }
  free(head);
}//deallocateList
