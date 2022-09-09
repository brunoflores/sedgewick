#include "item.h"
#include "queue_adt.h"
#include <stdio.h>
#include <stdlib.h>

#define M 10

int main(int __attribute__((unused)) argc, char *argv[]) {
  int N = atoi(argv[1]);
  Q queues[M]; // An array of queues

  for (int i = 0; i < M; i++) {
    queues[i] = Queue_init(N);
  }

  for (int j = 0; j < N; j++) {
    Queue_put(queues[rand() % M], j);
  }

  for (int i = 0; i < M; i++, printf("\n")) {
    for (int j = 0; !Queue_empty(queues[i]); j++) {
      printf("%3d ", Queue_get(queues[i]));
    }
  }
}

// Usage:
// $ ./4_19 84
//  12  16  25  49  53  57  79
//   9  20  38  42  52  59
//   7  10  18  24  26  31  32  39  56  72
//   0   4  14  27  36  41  50  55  68  78
//  44  47  62  70  74  76  77
//   3   5  29  48  60  61  65  71  73
//   1   6  15  17  19  37  51  54  58  64  66  82
//   2  11  22  28  35  45  63  69  75  80
//  21  33  46  81  83
//   8  13  23  30  34  40  43  67
