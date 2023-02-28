#include <stdlib.h>


typedef struct node{
  int data;
  struct node* next;
}node;
int listSize;
struct node *head;

int createSLinkedList(int initalData){
  struct node *newnode, *temp;
  newnode = (struct node*)malloc(sizeof(struct node));
  if (newnode == NULL)
  {
    exit(1);
  }
  
  newnode->data = initalData;
  newnode->next = NULL;
  if(head == NULL){
    head = newnode;
    return 1;
  }
  else {
    temp = head;
    while (temp->next != NULL)
    {
      temp= temp->next;
    }
    temp->next = newnode;
  }

}

int size(){
  return listSize;
}

int main(void)
{
  listSize = NULL;
  head = NULL;
}
