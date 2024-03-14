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
  list.removeAt(3);
  list.print();
  cout << "List 1 size is " << list.listSize() << endl;
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
  cout << "Element " << list.retrieveAt(1) << " is at Index 1 for list 1!"
       << endl;
  cout << "Element " << list2.retrieveAt(2) << " is at Index 2 for list 2!"
       << endl;
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
  cout << "Checking assignment operator!" << endl;
  list = list2;
  list2.print();

  // Task 2
  sortList.print();
  cout << "Is there an element 0 in sorted list? "
       << (sortList.isItemInList(0) ? "Yes" : "No") << endl;
  cout << "\nFilling sorted list!" << endl;
  sortList.insert(2);
  sortList.insert(1);
  sortList.insert(4);
  sortList.insert(4);
  sortList.insert(8);
  sortList.print();
  cout << "Testing REMOVE function for sorted list." << endl;
  sortList.remove(2);
  sortList.print();
  cout << "Is there an element 0 in sorted list? "
       << (sortList.isItemInList(0) ? "Yes" : "No") << endl;
  cout << "Is there an element 10 in sorted list? "
       << (sortList.isItemInList(10) ? "Yes" : "No") << endl;
  cout << "Element " << sortList.retrieveAt(0) << " is at index 0\n";
  cout << "Clearing all lists!" << endl;
  sortList.clearlist();
  list.clearList();
  list2.clearList();
  cout << endl;
  cout << "Is list 1 empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
  cout << "Is list 2 empty? " << (list2.isEmpty() ? "Yes" : "No") << endl;
  cout << "Is sortlist empty? " << (sortList.isEmpty() ? "Yes" : "No") << endl;
  cout << "\nTesting complete!\n";
  return 0;
}
