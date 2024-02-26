#include <iostream>
#include "arrayList.h"

using namespace std;

int main() {
  int capacity = 25;
  int capacity2 = 30;
  arrayList<int> list(capacity);    // Create a list with a capacity
  arrayList<int> list2(capacity2);  // Create a second list

  // Insert elements into the list
  list.insertEnd(10);
  list.insertEnd(10);
  list.insertEnd(30);
  list.insertEnd(40);

  cout << "List elements by index: " << endl;
  list.print();

  cout << "Is item equal: " << (list.isItemAtEqual(0, 10) ? "Yes" : "No")
       << endl;

  cout << "Is item equal: " << (list.isItemAtEqual(0, 20) ? "Yes" : "No")
       << endl;

  // Check if list is empty
  cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

  // Check if list is full
  cout << "Is list full? " << (list.isFull() ? "Yes" : "No") << endl;

  // Print list size and max size
  cout << "List size: " << list.listSize() << endl;
  cout << "Max list size: " << list.maxListSize() << endl;

  // Insert an element at Index 2
  list.insertAt(2, 25);
  cout << "List elements after insert: \n";
  list.print();

  // Remove element at Index 1
  list.removeAt(1);
  cout << "List elements after remove: \n";
  list.print();

  // Retrieve element at Index 2
  cout << "Element at Index 2: " << list.retrieveAt(2) << endl;

  // Replace element at Index 0 with 5
  list.replaceAt(0, 5);
  cout << "List elements after replace: \n";
  list.print();

  list2.insertEnd(10);
  list2.insertEnd(40);
  cout << "Elements in list 2 are: \n";
  list2.print();
  list2 = list;

  cout << "Elements in list 2 after assignment: \n";
  list2.print();

  // Clear the list
  list.clearList();
  list2.clearList();

  cout << "List1 elements after clear: \n";
  list.print();
  cout << "Is List1 empty? " << (list.isEmpty() ? "Yes" : "No") << endl;
  cout << "List2 elements after clear: \n";
  list2.print();
  cout << "Is list2 empty? " << (list2.isEmpty() ? "Yes" : "No") << endl;
  return 0;
}
