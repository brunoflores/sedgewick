#include <List.h>
#include <stdio.h>
#include <stdlib.h>

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);
  Node t;
  Node x;

  initNodes(N);

  for (i = 2, x = newNode(1); i <= N; i++) {
    t = newNode(i);
    insertNext(x, t);
    x = t;
  }

  while (x != Next(x)) {
    for (i = 1; i < M; i++) {
      x = Next(x);
    }
    freeNode(deleteNext(x));
  }

  printf("%d\n", Item(x));

  freeNodes();
}
