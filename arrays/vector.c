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
  void (*ptrVectorPush)(vector *);
  void (*ptrVectorPrepend)(vector *);
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




int main(void)
{

  

 
}

void vector_init(vector *v){
  v->ptrVectorSize = size;
  v->ptrVectorCapacity = capacity;
  // v->ptrVectorIsEmpty = is_empty;
  // v->ptrVectorAtIndex = at;
  // v->ptrVectorPush = push;
  // v->ptrVectorInsert = insert;
  // v->ptrVectorPrepend = prepend;
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

int resize(vector* v, int capacity)
{

  int status = UNDEFINE;
  if(v)
  {
      void **items = realloc(v->vectorList.items, sizeof(void*) * capacity);
      if (items)
      {
        v->vectorList.items = items;
        v->vectorList.capacity = capacity;
        status = SUCCESS;
      }
      
  }
  return status;

}

// int is_empty(vector* v){
//   return 0;
// }
  

  