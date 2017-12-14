#include <stdlib.h>
#include <stdio.h>
#include "assignment3.h"

TreeNodePtr createBSTnode(int key) {

  TreeNodePtr p = malloc(sizeof(struct TreeNode));
  if(p){
    p -> key = key;
    p -> left = NULL;
    p -> right = NULL;

  }//if
  return p;

}//createBSTnode


TreeNodePtr insertNodeIntoBST(TreeNodePtr root, const TreeNodePtr z){

  if(root == NULL){
    return z;
  }

  if(z -> key <= root -> key){
    root -> left = insertNodeIntoBST(root -> left, z);
    return root;
  }else{
    root -> right = insertNodeIntoBST(root -> right, z);
    return root;
  }

  /*return root;*/

}//function

TreeNodePtr insertArrayIntoBST(int n , int *A) {

  TreeNodePtr root = createBSTnode(*A);

  int i;
  TreeNodePtr current;

  for(i = 1; i < n; i++){

    current = createBSTnode(*(A+i));
    root = insertNodeIntoBST(root, current);

  }//for

  return root;

}//insertArrayIntoBST

void deallocateBST(TreeNodePtr root){

  if(root == NULL){
    return;
  }else{
    deallocateBST(root -> left);
    deallocateBST(root -> right);
  }

  free(root);

}//deallocateBST

ListNodePtr convertBSTtoLinkedList(TreeNodePtr root){
  if(root == NULL){
    return NULL;
  }

  /*ListNodePtr current, leftTree, rightTree, last; */
  ListNodePtr current = malloc(sizeof(struct ListNode));
  ListNodePtr leftTree;/* = malloc(sizeof(struct ListNode));*/
  ListNodePtr last;


  leftTree = convertBSTtoLinkedList(root -> left);
  current -> key = root -> key;
  current -> next = convertBSTtoLinkedList(root -> right);

  if(leftTree == NULL){
    return current;
  }else{
    last = leftTree;
    while(last -> next != NULL){
      last = last -> next;
    }
    last -> next = current;
    return leftTree;
  }
}//convertBSTtoLinkedList
