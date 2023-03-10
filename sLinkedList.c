#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "sLinkedList.h"



typedef struct Node{
  int data;
  struct Node* next;
}Node;

int listSize = 0;
struct Node *head;
struct Node *tail;


void createSLinkedList() {

  head = malloc(sizeof(*head));
  assert(head != NULL);
  tail = malloc(sizeof(*tail));
  assert(tail != NULL);

  listSize = 1;
  
  head->next = tail;
  tail->next = tail;
  
}

int size(){
  return listSize;
}
bool is_empty(){
  if (head->next == tail)
  {
    return true;
  }
  return false;
}

int value_at(int index){
  assert(index <= listSize);

  struct Node *current = head;
  int count = 1;

  while (current != NULL)
  {
    if(count == index){
      return current->data;
    }
    count++;
    current = current->next;
    assert(count <= listSize);
    
  }
  
}

void pushFront(int newData){
   
  struct Node *newnode;
  newnode = malloc(sizeof(*newnode));
  assert(newnode != NULL);
  newnode->data = newData;
  if (head->next == tail)
  {
    tail->next = newnode;
  }
  
  newnode->next = head->next;

  head->next = newnode;
  listSize++;
}
int popFront(){

  assert(!is_empty());

  int value = head->next->data;
  struct Node *temp = head->next->next;

  free(head->next);

  if(temp != NULL){

  head->next = temp;

  }
  listSize--;
  return value;

}

void pushBack(int newData){
  struct Node *current = head;
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
  assert(temp != NULL);
  
  while (current->next != NULL)
  {
    current = current->next;
  }

  temp->data = newData;
  current->next = temp;
  listSize++;
  
}
int popBack(){

  struct Node *temp;
  struct Node* current = head;
  temp = tail->next;
  int value = temp->data;
  while (current != temp)
  {
     tail->next = current->next;
  }
  
 

  free(temp);
  return value;
}

int front(){
  return head->next->data;
}

int back(){
  return tail->next->data;
}

void insert(int index, int data){
  assert(index <= listSize);

  struct Node *current = head;
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
  assert(newNode != NULL);
  int count = 1;

  while (current != tail)
  {
    if(count == index){
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
        return;
    }
    current = current->next;
    count++;
  }
}


void erase(int index){
  assert(index <= listSize);
  struct Node *current = head;
  struct Node *prev;

  int count = 1;

  while (current != tail)
  {
    if(count == index ){
        prev->next = current->next;
        free(current);
        listSize--;
        return;
    }
    prev = current;
    current = current->next;
    count++;
  }
}
void reverse(){
 struct Node* temp;
 struct Node* current = head;
 struct Node* rev = NULL;

 while (current != NULL)
 {
   temp = current->next;
   current->next = rev;
   rev = current;
   current = temp;
 }
 

}