
#include <stdlib.h>
#include <stdio.h>


int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};


int min = 0;
int max = 24;
int mid = 0;
int search = 3;



int bSearch(int min, int max, int mid, int search){

      

      if (min > max)
      {
        printf("%d not found in list \n", search);
        return -1;
      }
      
      if (primes[mid] > search)
      {
          max = mid - 1;

          mid = min + (max - min)/ 2;  
          bSearch(min,max,mid,search);

      } else if (primes[mid] < search)
      {
        min = mid + 1;
        mid = min + (max - min)/ 2; 

        bSearch(min,max,mid,search);

      }
       else if (primes[mid] == search)
      {
        printf("%d found at index: %d \n", search , mid);
        return primes[mid];
      }
     else if (min == max)
      {
        printf("%d not found in list \n", search);
        return -1;
      }
      return -1;
      
      

}

int main(void)
{
 
  mid = min + (max - min)/ 2; 
  bSearch(min,max,mid,search);
 
}





