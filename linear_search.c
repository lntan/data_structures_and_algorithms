#include <stdlib.h>
#include <stdio.h>

int linear_search(int a[], int n, int val);

int main() {
  int a[100];
  a[0] = 15;
  a[1] = 2;
  a[2] = 8;
  a[3] = 7;
  a[4] = 3;
  a[5] = 6;
  a[6] = 9;
  a[7] = 17;
  int n = 8;
  printf("%d\n", linear_search(a, n, 10)); // -1
  printf("%d\n", linear_search(a, n, 8)); // 2
  printf("\n");
}

int linear_search(int a[], int n, int val) {
  int index = -1;
  for(int i = 0; i < n; i++) {
    if (a[i] == val) return i;
  }
  return -1;
}
