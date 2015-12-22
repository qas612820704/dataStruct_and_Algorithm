#include <iostream>
#include <cstdlib>

#define nullptr NULL
using namespace std;

class Node
{
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
  ~Node() {
    next = nullptr;
    delete next;
  }
};

class Stack {
private:
  Node* top;
public:
  Stack() {
    top = nullptr;
  }
  ~Stack() {
    delete top;
  };
  bool isEmpty() {
    return (top == nullptr);
  }
  bool isFull() {
      return false;
  }
  int pop() {
    if (isEmpty()) {
      cout << "Stack Underflow" << endl;
      exit(1);
    }
    Node* node = top;
    int data = node->data;
    top = top->next;
    delete node;
    return data;
  }
  int push(int data) {
    if (isFull()) {
      cout << "Stack Overflow!" << endl;
      exit(1);
    }
      Node* node = new Node(data);
      if (top != nullptr)
        node->next = top;
      top = node;
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
