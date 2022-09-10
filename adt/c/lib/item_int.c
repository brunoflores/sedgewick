#include "item.h"
#include <stdio.h>
#include <stdlib.h>

int Item_rand(void) { return rand(); }
int Item_scan(int *i) { return scanf("%d", i); }
void Item_show(int i) { printf("%d ", i); }
