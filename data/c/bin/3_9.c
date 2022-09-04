#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  int item;
  link next;
};

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  link t = malloc(sizeof *t);
  link x = t;

  t->item = 1;
  t->next = t;

  for (i = 2; i <= N; i++) {
    x = (x->next = malloc(sizeof *x));
    x->item = i;
    x->next = t;
  }

  while (x != x->next) {
    for (i = 1; i < M; i++) {
      x = x->next;
    }
    {
      link tmp = x->next;
      x->next = x->next->next;
      free(tmp);
    };
    N--;
  }

  printf("%d\n", x->item);
  free(x);
}
