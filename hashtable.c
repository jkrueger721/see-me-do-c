#include <stdlib.h>
#include <stdio.h>


const int max = 10;
int size = 0;

int valueArray[max]={NULL};

int hash(int k, int m){

   int h;
   do
   {
      h = k % m;
      h++;
   } while (valueArray[h] != NULL && h <= max);
   return h;

}
void add(int k, int v){
  int index;
  index = hash(k,max);
  valueArray[index] = v;
}

int main(void)
{
  add(34,54);
  add(23,45);
  add(31,456);
  printf("%d \n", hash(5435234, max));
}

