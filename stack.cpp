#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define STACKSIZE 100

class Stack {
private:
  int items[STACKSIZE];
  int top;
public:
  Stack() {
    for (int i = 0; i < STACKSIZE; i++) {
        items[i] = 0;
    }
    top = -1;
  }
  ~Stack() {};
  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == STACKSIZE -1)
      return true;
    else
      return false;
  }
  int pop() {
    if (isEmpty()) {
      cout << "Stack Underflow" << endl;
      exit(1);
    }
    else
      return items[top--];
  }
  int push(int data) {
    if (isFull()) {
      cout << "Stack Overflow!" << endl;
      exit(1);
    }
    else
      items[++top] = data;
    return data;
  }
};

int randnum() {
  return rand() % 1000;
}

int main() {
  srand(time(0));
  Stack* stack = new Stack();
  for (int i = 0; i < 10; ++i)
  {
    cout << stack->push(randnum()) << ',';
  }
  cout << endl;
  while (!stack->isEmpty()) {
    cout << stack->pop() << ',';
  }
  cout << endl;
  return 0;
}
