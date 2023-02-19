#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 100000 

void generateRandonArr();

int main(void)
{
  printf("I'm going to be a vector\n");

  generateRandonArr();

 
  return 0;
}

void generateRandonArr(){
  int my_array[ARRAY_SIZE];

      srand(0);

      int i;
      for (i = 0; i < ARRAY_SIZE; i++) {
          my_array[i] = rand();
          printf("My array: %d\n", my_array[i]);
      }
    
      
}
