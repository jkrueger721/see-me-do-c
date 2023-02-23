#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VECTOR_INIT_CAPACITY 6
#define UNDEFINE  -1
#define SUCCESS 0

typedef struct
{
  void** items;
  int size;
  int capacity;
} myVectorList;

typedef struct myVector vector;

struct myVector{
  myVectorList vectorList;

  // function pointers
  int (*ptrVectorSize)(vector *);
  int (*ptrVectorIsEmpty)(vector *);
  int (*ptrVectorCapacity)(vector *);
  int (*ptrVectorAtIndex)(vector *);
  int (*ptrVectorPush)(vector *);
  int (*ptrVectorPrepend)(vector *);
  void (*ptrVectorInsert)(vector *);
  int (*ptrVectorPop)(vector *);
  int (*ptrVectorDelete)(vector *);
  void (*ptrVectorRemoveItem)(vector *);
  int (*ptrVectorFind)(vector *);
  int (*ptrVectorResize)(vector *);


};
// void vector_init(vec) vector vec;

#define VECTOR_INIT(vec) vector vec;\
 vector_init(&vec)

int size(vector* v);
int capacity(vector* v);
int resize(vector* v, int newCapacity);
int push(vector* v, void* item);
int at(vector* v , void* item);
int is_empty(vector* v);
int prepend(vector* v , void* item);

int main(void)
{

  

 
}

void vector_init(vector *v){
  v->ptrVectorSize = size;
  v->ptrVectorCapacity = capacity;
  v->ptrVectorIsEmpty = is_empty;
  v->ptrVectorAtIndex = at;
  v->ptrVectorPush = push;
  v->ptrVectorInsert = insert;
  v->ptrVectorPrepend = prepend;
  // v->ptrVectorPop = pop;
  // v->ptrVectorDelete = delete;
  // v->ptrVectorRemoveItem = vec_remove;
  // v->ptrVectorFind = find;
  v->ptrVectorResize = resize;

  v->vectorList.capacity = VECTOR_INIT_CAPACITY;
  v->vectorList.size = 0;
  v->vectorList.items = malloc(sizeof(void*) * v->vectorList.capacity);
  
}

int size(vector* v){
  return v->vectorList.size;
}

int capacity(vector* v){
  return v->vectorList.capacity;
}

int resize(vector* v, int newCapacity)
{

  int status = UNDEFINE;
  if(v)
  {
    if(v->vectorList.size == v->vectorList.capacity){
      newCapacity = v->vectorList.capacity * 2;
    }else if (v->vectorList.size == v->vectorList.capacity / 4)
    {
      newCapacity = v->vectorList.capacity / 2;
    }
    
      void **items = realloc(v->vectorList.items, sizeof(void*) * newCapacity);
      if (items)
      {
        v->vectorList.items = items;
        v->vectorList.capacity = newCapacity;
        status = SUCCESS;
      }
      
  }
  return status;

}

int push(vector* v, void* item){

  int status = UNDEFINE;

  if(v){
    if(v->vectorList.capacity == v->vectorList.size){
      status = resize(v, v->vectorList.capacity * 2);
      if(status != UNDEFINE){
        v->vectorList.items[v->vectorList.size++] = item;
      }
    }else {

        v->vectorList.items[v->vectorList.size++] = item;
        status = SUCCESS;
    }
  }

  return status;
}

int at(vector* v , void* item){
  int index = UNDEFINE;
  if (v)
  {
     for (int i = 0; i < v->vectorList.size; i++)
     {
       if (item == v->vectorList.items[i])
       {
         index = i;
         return index;
       }
       
     }
     
  }

  return index;
  
}
int is_empty(vector* v){

  int result = 0;
  for (int i = 0; i < v->vectorList.size; i++)
  {
     if(v->vectorList.items[i] == NULL){
      result = 1;
    }
  }
  return result;
}

int prepend(vector* v , void* item){
  int status = UNDEFINE;
  if(v && item){
    
    status = insert(v, item, 0);
    
  }
  return status;
}

int insert(vector* v , void* item, int pos){
  int status = UNDEFINE;
  if(v){
    if (v->vectorList.size == v->vectorList.capacity)
    {
      status = resize(v , v->vectorList.capacity);
    }
    for (int i = v->vectorList.size - 1; i >= pos; i--)
    {
      v->vectorList.items[i + 1] = v->vectorList.items[i];

    }

    v->vectorList.items[pos] = item;
    
    status = SUCCESS;
  }
  return status;
}
