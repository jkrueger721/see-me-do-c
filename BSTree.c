#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int MAX(int a, int b) { return a > b ? a : b; }
int nodeCount = 0;

typedef struct BSTnode {
  int data;
  struct BSTnode* right;
  struct BSTnode* left;
} BSTnode;

 BSTnode* getNewNode(int data){
  BSTnode* newNode = ( BSTnode*)malloc(sizeof( BSTnode));
  newNode->data = data;
  newNode->left , newNode->right = NULL;
  
  nodeCount++;

  return newNode;
  
}

int getMin(BSTnode* root){
  if(root->left == NULL){
    printf("Error: tree is empty \n");
    return -1;
  }
  while(root->left != NULL){
    root = root->left;
  }
  return root->data;
}

int getMax(BSTnode* root){
  if(root->right == NULL){
    printf("Error: tree is empty \n");
    return -1;
  }
  while(root->right != NULL){
    root = root->right;
  }
  return root->data;
}
int findHeight(BSTnode* root){
  if(root == NULL){
    return -1;
  }
  return MAX(findHeight(root->left), findHeight(root->right)) + 1;
}

int getNodeCount(){
  return nodeCount;
}

bool search(BSTnode* root, int data){
  if(root == NULL) return false;
  else if(root->data == data) return true;
  else if(data <= root->data) return search(root->left, data);
  else return search(root->right, data);
}

BSTnode* insert(BSTnode* root, int data){
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
   BSTnode* rootPtr = NULL;

}
