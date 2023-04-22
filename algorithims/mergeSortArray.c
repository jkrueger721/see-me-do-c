#include <stdio.h>
#define POD
#define T int



void merge_sort(int s[], int low, int high);
void merge(int s[], int low, int middle, int high);


int main(void)
{

}

void merge_sort(int s[], int low, int high){
  int middle;

  if (low < high) {
    middle = (low + high) / 2;
    merge_sort(s, low, middle);
    merge_sort(s, middle, high);

    merge(s, low, middle, high);
  }
}


