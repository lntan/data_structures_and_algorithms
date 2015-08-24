#include <stdlib.h>
#include <stdio.h>

void quick_sort(int[], int, int);

int main() {
  int a[100];
  a[0] = 15;
  a[1] = 10;
  a[2] = 8;
  a[3] = 23;
  a[4] = 20;
  a[5] = 16;
  a[6] = 24;
  a[7] = 19;
  a[8] = 10;
  int n = 9;
  quick_sort(a, 0, n - 1);
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
  return 0;
}


void quick_sort(int a[], int from, int to) {
  int x = a[(to + from)/2];
  int i = from;
  int j = to;
  while(i < j) {
    while(a[i] < x) i++;
    while(a[j] > x) j--;
    if (i <= j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }

  if(j > from) {
    quick_sort(a, from, j);
  }
  if (i < to) {
    quick_sort(a, i, to);
  }
}
