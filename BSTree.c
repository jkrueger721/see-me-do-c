#include <stdlib.h>
#include <stdio.h>

struct BTSnode {
  int data;
  struct BTSnode* right;
  struct BTSnode* left;
};

struct BTSnode* getNewNode(int data){
struct  BTSnode* newNode = (struct BTSnode*)malloc(sizeof(struct BTSnode));
  newNode->data = data;
  newNode->left , newNode->right = NULL;
  
  return newNode;
  
}

int main(void){
  struct BTSnode* rootPtr = NULL;

}