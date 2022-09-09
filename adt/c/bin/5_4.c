#include <stdio.h>

char *a;
int i = 0;

int eval(void) {
  int x = 0;

  while (a[i] == ' ') {
    i++;
  }

  if (a[i] == '+') {
    i++;
    return eval() + eval();
  }

  if (a[i] == '*') {
    i++;
    return eval() * eval();
  }

  // Convert from ASCII to binary:
  while ((a[i] >= '0') && (a[i] <= '9')) {
    x = 10 * x + (a[i++] - '0');
  }

  return x;
}

int main(void) {
  a = "* + 7 * * 4 6 + 8 9 5";
  printf("%d\n", eval());
  return 0;
}
