#include <stdio.h>
#include <stdlib.h>

#define V 10

typedef struct node *link;

struct node {
  int v;
  link next;
};

link new (int v, link next) {
  link x = malloc(sizeof *x);
  x->v = v;
  x->next = next;
  return x;
}

int main(void) {
  int i;
  int j;
  link adj[V];

  for (i = 0; i < V; i++) {
    adj[i] = NULL;
  }

  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[j] = new (i, adj[j]);
    adj[i] = new (j, adj[i]);
  }
}
