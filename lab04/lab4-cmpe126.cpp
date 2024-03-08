#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
  linkedlist<int> list;
  linkedlist<int> list2;

  cout << "Is list 1 empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
  cout << "Is list 1 full? " << (list.isFull() ? "Yes" : "No") << endl;
  return 0;
}
