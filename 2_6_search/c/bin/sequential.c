/*
  Linear search:

  Check whether the number `v` is among a previously stored set of numbers in
  `a[l], a[l+1], ..., a[r]`, by comparing against each number sequentially,
  starting at the beginning.

  If we reach the end without finding the number sought, then we return the
  value `-1`. Otherwise, we return the index of the array position containing
  the number.
*/
int search(int a[], int val, int left, int right) {
  int i;
  for (i = left; i <= right; i++) {
    if (val == a[i]) {
      return i;
    }
  }
  return -1;
}

int main() { return 0; }
