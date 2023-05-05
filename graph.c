#include <stdio.h>
#include <stdbool.h>

#define MAXV 100

typedef struct edgenode{
  int y;
  int weight;
  struct edgenode* next;
} edgenode;

typedef struct {
  edgenode* edges[MAXV];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;
} graph;


