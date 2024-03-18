#include <cstdlib>
#include <iostream>
#include "arrayList.h"

using namespace std;

int main() {
  srand(time(0));
  int SIZE = 10;
  int MAX = 100;
  int MIN = 0;
  arrayList<int> list(MAX);
  arrayList<int>* list2 = new arrayList<int>(SIZE);
  // Generate random values into array to check MIN/MAX and COUNT functions
  for (int i = MIN; i < SIZE; i++) {
    int randomNum = MIN + rand() % (MAX - MIN + 1);
    list.insertAt(i, randomNum);
    if (randomNum % 2 == 0) {
      list.replaceAt(i, list.max() - list.min());
    }
  }
  list.print();
  cout << "The MIN element is " << list.min() << endl;
  cout << "The MAX element is " << list.max() << endl;
  cout << "There are " << list.count(list.min())
       << " values of the minimum in the list!" << endl;
  for (int i = MIN; i < SIZE; i++) {
    int randomNum = MIN + rand() % (MAX - MIN + 1);
    list2->insertAt(i, randomNum);
  }
  list.extend(list2);
  cout << "\nNew list after being extended!\n" << endl;
  list.print();
  return 0;
}
