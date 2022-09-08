#include "fifo.h"
#include "item.h"
#include <stdlib.h>

typedef struct queue_node *link;

struct queue_node {
  Item item;
  link next;
};

static link head;
static link tail;

link new (Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

void queue_init(int __attribute__((unused)) maxN) { head = NULL; }

int queue_empty(void) { return head == NULL; }

void queue_put(Item item) {
  if (head == NULL) {
    head = (tail = new (item, head));
    return;
  }
  tail->next = new (item, tail->next);
  tail = tail->next;
}

Item queue_get(void) {
  Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}
