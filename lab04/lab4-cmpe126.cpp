#include <iostream>
#include "linkedlist.h"
#include "sortedLinkList.h"
using namespace std;

int main() {
  linkedlist<int> list;
  linkedlist<int> list2;
  sortedlinkedlist<int> sortList;
  cout << "Is list 1 empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
  cout << "Is list 1 full? " << (list.isFull() ? "Yes" : "No") << endl;
  cout << "Filling list 1!" << endl;
  list.insertAt(0, 5);
  list.insertAt(1, 2);
  list.insertAt(2, 3);
  list.insertAt(3, 8);
  cout << "Is Index 3 equal to 8? " << (list.isItemAtEqual(3, 8) ? "Yes" : "No")
       << endl;
  cout << "Is Index 2 equal to 8? " << (list.isItemAtEqual(2, 8) ? "Yes" : "No")
       << endl;
  list.print();
  cout << "Testing INSERT END function!\n";
  list.insertEnd(10);
  list.print();
  cout << "Testing REMOVE AT function!\n";
  list.removeAt(4);
  list.print();
  cout << "List 1 size is " << list.listSize() << endl;
  list.clearList();
  cout << "Is list 2 empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
  cout << "Filling list 2!" << endl;
  list2.insertAt(0, 5);
  list2.insertAt(1, 2);
  list2.insertAt(2, 3);
  list2.insertAt(3, 8);
  list2.insertAt(4, 8);
  list2.print();
  cout << "Testing REPLACE function!\n";
  list2.replaceAt(4, 9);
  list2.print();
  cout << "Is list 2 empty? " << (list2.isEmpty() ? "Yes" : "No") << endl;
  cout << "Is list 2 full? " << (list2.isFull() ? "Yes" : "No") << endl;
  cout << "Temp change of max size! New Max: " << list2.testMax(5) << endl;
  cout << "Is list 2 full after changing range? "
       << (list2.isFull() ? "Yes" : "No") << endl;
  cout << list2.retrieveAt(3) << " is at index 3!" << endl;
  cout << "Clearing list to test list2!" << endl;
  list2.clearList();
  list2.testMax(100);
  cout << "Is list 2 empty now? " << (list2.isEmpty() ? "Yes" : "No") << endl;
  list2.print();
  list = list2;
  cout << "Checking assignment operator!" << endl;
  list.print();

  // Task 2
  sortList.print();
  cout << "Is there an element 0 in sorted list? "
       << (sortList.isItemInList(0) ? "Yes" : "No") << endl;
  sortList.insert(2);
  sortList.insert(1);
  sortList.insert(3);
  sortList.insert(4);
  sortList.print();
  cout << "\nTesting complete!\n";
  return 0;
}
