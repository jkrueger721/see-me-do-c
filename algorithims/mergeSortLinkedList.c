#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int data;
 struct node* next;
} node;

node* sortedMerge(node* a, node* b);
void splitFrontBack(node* source, node** front, node** back);

void push(node** head_ref, int new_data)
{
    /* allocate node */
    node* new_node = (node*)malloc(sizeof(node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

int main(){


  return EXIT_SUCCESS;
}

void splitFrontBack(node* source, node** front, node** back){
  node* fast;
  node* slow;

  slow = source;
  fast = source->next;  

  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      fast = fast->next;
      slow = slow->next;
    }
  }
}

node* sortedMerge(node* a, node* b){
  node* result = NULL;

  if (a == NULL) {
     return (b);
  }else if (b == NULL) {
    return (a);
  }

  if (a->data <= b->data) {
    result = a;
    result->next = sortedMerge(a->next, b );
  }else  {
    result = b;
    result->next = sortedMerge(a, b->next);
  }

  return result;
}

