#include <cstdlib>
#include <iostream>
#include "arrayList.h"
#include "linkedlist.h"
using namespace std;

int main() {
  srand(time(0));
  int SIZE = 10;
  int MAX = 100;
  int MIN = 0;
  arrayList<int> list(MAX);
  arrayList<int>* list2 = new arrayList<int>(SIZE);
  linkedlist<int> llist;
  //   Generate random values into array to check MIN/MAX and COUNT functions
  cout << "Populating list 1!" << endl;
  for (int i = 0; i < SIZE; i++) {
    int randomNum = MIN + rand() % (MAX - MIN + 1);
    list.insertAt(i, randomNum);
    if (randomNum % 2 == 0) {
      list.replaceAt(i, list.max() - list.min());
    }
  }
  list.print();
  cout << "The MIN element in list 1 is " << list.min() << endl;
  cout << "The MAX element is list 1 is " << list.max() << endl;
  cout << "There are " << list.count(list.min())
       << " values of the minimum in the list!" << endl;
  cout << "Populating list 2!" << endl;
  for (int i = 0; i < SIZE; i++) {
    int randomNum = MIN + rand() % (MAX - MIN + 1);
    list2->insertAt(i, randomNum);
  }
  list.extend(list2);
  cout << "\nNew list after being extended!\n" << endl;
  list.print();
  cout << "List 1 was cleared!\n";
  list.clearList();
  cout << "List 2 was cleared!\n";
  list2->clearList();
  delete list2;
  // ####### TASK 2 ############
  cout << "Populating linked list!" << endl;
  for (int i = 0; i < SIZE - 1; i++) {
    int randomNum = MIN + rand() % (MAX - MIN + 1);
    llist.insertAt(i, randomNum);
    if (randomNum % 2 == 1) {
      llist.replaceAt(i, llist.max() - llist.min());
    }
  }
  //
  llist.print();
  cout << "The MIN element is " << llist.min() << endl;
  cout << "The MAX element is " << llist.max() << endl;
  cout << "There are " << llist.count(llist.min()) << " values of the minumum!"
       << endl;
  cout << "Linked list was cleared!" << endl;
  llist.clearList();
  return 0;
}
