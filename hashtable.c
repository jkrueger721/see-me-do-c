#include <stdlib.h>
#include <stdio.h>

typedef struct item {
  int key;
  int value;
}item;

typedef struct hashTable_item {
    int flag;
     /*
     * flag = 0 : data does not exist
     * flag = 1 : data exists
     * flag = 2 : data existed at least once
    */
    struct item *data;
}hashTable_item;
struct hashtable_item *array = malloc(sizeof(struct hashTable_item));
int max = 10;
int size = 0;


void hash(k, v){

  int index = k % max;

  struct item* new_item = (struct item*)malloc(sizeof(struct item));
  new_item->key = k;
  new_item->value = v;
      
} 

void init_array()
{
    int i;
    for (i = 0; i < max; i++) 
    {
	array[i].flag = 0;
	array[i].data = NULL;
    }
}

int main(void)
{
  
}

