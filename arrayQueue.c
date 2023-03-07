#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10

int arrQueue[MAXSIZE];
int read = 0;
int write = 0;
int size = 0;
bool isEmpty(){
  return read == write ? true : false;
}

int main(void)
{
  printf("Is queue empty: %d \n", isEmpty());
}

void updateWrite(){

  if (write < 9)
  {
    write++;
  }else{
    write = 0;
  }
  
}

void updateRead(){

  if (read < 9)
  {
    read++;
  }else{
    read = 0;
  }
  
}

void enQueue(int data){

  arrQueue[write] = data;
  updateWrite();
  size++;
}

int deQueue(){
  int value = arrQueue[read];

  arrQueue[read] = NULL;
  updateRead();
  size--;
  return value;
}
