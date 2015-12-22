#include <iostream>
#include <cstdlib>

using namespace std;
#define SIZE 20

int randnum() {
  return rand() % 1000;
}

int main() {
  srand(time(0));
  int ary[SIZE];
  for (int i = 0; i < SIZE; ++i)
  {
    cout << (ary[i] = randnum()) << ',';
  }
  cout << endl;

  /* sort */
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE-i; j++)
    {
      if (ary[j] > ary[j+1]) {
        int temp = ary[j];
        ary[j] = ary[j+1];
        ary[j+1] = temp;
      }
    }
    cout << "[" << i << "]";
    for (int z = 0; z < SIZE; ++z)
    {
      cout << ary[z] << ',';
    }
    cout << endl;
  }

  for (int i = 0; i < SIZE; ++i)
  {
    cout << ary[i] << ',';
  }
  cout << endl;
  return 0;

}
