#include "item.h"

typedef struct queue *Q;

void Queue_dump(Q);
Q Queue_init(int maxN);
int Queue_empty(Q);
void Queue_put(Q, Item);
Item Queue_get(Q);
