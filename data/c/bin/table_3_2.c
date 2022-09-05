int my_strlen(char *a) {
  int i;
  for (i = 0; a[i] != 0; i++)
    ;
  return i;
}

void my_strcpy(char *from, char *to) {
  for (int i = 0; (to[i] = from[i]) != 0; i++)
    ;
}

int my_strcmp(char *a, char *b) {
  int i;
  for (i = 0; a[i] == b[i]; i++) {
    if (a[i] == 0) {
      return 0;
    }
  }
  return a[i] - b[i];
}

int main(void) { return 0; }
