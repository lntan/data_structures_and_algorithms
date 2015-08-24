#include <stdlib.h>
#include <stdio.h>

void heap_sort(int[], int);
void build_head(int[], int);
void heapify(int[], int, int);

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
  heap_sort(a, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

void build_head(int a[], int length) {
  for (int i = length/2; i >= 0; i--) {
    heapify(a, i, length - 1);
  }
}

void heapify(int a[], int i, int heap_size) {
  int left = 2*i;
  int right = 2*i + 1;
  int max = i;
  if (left <= heap_size && a[left] > a[max]) {
    max = left;
  }
  if (right <= heap_size && a[right] > a[max]) {
    max = right;
  }
  if (max != i) {
    int temp = a[max];
    a[max] = a[i];
    a[i] = temp;
    heapify(a, max, heap_size);
  }
}

void heap_sort(int a[], int length) {
  for (int i = length; i > 0; i--) {
    int heap_size = i;
    build_head(a, heap_size);
    int temp = a[heap_size - 1];
    a[heap_size - 1] = a[0];
    a[0] = temp;
  }
}
