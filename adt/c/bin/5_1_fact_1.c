#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int factorial(int N) {
  if (N == 0) {
    return 1;
  }
  return N * factorial(N - 1);
}

int main(int __attribute__((unused)) argc, char *argv[]) {
  int N = atoi(argv[1]);
  {
    int fact = factorial(N);
    printf("Recursive answer: %d\n", fact);
  }
  {
    int fact = 1;
    for (int i = 1; i <= N; i++) {
      fact *= i;
    }
    printf("Loop answer %d\n", fact);
  }
}
