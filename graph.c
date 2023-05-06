#include <stdio.h>
#include <stdbool.h>
#include <sys/_types/_null.h>

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

void init_graph(graph* g, bool directed){
   int i;

  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i = 1; i <= MAXV; i++) {
    g->degree[i] = 0;
  }

  for (i = 1; i<= MAXV; i++ ) {
    g->edges[i] = NULL;
  }
}
