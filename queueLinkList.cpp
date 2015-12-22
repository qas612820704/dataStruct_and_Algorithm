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

class Queue
{
private:
  Node* head;
  Node* tail;
public:
  Queue() {
    head = nullptr;
    tail = nullptr;
  }
  ~Queue() {
    head = nullptr;
    tail = nullptr;
    delete head, tail;
  };
  bool isEmpty() {
    return (head == nullptr);
  }
  bool isFull() {
    return false;
  }
  int insert(int data) {
    if (isFull()) {
       cout << "Queue overflow" << endl;
       exit(1);
    }
    Node* node = new Node(data);
    if (tail == nullptr)
      head = node;
    else
      tail->next = node;
    tail = node;
    return data;
  }
  int remove() {
    if(isEmpty()) {
      cout << "Queue underflow" << endl;
      exit(1);
    }
    
    Node* node = head;
    int data = node->data;
    head = node->next;
    if (head == nullptr)
      tail = nullptr;
    delete node;
    return data;
  }
};

int randnum() {
  return rand() % 1000;
}

int main() {
  srand(time(0));
  Queue*  queue = new Queue();
  for (int i = 0; i < 10; ++i)
  {
    cout << queue->insert(randnum()) << ',';
  }
  cout << endl;
  while (!queue->isEmpty()) {
    cout << queue->remove() << ',';
  }
  cout << endl;
  return 0;
}
