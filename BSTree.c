#include <stdlib.h>
#include <stdio.h>

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