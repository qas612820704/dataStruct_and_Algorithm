#include <iostream>
#include <cstdlib>
using namespace std;
#define nullptr NULL
void swap(int& a, int& b) {
  int swap = a;
  a = b;
  b = swap;
};

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

class Graph
{
private:
  int size;
  bool **connect;
public:
  Graph(int n) {
    size = n;
    connect = new bool*[size];
    for (int i = 0; i < size; ++i)
    {
      connect[i] = new bool[n];
      for (int j = 0; j < size; ++j)
      {
        connect[i][j] = false;
      }
    }
  }
  ~Graph() {
    for (int i = 0; i < size; ++i)
      delete connect[i];
    delete connect;
  }
  bool isConnected(int x, int y) {
    return connect[x][y];
  }
  void addEdge(int x, int y) {
    connect[x][y] = connect[y][x] = true;
  }
  void DFS(int start, int end) {
    cout << "DFS : ";
    Stack *s = new Stack();
    bool* visited = new bool[size];
    for (int i = 0; i < size; ++i)
      visited[i] = false;
    s->push(start);
    visited[start] = true;
    while (!s->isEmpty()) {
      int node = s->pop();
      cout << node << ", ";
      if (node == end) break;
      for (int i = 0; i < size; ++i)
      {
        if ( isConnected(node, i) && !visited[i]) {
          s->push(i);
          visited[i] = true;
        }
      }
    }
    cout << endl;
    delete [] visited;
  }
  void BFS(int start, int end) {
    cout << "BFS : ";
    Queue *q = new Queue();
    bool* visited = new bool[size];
    for (int i = 0; i < size; ++i)
      visited[i] = false;
    q->insert(start);
    visited[start] = true;
    while (!q->isEmpty()) {
      int node = q->remove();
      cout << node << ", ";
      if (node == end) break;
      for (int i = 0; i < size; ++i)
      {
        if (isConnected(node, i) && !visited[i]) {
          q->insert(i);
          visited[i] = true;
        }
      }
    }
    cout << endl;
    delete [] visited;
  }
};

int main() {
  Graph g(9);
  g.addEdge(1, 2); g.addEdge(1, 3); g.addEdge(1, 4);
  g.addEdge(2, 5); g.addEdge(2, 6); g.addEdge(4, 7);
  g.addEdge(4, 8);
  g.DFS(1, 5);
  g.BFS(1, 8);
  return 0;
}
