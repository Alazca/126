#include <cstdlib>
#include <iostream>
#include "arrayList.h"

using namespace std;

int main() {
  srand(time(0));
  int SIZE = 10;
  int MAX = 100;
  int MIN = 0;
  arrayList<int> list(SIZE);
  arrayList<int> list2(SIZE);
  for (int i = MIN; i < SIZE; i++) {
    int randomNum = MIN + rand() % (MAX - MIN + 1);
    list.insertAt(i, randomNum);
  }
  list.print();
  cout << "The MIN element is " << list.min() << endl;
  cout << "The MAX element is " << list.max() << endl;
  for (int i = MIN; i < SIZE; i++) {
    int randomNum = MIN + rand() % (MAX - MIN + 1);
    list2.insertAt(i, randomNum);
    if (randomNum % 2 == 0) {
      list2.replaceAt(i, 2);
    }
  }
  list2.print();
  cout << "There are " << list2.count(2) << " values of 2 in the list!" << endl;
  return 0;
}
