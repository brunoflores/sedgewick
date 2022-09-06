#include "item.h"
#include <stdlib.h>

typedef struct stack_node *link;

struct stack_node {
  Item item;
  link next;
};

static link head;

link new (Item item, link next) {
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

void stack_init(int __attribute__((unused)) maxN) { head = NULL; }

int stack_empty(void) { return head == NULL; }

void stack_push(Item item) { head = new (item, head); }

Item stack_pop(void) {
  Item item = head->item;
  link new_head = head->next;
  free(head);
  head = new_head;
  return item;
}
