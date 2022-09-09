#include "item.h"
#include "queue_adt.h"
#include <stdlib.h>

typedef struct Queue_node *link;

struct Queue_node {
  Item item;
  link next;
};

struct queue {
  link head;
  link tail;
};

link new (Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

Q Queue_init(int __attribute__((unused)) maxN) {
  Q q = malloc(sizeof *q);
  q->head = NULL;
  return q;
}

int Queue_empty(Q q) { return q->head == NULL; }

void Queue_put(Q q, Item item) {
  if (q->head == NULL) {
    // Queue is empty:
    q->tail = new (item, q->head);
    q->head = q->tail;
    return;
  }
  // Queue is not empty:
  q->tail->next = new (item, q->tail->next);
  q->tail = q->tail->next;
}

Item Queue_get(Q q) {
  Item item = q->head->item;
  link t = q->head->next;
  free(q->head);
  q->head = t;
  return item;
}
