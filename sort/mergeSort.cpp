#include <iostream>
#include <cstdlib>

using namespace std;
#define SIZE 12

void swap(int& a, int& b) {
  int swap = a;
  a = b;
  b = swap;
};

int randnum() {
  return rand() % 12;
}

void merge(int *ary, int size1, int size2) {
  int temp[size1+size2];
  int ptr1=0, ptr2=0;
  while (ptr1+ptr2 < size1+size2) {
    if ( ptr1 < size1 && ary[ptr1] <= ary[size1+ptr2] || ptr1< size1 && ptr2 >= size2)
      temp[ptr1+ptr2] = ary[ptr1++];
    if ( ptr2 < size2 && ary[size1+ptr2] <= ary[ptr1] || ptr2< size2 && ptr1 >= size1)
      temp[ptr1+ptr2] = ary[size1+ptr2++];
  }

  for (int i=0; i < size1+size2; i++)
        ary[i] = temp[i];
}

void mergeSort(int *ary, int size) {
  if (size == 1)
    return;

  int size1 = size/2;
  int size2 = size - size1;

  mergeSort(ary , size1);
  mergeSort(ary+size1, size2);
  merge(ary,size1,size2);
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

  mergeSort(ary, SIZE);

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
