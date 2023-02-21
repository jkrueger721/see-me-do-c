#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void myDynamicArr();

int main(void)
{

  
  myDynamicArr();

 
}

void myDynamicArr()
{
  int* ptr;
  int i;
  int size = 16;



  printf("Enter size of elements:");
  scanf("%d", &size);

  ptr = (int*)calloc(size , sizeof(int));


  if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
  else{

    srand(0);

    for ( i = 0; i < size; i++)
    {
      ptr[i] = rand();
    }
    

      printf("The elements of the array are: ");
          for (i = 0; i < size; ++i) {
              printf("%d, ", ptr[i]);
          }
          printf("\n");

     printf("Enter size of elements:");
     scanf("%d", &size);

     int* temp = ptr;

     ptr = realloc(ptr, size * sizeof(int));

     if (!ptr) {
        printf("Memory Re-allocation failed.");
        ptr = temp;
    }
    else {
        srand(0);

        printf("Memory successfully re-allocated using "
               "realloc.\n");
        for ( ; i < size; i++)
        {
          ptr[i] = rand();
        }
    }

     printf("The new elements of the array are: ");
          for (int j = 0 ; j < size; ++j) {
              printf("%d, ", ptr[i]);
          }
          printf("\n");

  }
    
  
}