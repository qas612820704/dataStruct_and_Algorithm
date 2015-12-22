#include <iostream>
#include <cstdlib>

using namespace std;
#define SIZE 20

void swap(int& a, int& b) {
  int swap = a;
  a = b;
  b = swap;
};

int randnum() {
  return rand() % 1000;
}

void quick_sort_recursive(int* ary, int start, int end) {
  int left = start;
  int right = end - 1;
  int midnum = ary[end];
  while (left <= right) {
    while (left < end && ary[left] < midnum) left++;
    while (right >= start && ary[right] > midnum) right--;
    if (left <= right)
      swap(ary[left], ary[right]);
    else {
      swap(ary[left], ary[end]);
      quick_sort_recursive(ary, start, right);
      quick_sort_recursive(ary, left+1, end);
    }
  }
}

void qSort(int* ary) {
  quick_sort_recursive(ary, 0, SIZE-1);
}

bool sortedcheck(int* ary) {
  for (int i = 0; i < SIZE-1; ++i)
  {
    if (ary[i] > ary [i+1])
      return false;
  }
  return true;
}

int main() {
  srand(time(0));
  int ary[SIZE];
  cout << "Before : \t";
  for (int i = 0; i < SIZE; ++i)
  {
    cout << (ary[i] = randnum()) << ", ";
  }
  cout << endl;

  qSort(ary);

  cout << "After : \t";
  for (int i = 0; i < SIZE; ++i)
  {
    cout << ary[i] << ", ";
  }
  cout << endl;
  if (sortedcheck(ary))
    cout << "Sorted checked: Yes" << endl;
  else
    cout << "Sorted checked: No" << endl;

  return 0;

}
