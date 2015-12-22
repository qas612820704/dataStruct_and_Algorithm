#include <iostream>
#include <cstdlib>
using namespace std;

#define QUEUESIZE 10

class Queue
{
private:
  int head, tail;
  int items[QUEUESIZE];
public:
  Queue() {
    for (int i = 0; i < QUEUESIZE; ++i)
    {
      items[i] = 0;
    }
    head = tail = QUEUESIZE -1;
  }
  ~Queue() {};
  bool isEmpty() {
    return head == tail;
  }
  bool isFull() {
    return head == (tail+1);
  }
  int insert(int data) {
    if (isFull()) {
       cout << "Queue overflow" << endl;
       exit(1);
    }
    if (tail == QUEUESIZE -1)
      tail = 0;
    else
      tail++;
    items[tail] = data;
    return data;
  }
  int remove() {
    if(isEmpty()) {
      cout << "Queue underflow" << endl;
      exit(1);
    }
    if (head == QUEUESIZE -1)
      head = 0;
    else
      head++;
    return items[head];
  }
};

int randnum() {
  return rand() % 1000;
}

int main() {
  srand(time(0));
  Queue*  queue = new Queue();
  for (int i = 0; i < 20; ++i)
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
