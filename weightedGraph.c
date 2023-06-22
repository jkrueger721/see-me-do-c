#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXV 100
#define MAXINT 1000
int parent[MAXV + 1];

typedef struct {
  int y;
  int weight;
  struct edgenode* next;
} edgenode;

typedef struct {
  edgenode* edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;
} graph;

init_graph(graph *g){
  int i;

  g->nvertices = 0;
  g->nedges = 0;
  g->directed = false;

  for (i = 1; i <= MAXV; i++) {
    g->degree[i] = 0;
  }

  for (i = 1; i <= MAXV; i++) {
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

  if (directed == false) {
    insert_edge(g, y, x, true);
  } else {
    g->nedges++;
  }
}

void insert_vertex(graph* g){
  if (g->nvertices == MAXV) {
    printf("Graph has too many vertices\n");
  } else {
    g->nvertices++;
  }
}

// print_graph(graph *g){
//   int i;
//   edgenode* p;

//   for (i = 1; i <= g->nvertices; i++) {
//     printf("%d: ", i);
//     p = g->edges[i];

//     while(p != NULL) {
//       printf(" %d", p->y);
//       p = p->next;
//     }
//     printf("\n");
//   }
// }

int prim(graph *g, int start){
  int i; // counter
  edgenode* p; // temporary pointer
  bool intree[MAXV + 1]; // is the vertex in the tree yet?
  int distance[MAXV + 1]; // cost of adding to tree
  int v; // current vertex to process
  int w; // candidate next vertex
  int dist; // best current distance from start
  int weight = 0; // edge weight

  for (i = 1; i <= g->nvertices; i++) {
    intree[i] = false;
    distance[i] = MAXINT;
    parent[i] = -1;
  }

  distance[start] = 0;
  v = start;

  while(!intree[v]) {
    intree[v] = true;
    if(v != start) {
      printf("%d %d\n", parent[v], v);
      weight += distance[v];
    }
    p = g->edges[v];

    while(p != NULL) {
      w = p->y;
      weight = p->weight;

      if ((distance[w] > weight) && !intree[w]) {
        distance[w] = weight;
        parent[w] = v;
      }

      p = p->next;
    }

    dist = MAXINT;

    for (i = 1; i <= g->nvertices; i++) {
      if ((!intree[i]) && (dist > distance[i])) {
        dist = distance[i];
        v = i;
      }
    }
  }
  return weight;

}


int main(void)
{
  graph *g = malloc(sizeof(graph));
  init_graph(g);
  insert_edge(g, 1, 2, false);
  insert_edge(g, 1, 3, false);
  insert_edge(g, 1, 4, false);
  insert_edge(g, 2, 3, false);
  insert_edge(g, 2, 4, false);
  insert_edge(g, 3, 4, false);
  print_graph(g);

  printf("%d\n", prim(g, 1));

  
}




