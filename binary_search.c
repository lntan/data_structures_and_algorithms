#include <stdlib.h>
#include <stdio.h>

int binary_search(int a[], int left, int right, int val);
void quick_sort(int[], int, int);

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
  quick_sort(a, 0, n - 1);
  printf("%d\n", binary_search(a, 0, n - 1, 10));
  printf("%d\n", binary_search(a, 0, n - 1, 8));
  printf("\n");
}

int binary_search(int a[], int left, int right, int val) {
  if(left > right) return -1;
  int mid = (right + left)/2;

  if (a[mid] == val) {
    return mid;
  } else if (a[mid] < val) {
    return binary_search(a, mid + 1, right, val);
  } else {
    return binary_search(a, left, mid - 1, val);
  }
  return -1;
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


