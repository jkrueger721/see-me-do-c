#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAXV 100
#define TREE 0
#define BACK 1
#define FORWARD 2
#define CROSS 3

bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];
int reachable_ancestor[MAXV + 1];
int tree_out_degree[MAXV + 1];

bool finished = false;
int time;
int entry_time[MAXV + 1];
int exit_time[MAXV + 1];
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

int edge_classification(int x, int y){
  if (parent[y] == x) {
    return(TREE);
  }
  if (discovered[y] && !processed[y]) {
    return(BACK);
  }
  if (processed[y] && (entry_time[y] > entry_time[x])) {
    return(FORWARD);
  }
  if (processed[y] && (entry_time[y] < entry_time[x])) {
    return(CROSS);
  }
  printf("Warning: self loop (%d, %d)\n", x, y);
}

void process_edge(int x, int y){
  int class;
  
  class = edge_classification(x, y);

  if (class == TREE) {
    tree_out_degree[x] = tree_out_degree[x] + 1;
  }
  if ((class == BACK) && (parent[x] != y)) {
    if (entry_time[y] < entry_time[reachable_ancestor[x]]) {
      reachable_ancestor[x] = y;
    }
  }
  printf("processed edge (%d, %d)\n", x, y);
}
void process_vertex_late(int v){
  bool root;
  int time_v;
  int time_parent;

  if (parent[v] < 1) {
    if (tree_out_degree[v] > 1) {
      printf("root articulation vertex: %d\n", v);
    }
    return;
  }

  root = (parent[parent[v]] < 1);

  if(!root) {
    if (reachable_ancestor[v] == parent[v]) {
      printf("parent articulation vertex: %d\n", parent[v]);
    }

    if (reachable_ancestor[v] == v) {
      printf("bridge articulation vertex: %d\n", parent[v]);

      if (tree_out_degree[v] > 0) {
        printf("bridge articulation vertex: %d\n", v);
      }
    }
  }

  time_v = entry_time[reachable_ancestor[v]];
  time_parent = entry_time[reachable_ancestor[parent[v]]];

  if(time_v < time_parent) {
    reachable_ancestor[parent[v]] = reachable_ancestor[v];
  }
  
  printf("processed vertex %d\n", v);
}
void process_vertex_early(int v){
  reachable_ancestor[v] = v;
  printf("processed vertex %d\n", v);
}
void depth_first_search(graph* g, int v){
  edgenode* p;
  int y;
  

  if (finished) {
    return;
  }

  discovered[v] = true;
  time = time + 1;
  entry_time[v] = time;

  process_vertex_early(v);

  p = g->edges[v];
  while (p != NULL) {
    y = p->y;
    if (!discovered[y]) {
      parent[y] = v;
      process_edge(v, y);
      depth_first_search(g, y);
    }else if ((!processed[y]) || (g->directed)) {
      process_edge(v, y);
    }
    if (finished) {
      return;
    }
    p = p->next;
  }
  process_vertex_late(v);
  time = time + 1;
  exit_time[v] = time;

  processed[v] = true;
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

void find_path(int start, int end, int parents[]){
  if ((start == end) || (end == -1)) {
    printf("\n%d", start);
  }else {
    find_path(start, parents[end], parents);
    printf(" %d", end);
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
