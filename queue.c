#include "sLinkedList.c"
#include <stdbool.h>


void initQueue();

int main(void)
{
  initQueue();
  return 0;
}
void initQueue(){
  createSLinkedList();
}

void enqueue(int data){
  pushBack(data);
}
void dequeue(){
  popFront();
}

bool empty(){
  return is_empty();
}