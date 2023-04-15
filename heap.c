#include "stdio.h"

#define MAX_SIZE 15
int size = 0;
/*
parent (x -1) /2
left child 2 * x + 1
right child 2 * x + 2
*/

void swap(int* a , int* b ){
  int temp = *b;
  *b = *a;
  *a = temp;
}

int parent(int n){
  return (n - 1) / 2;
}
int leftChild(int n) {
    return 2 * n + 1;
}
int rightChild(int n) {
    return 2 * n + 2;
}
void heapify(int arr[], int n, int i){
  int max = i; 
  int l = leftChild(i);
  int r = rightChild(i);

  if (l < n && arr[l] > arr[max]) {
     max = l;
  }

  if (r < n  && arr[r] > arr[max]) {
     max = r;
  }
  if (max != i) {
    swap(&arr[i], &arr[max]);
  }
  heapify(arr, n, max);
}

void buildHeap(int arr[], int n ){
  int lastNonLeafNode = (n / 2) - 1;
  
  for (int i = 0; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

void insert(int arr[],int n, int *index){
    
   if (*index >= MAX_SIZE) {
    printf("Heap if fulle");
    return;
   }  
   arr[*index] = n;
    *index++;

    int i = *index - 1;
  while(i != 0 && arr[parent(i)] < arr[i]){
    swap(&arr[parent(i)], &arr[i]);
    i = parent(i);
  }

}

int main(void){
  
}






