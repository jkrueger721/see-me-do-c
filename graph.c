#include <stdio.h>

#define MAXV 100

typedef struct edgenode{
  int y;
  int weight;
  struct edgenode* next;
} edgenode;

typedef struct {
  edgenode* edges[MAXV];
  int nvertices;
  int nedges;
  int directed;
} graph;


