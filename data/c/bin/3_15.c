#include <stdio.h>
#define N 10000

int main(int __attribute__((unused)) argc, char *argv[]) {
  int i;
  int j;
  int t;
  char a[N];
  char *p = argv[1];

  for (i = 0; i < (N - 1); a[i] = t, i++) {
    if ((t = getchar()) == EOF) {
      break;
    }
  }

  a[i] = 0;

  for (i = 0; a[i] != 0; i++) {
    for (j = 0; p[j] != 0; j++) {
      if (a[i + j] != p[j]) {
        break;
      }
    }
    if (p[j] == 0) {
      printf("%d ", i);
    }
  }

  printf("\n");
}

// Usage:
// $ echo "bruno flores lorem" | ./3_15 lore
// 7 13
