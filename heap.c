#include "stdio.h"

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

void heapify(int arr[], int n, int i){
  int max = i; 
  int l = 2 * i + 1;
  int r = 2 * i + 2;

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


int main(void){
  
}






