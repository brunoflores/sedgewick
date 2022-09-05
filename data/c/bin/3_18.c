#include <stdio.h>
#include <stdlib.h>

#define V 8

int main(void) {
  int i;
  int j;
  int __attribute__((unused)) adj[V][V];

  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      adj[i][j] = 0; // All vertices are disconnected.
    }
  }

  for (i = 0; i < V; i++) {
    adj[i][i] = 1; // Each vertex is connected to itself.
  }

  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[i][j] = 1;
    adj[j][i] = 1;
  }
}
