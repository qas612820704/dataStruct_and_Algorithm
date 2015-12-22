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

int main() {
  srand(time(0));
  Node* node1;
  Node* node2;
  node1 = NULL;
  node2 = NULL;
  cout << (node1 == NULL) << endl;
  return 0;
}
