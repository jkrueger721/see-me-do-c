#include <stdio.h>
#include <stdlib.h>
# define SIZE 220

void quick_sort(int s[], int low, int high);
int partition(int s[], int low, int high);
void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void printArray(int *array, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}
void generateRandomArray(int *array, int size){
  for(int i = 0; i < size; i++){
    array[i] = rand() % 100;
  }
}
int main(void)
{
  int array[SIZE];
  generateRandomArray(array, SIZE);

  quick_sort(array, 0, SIZE - 1);

  printArray(array, SIZE);

  return 0;
}

void quick_sort(int s[], int low, int high){
  int p;

  if( low < high){
    p = partition(s, low, high);
    quick_sort(s, low, p - 1);
    quick_sort(s, p + 1, high);
  }
}
int partition(int s[], int low, int high)
{
  int i, p, firstHigh;

  p = high;
  firstHigh = low;
  for (i = low; i < high; i++)
  {
    if (s[i] < s[p])
    {
      swap(&s[i], &s[firstHigh]);
      firstHigh++;
    }
  }
  swap(&s[p], &s[firstHigh]); // put pivot in place

  return firstHigh; 
}