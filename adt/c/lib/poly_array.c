#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

struct poly {
  int N;
  int *a;
};

Poly Poly_term(int coeff, int exp) {
  int i;
  Poly t = malloc(sizeof *t);
  t->a = malloc((exp + 1) * sizeof(int));
  t->N = exp + 1;
  t->a[exp] = coeff;
  for (i = 0; i < exp; i++) {
    t->a[i] = 0;
  }
  return t;
}

Poly Poly_add(Poly p, Poly q) {
  int i;
  Poly t;
  if (p->N < q->N) {
    t = p;
    p = q;
    q = t;
  }
  for (i = 0; i < q->N; i++) {
    p->a[i] += q->a[i];
  }
  return p;
}

Poly Poly_mult(Poly p, Poly q) {
  int i;
  int j;
  Poly t = Poly_term(0, (p->N - 1) + (q->N - 1));
  for (i = 0; i < p->N; i++) {
    for (j = 0; j < q->N; j++) {
      t->a[i + j] += p->a[i] * q->a[j];
    }
  }
  return t;
}

float Poly_eval(Poly p, float x) {
  int i;
  double t = 0.0;
  for (i = p->N - 1; i >= 0; i--) {
    t = t * x + p->a[i];
  }
  return t;
}

char *Poly_show(Poly p) {
  int buff_len = 10 * sizeof(char);
  char *buff = malloc(buff_len);
  snprintf(buff, buff_len, "%d %d", p->N, *p->a);
  return buff;
}
