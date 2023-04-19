#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int data;
 struct node* next;
} node;

struct node* sortedMerge(node* a, node* b);
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
