#include "array.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

void randinit(Item a[], int N) {
  for (int i = 0; i < N; i++) {
    a[i] = Item_rand();
  }
}

void scaninit(Item a[], int *N) {
  int i;
  for (i = 0; i < *N; i++) {
    if (Item_scan(&a[i]) == EOF) {
      break;
    }
  }
  *N = i;
}

void show(Item a[], int left, int right) {
  for (int i = left; i < right; i++) {
    Item_show(a[i]);
  }
  printf("\n");
}

void sort(Item __attribute__((unused)) a[], int __attribute__((unused)) left,
          __attribute__((unused)) int right) {
  return;
}
