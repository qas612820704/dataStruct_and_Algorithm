#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
#define ARYSIZE 20
void swap(int& a, int& b) {
  int swap = a;
  a = b;
  b = swap;
}

void max_heapify(int* ary, int start, int end) {
  int dad = start;
  int son = dad*2 +1;
  while (son < end) {
    if (son+1 < end && ary[son+1] > ary[son])
      son++;
    if (ary[son] < ary[dad])
      return;
    else {
      swap(ary[son], ary[dad]);
      dad = son;
      son = dad*2 +1;
    }
  }
}

void heap_sort(int* ary, int len) {
  for (int i=len/2 -1; i>=0; i--)
    max_heapify(ary, i, len);
  for (int i= len -1; i>=0; i--) {
    swap(ary[0],ary[i]);
    max_heapify(ary, 0, i);
  }
}

int randnum() {
  return rand() % 1000;
}

int main() {
  srand(time(0));
  int arr[ARYSIZE];
  int len = (int) sizeof(arr) / sizeof(*arr);
  
  for (int i = 0; i < ARYSIZE; ++i)
  {
    arr[i] = randnum();
  }

  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);
  printf("\n");
  heap_sort(arr, len);
  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
