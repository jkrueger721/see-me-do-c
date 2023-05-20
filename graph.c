#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAXV 100

bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];

typedef struct {
  int q[MAXV + 1];
  int first;
  int last;
} queue;

void init_queue(queue* q){
  q->first = 0;
  q->last = MAXV - 1;
}
void enqueue(queue* q, int x){
  if (q->last == MAXV - 1) {
    q->last = 0;
  }else {
    q->last = q->last + 1;
  }
  q->q[q->last] = x;
}
int dequeue(queue* q){
  int x;
  x = q->q[q->first];
  if (q->first == MAXV - 1) {
    q->first = 0;
  }else {
    q->first = q->first + 1;
  }
  return x;
}
bool empty_queue(queue* q){
  if (q->first == q->last + 1) {
    return true;
  }else {
    return false;
  }
}

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

void init_search(graph* g) {
  int i;

  for (i = 0; i <= g->nvertices; i++) {
    processed[i] = false;
    discovered[i] = false;
    parent[i] = -1;
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

void print_graph(graph* g){
  int i;
  edgenode* p;

  for (i = 1; i <= g->nvertices; i++) {
    printf("%d: ", i);
    p = g->edges[i];
    while (p != NULL) {
      printf(" %d", p->y);
      p = p->next;
    }
    printf("\n");
  }
}
void process_edge(int x, int y){
  printf("processed edge (%d, %d)\n", x, y);
}
void process_vertex_late(int v){
  printf("processed vertex %d\n", v);
}
void process_vertex_early(int v){
  printf("processed vertex %d\n", v);
}

void breadth_first_search(graph* g, int start){
  queue q;
  int v;
  int y;
  edgenode* p;

  init_queue(&q);
  enqueue(&q, start);
  discovered[start] = true;

  while (!empty_queue(&q)) {

    v = dequeue(&q);
    processed[v] = true;
    p = g->edges[v];
    while (p != NULL) {
      y = p->y;
      if (!processed[y] || g->directed) {
        process_edge(v, y);
        g->nedges++;
      }
      if (!discovered[y]) {
        enqueue(&q, y);
        discovered[y] = true;
        parent[y] = v;
      }
      p = p->next;
    }
    process_vertex_late(v);
    g->nvertices++;
  }

  
}

int main(){
  graph g;
  init_graph(&g, false);
  insert_edge(&g, 1, 2, false);
  insert_edge(&g, 1, 3, false);
  insert_edge(&g, 1, 4, false);
  insert_edge(&g, 2, 5, false);
  insert_edge(&g, 2, 6, false);
  insert_edge(&g, 3, 7, false);
  insert_edge(&g, 3, 8, false);
  insert_edge(&g, 4, 9, false);
  insert_edge(&g, 4, 10, false);
  insert_edge(&g, 5, 11, false);


  init_search(&g);
  breadth_first_search(&g, 1);

  
}
