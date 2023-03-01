#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>



typedef struct Node{
  int data;
  struct Node* next;
}Node;
int listSize;
struct Node *head;

void createSLinkedList(int initalData){
  struct Node *newnode, *temp;
  newnode = (struct Node*)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    assert(0);
  }
  
  newnode->data = initalData;
  newnode->next = NULL;
  if(head == NULL){
    head = newnode;
    
  }
  else {
    // temp = head;
    // while (temp->next != NULL)
    // {
    //   temp= temp->next;
    // }
    // temp->next = newnode;
    assert(0);
  }
}

int size();
bool is_empty();
int value_at(int index);
void pushFront(int newData);
int popFront();

int main(void)
{
  createSLinkedList(6);
  listSize = 0;
  pushFront(5);
  pushFront(4);
  printf("pop value is %d\n", popFront());
}

int size(){
  return listSize;
}
bool is_empty(){
  if (head == NULL)
  {
    return true;
  }
  return false;
}

int value_at(int index){
  struct Node *current = head;
  int count = 0;

  while (current != NULL)
  {
    if(count == index){
      return current->data;
    }
    count++;
    current = current->next;

  }
  
  assert(0);
}

void pushFront(int newData){
   
   struct Node *newnode, *temp;
  newnode = (struct Node*)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    assert(0);
  }
  newnode->data = newData;

  newnode->next = head->next;

  head->next = newnode;
}
int popFront(){
  if (is_empty())
  {
    assert(0);
  }

  int value = head->next->data;
  struct Node *temp = head->next->next;

  free(head->next);

  if(temp != NULL){

  head->next = temp;

  }
  
  return value;

}