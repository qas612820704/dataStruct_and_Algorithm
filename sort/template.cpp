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

void mysort(int* ary) {
  
}

int main() {
  srand(time(0));
  int ary[SIZE];
  cout << "Before : ";
  for (int i = 0; i < SIZE; ++i)
  {
    cout << (ary[i] = randnum()) << " ,";
  }
  cout << endl;

  mysort(ary);
  cout << "After : ";
  for (int i = 0; i < SIZE; ++i)
  {
    cout << ary[i] << " ,";
  }
  cout << endl;
  return 0;

}
