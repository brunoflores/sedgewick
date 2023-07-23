#include "Lib.h"
#include "Point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  point p;
  link next;
};

link **grid;
int G;
float d;
int cnt = 0;

void gridinsert(float x, float y) {
  int i;
  int j;
  link s;
  int X = (x * G) + 1;
  int Y = (y * G) + 1;
  link t = malloc(sizeof *t);
  t->p.x = x;
  t->p.y = y;
  for (i = X - 1; i <= X + 1; i++) {
    for (j = Y - 1; j <= Y + 1; j++) {
      for (s = grid[i][j]; s != NULL; s = s->next) {
        if (distance(s->p, t->p) < d) {
          cnt++;
        }
      }
    }
  }
  t->next = grid[X][Y];
  grid[X][Y] = t;
}

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int j;
  int N = atoi(argv[1]);
  float d = atof(argv[2]);
  G = 1 / d;
  grid = (link **)malloc2d(G + 2, G + 2, (sizeof(link)));

  for (i = 0; i < G + 2; i++) {
    for (j = 0; j < G + 2; j++) {
      grid[i][j] = NULL;
    }
  }

  for (i = 0; i < N; i++) {
    gridinsert(randFloat(), randFloat());
  }

  free(grid);

  printf("%d edges shorter than %f\n", cnt, d);
}
