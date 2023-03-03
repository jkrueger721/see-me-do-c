#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>



typedef struct Node{
  int data;
  struct Node* next;
}Node;
int listSize = 0;
struct Node *head;
// struct Node *tail;


void createSLinkedList(){

  head = (struct Node*)malloc(sizeof(struct Node));
  if (head == NULL)
  {
    assert(0);
  }
  listSize = 1;
  
  head->data = listSize;
  head->next = NULL;
 
  
 
  
}

int size();
bool is_empty();
int value_at(int index);
void pushFront(int newData);
int popFront();
void pushBack(int newData);
int popBack();
int front();
int back();
void insert(int index, int data);
void printList();
void erase(int index);

int main(void)
{
  createSLinkedList();
  srand(0);
  for (int i = 0; i < 10; i++)
  {
    pushFront(rand());
  }

  pushBack(10);
  pushBack(10);
  pushBack(10);
  pushBack(10);
  pushBack(10);

  pushBack(10);
  pushBack(10);
  pushBack(11);


  insert(6, 56);
  // erase(15);
  printList();
  printf("size of list is: %d\n", size());
  printf("value at index 12: %d\n", value_at(12));

  printf("front value is %d\n", front());
  
  printf("pop front value is %d\n", popFront());
  printf(" back value is %d\n", back());

  printf("pop back value is %d\n", popBack());

}

int size(){
  return listSize;
}
bool is_empty(){
  if (head == NULL || listSize == 0)
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
  newnode = (struct Node*)malloc(sizeof(struct Node));
  if (newnode == NULL)
  {
    assert(0);
  }
  newnode->data = newData;

  newnode->next = head->next;

  head->next = newnode;
  listSize++;
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
  struct Node* current = head;
  struct Node *prev;
   while (current->next != NULL)
  {
    
    current = current->next;
  }
  int value = current->data;
  free(current);
  return value;
}

int front(){
  return value_at(2);
}

int back(){
  return value_at(listSize);
}

void insert(int index, int data){
  assert(index <= listSize);

  struct Node *current = head;
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
  assert(newNode != NULL);
  int count = 1;

  while (current != NULL)
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

void printList(){
  struct Node* temp = head;
  printf("The elements of the list are: ");
  for (; temp != NULL; temp=temp->next)
  {
    printf("%d ", temp->data);
  }
  printf("\n");
}

void erase(int index){
  assert(index <= listSize);
  struct Node *current = head;
  struct Node *prev;

  int count = 1;

  while (current != NULL)
  {
    if(count == index){
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