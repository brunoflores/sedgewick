#include "fifo.h"
#include "item.h"
#include <stdlib.h>

static Item *q;
static int N;
static int head;
static int tail;

void queue_init(int maxN) {
  q = malloc((maxN + 1) * sizeof(Item));
  N = maxN + 1;
  head = N;
  tail = 0;
}

int queue_empty(void) { return head % N == tail; }

void queue_put(Item item) {
  q[tail++] = item;
  tail = tail % N;
}

Item queue_get(void) {
  head = head % N;
  return q[head++];
}
