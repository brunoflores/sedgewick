#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nmax 1000  // Max number of C strings in buffer.
#define Mmax 10000 // Max length of characters buffer.

char buf[Mmax]; // Characters buffer.
int M = 0;      // Index of currently available position in characters buffer.

int compare(const void *i, const void *j) {
  // To access the first character in a string for a comparison, we derreference
  // three pointers: one to get the index (which is a pointer) into our array,
  // one to get the pointer to the string (using the index), and one to get the
  // character (using the pointer).
  return strcmp(*(char **)i, *(char **)j);
}

int main(void) {
  int N;         // Number of C strings in the characters buffer.
  char *a[Nmax]; // Pointers to strings in characters buf.

  for (N = 0; N < Nmax; N++) {
    a[N] = &buf[M];
    if (scanf("%s", a[N]) == EOF) {
      break;
    }
    M += strlen(a[N]) + 1;
  }

  qsort(a, N, sizeof(char *), compare);

  for (int i = 0; i < N; i++) {
    printf("%s\n", a[i]);
  }
}

// Usage:
// $ echo "bruno lorem flores" | ./3_17
// bruno
// flores
// lorem
