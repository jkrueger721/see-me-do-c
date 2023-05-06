#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void insert_edge(graph* g, int x, int y, bool directed){
  edgenode* p;

  p = malloc(sizeof(edgenode));

  p->weight = 0;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p;

  g->degree[x]++;

  if (!directed) {
     insert_edge(g, y, x, true);
  }else {
    g->nedges++;
  }
}

void read_graph(graph* g, bool directed){
  int i, m, x, y;

  init_graph(g, directed);

  scanf("&d %d", &(g->nvertices), &m); 

  for (i = 1; i <= m; i++ ) {
    scanf("%d %d", &x, &y);
    insert_edge(g, x, y, directed);
  }
}

int main(){
  
}
