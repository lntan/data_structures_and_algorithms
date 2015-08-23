#include <stdlib.h>
#include <stdio.h>

void selection_sort(int *a, int n);
int min(int *a, int from, int to);

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
  selection_sort(a, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}

void selection_sort(int *a, int n) {
  for(int i = 0; i < n - 1; i++) {
    int min_index = min(a, i + 1, n - 1);
    printf("%d\n", min_index);
    if (a[i] > a[min_index]) {
      int temp = a[i];
      a[i] = a[min_index];
      a[min_index] = temp;
    }
  }
}

int min(int *a, int from, int to) {
  int min_index = from;
  int min = a[min_index];
  for (int i = from + 1; i <= to; i++) {
    if (a[i] < min) {
      min_index = i;
      min = a[min_index];
    }
  }

  return min_index ;
}
