#include <stdio.h>




void merge_sort(int s[], int low, int high);
void merge(int s[], int low, int middle, int high);
void print_array(int a[], int size);


int main(void)
{
  
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    print_array(arr, arr_size);
 
    merge_sort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    print_array(arr, arr_size);
}

void merge(int s[], int low , int middle, int high){
  int i, j, k;
  int n1 = middle - low + 1;
  int n2 = high - middle;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = s[low + i];
  for (j = 0; j < n2; j++)
    R[j] = s[middle + 1 + j];

  i = 0;
  j = 0;
  k = low;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      s[k] = L[i];
      i++;
    } else {
      s[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    s[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    s[k] = R[j];
    j++;
    k++;
  }

}

void merge_sort(int s[], int low, int high){
  int middle;

  if (low < high) {
    middle = (low + high) / 2;
    merge_sort(s, low, middle);
    merge_sort(s, middle + 1, high);

    merge(s, low, middle, high);
  }
}

void print_array(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

