#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


const int max = 10;
int size = 0;

int valueArray[max]={NULL};

int hash(int k){

   return k % max;

}

int rehash(int key)
{
 int i;

 i = (key+1) % max;

 return i;
}
void add(int k, int v){
  int index;
  index = hash(k);
  while (valueArray[index] != NULL)
  {
    index = rehash(index);
  }
  
  valueArray[index] = v;
}

bool exits(int key){
     key = hash(key);

  for (int i = 0; i < max; i++)
  {
   int compare = valueArray[i];
    if (compare == key)
    {
      return true;
    }
        
  }
  return false;
  
}
int get(int key){
  int value;
  int index = hash(key);
  if (valueArray[index] != NULL)
  {
    value = valueArray[index];
    return value;
  }
  
  return -1;
}


void removek(int key){
  int h = hash(key);
  valueArray[h] = NULL;
}

int main(void)
{
  add(3,54);
  add(4,45);
  add(2,456);
  add(12,457);

  removek(12);


  for (int i = 0; i < max; i++)
  {
    printf("%d , %d \n", i , valueArray[i]);
  }
  
}

