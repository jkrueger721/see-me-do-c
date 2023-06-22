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

int prim(graph* g, int start){
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


int main(int argc, char const *argv[])
{
  
  
  return 0;
}




