#include <stdint.h>
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

void deleteTree(BSTnode* root){
  if (root == NULL) {
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);

  free(root);
}

BSTnode* getMin(BSTnode* root){
  if(root->left == NULL){
    printf("Error: tree is empty \n");
    return NULL;
  }
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

void printTreeElementsInOrder(BSTnode* root){
  
  if (root == NULL) {
    return;
  }
  printTreeElementsInOrder(root->left);

  printf("%d \n", root->data);

  printTreeElementsInOrder(root->right);
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
    return root;
  }
  else if(data <= root->data ){
    root->left = insert(root->left, data);
  }
  else {
    root->right = insert(root->right, data);
  }
  return root;
}

bool isBinaySearchTree(BSTnode* root){
  if(root == NULL){
    return true;
  }
  if (root->left != NULL && getMax(root) > root->data) {
    return false;
  }
  if (root->right != NULL && getMin(root) < root->data) {
    return false;
  }
  if (!isBinaySearchTree(root->left) || !isBinaySearchTree(root->right)) {
     return false;
  }
  return true;
}
BSTnode* deleteNode(BSTnode* root, int data){
    if (root == NULL) {
      return root;
    }
    else if (data <= root->data) {
      root->left =  deleteNode(root->left,  data);
    }else if (data >= root->data) {
      root->right = deleteNode(root->right, data);
    }else{
      if (root->left == NULL && root->right == NULL) {
        free(root);
        root = NULL;
      
      }
    else if (root->left == NULL) {
      BSTnode* temp = root;
      root = root->right;
      free(temp);
      
    }
    else if (root->right == NULL) {
      BSTnode* temp = root;
      root = root->left;
      free(temp);
      
    }
    else{
      BSTnode* temp = getMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right,temp->data );
    }
    return root;    
  }
}

BSTnode* getSuccessor(BSTnode* root , int data){
  BSTnode* current = search(root, data);
  if(current == NULL) return current;

  if (root->left != NULL) {
      BSTnode* temp = getMin(root->right);
      return temp;
  }else {
    BSTnode* successor = NULL;
    BSTnode* ancestor = root;
    while (ancestor != current) {
      if (current->data < ancestor->data) {
        successor = ancestor;
        ancestor = ancestor->left;
      }
      else {
        ancestor = ancestor->right;
      }
    }
    return successor;
  }
}

int main(void){
  BSTnode* rootPtr = NULL;


  rootPtr = insert(rootPtr, 35);  
  rootPtr = insert(rootPtr, 97);  
  rootPtr = insert(rootPtr, 12);  
  rootPtr = insert(rootPtr, 17); 
  rootPtr = insert(rootPtr, 109);

  printf("is %d in tree? : %d \n", 109, search(rootPtr, 1));

   printf("hello \n");

   printf("Is binary earch tree %d \n", isBinaySearchTree(rootPtr));

   printTreeElementsInOrder(rootPtr);



}
