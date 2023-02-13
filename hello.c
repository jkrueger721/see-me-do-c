#include <stdio.h>
#include <math.h>

int main()
{

  long nc;

  while ((nc = getchar()) != EOF)
  {

      nc++;

  }
  printf("%ld\n", nc);
  
}
/// @brief 
/// @param arrSize 
/// @return 
int* randomArray(int arrSize)
{
  int randomIntArray[arrSize];

   srand( (unsigned)time( NULL ) );
   
  for (int i = 0; i < arrSize; i++)
  {
    randomIntArray[i] = rand();
  }
  
  return randomIntArray;

}