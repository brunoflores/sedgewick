int search(int a[], int val, int left, int right) {
  while (right >= left) {
    int middle = (left + right) / 2;
    if (val == a[middle]) {
      return middle;
    }
    if (val < a[middle]) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

int main() { return 0; }
