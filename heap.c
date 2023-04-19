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

int getSize(){
  return size;
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
     size++;

    int i = *index - 1;
  while(i != 0 && arr[parent(i)] < arr[i]){
    swap(&arr[parent(i)], &arr[i]);
    i = parent(i);
  }

}

int extractMax(int arr[], int *n){
   int max_item = arr[0];

    arr[0] = arr[*n - 1];
    *n = *n - 1;

    heapify(arr, 0, *n);
    return max_item;
}

void heapSort(int arr[], int n){
  buildHeap(arr, n);

  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);

    heapify(arr, i, 0);
  }
}
void printArray(int arr[]){
  for (int i = 0; i < size - 1;i++) {
    printf("%d\n", arr[i]);
  }
}

int main(void){
  
  int nArr = { 15 , 55, 1 , 4 , 99, 16 };
  size = 6;
  heapSort(nArr, size);

  printArray(nArr);

}






