#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct BTSnode {
  int data;
  struct BTSnode* right;
  struct BTSnode* left;
} BTSnode;

 BTSnode* getNewNode(int data){
  BTSnode* newNode = ( BTSnode*)malloc(sizeof( BTSnode));
  newNode->data = data;
  newNode->left , newNode->right = NULL;
  
  return newNode;
  
}

bool search(BTSnode* root, int data){
  if(root == NULL) return false;
  else if(root->data == data) return true;
  else if(data <= root->data) return search(root->left, data);
  else return search(root->right, data);
}

BTSnode* insert(BTSnode* root, int data){
  if(root == NULL){
    root = getNewNode( data);
  }
  else if(data <= root->data ){
    root->left = insert(root->left, data);
  }
  else {
    root->right = insert(root->right, data);
  }
  return root;
}
int main(void){
   BTSnode* rootPtr = NULL;

}