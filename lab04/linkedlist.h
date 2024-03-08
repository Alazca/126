#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>

template <class elemType>
class linkedlist {
private:
  class Node {
    elemType element;
    linkedlist<elemType>* next;
  };

  Node* head;
  int size;
  int max_size;

public:
  linkedlist();
  ~linkedlist();
  bool isEmpty() const;
  bool isFull() const;
  int listSize() const;
  int maxListsize() const;
  void print();
  bool isItemAtEqual(int, elemType) const;
  void insertAt(int, elemType);
  void insertEnd(elemType);
  void removeAt(elemType);
  int retrieveAt(int);
  void replaceAt(int, elemType);
  void clearList();
  linkedlist& operator=(const linkedlist&);
};

template <class elemType>
linkedlist<elemType>::linkedlist() {
  size = 0;
  max_size = 100;
  head = nullptr;
}

template <class elemType>
linkedlist<elemType>::~linkedlist() {
  clearList();
}

template <class elemType>
bool linkedlist<elemType>::isEmpty() const {
  return size == 0;
}

template <class elemType>
bool linkedlist<elemType>::isFull() const {
  return size == max_size;
}

template <class elemType>
int linkedlist<elemType>::listSize() const {
  return size;
}

template <class elemType>
int linkedlist<elemType>::maxListsize() const {
  return max_size;
}

template <class elemType>
void linkedlist<elemType>::print() {
  Node* current = head;
  int i = 0;
  while (current != nullptr) {
    std::cout << "Index: " << i << " "
              << "Element: " << current->element << " ";
    current = current->next;
    i++;
  }
  std::cout << std::endl;
}

template <class elemType>
bool linkedlist<elemType>::isItemAtEqual(int index, elemType element) const {
  if (index < 0 || element >= size) {
    throw std::out_of_range("INVALID: INDEX or OUT OF RANGE PARAMETERS!");
  }
  Node* current = head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current == element;
}

template <class elemType>
void linkedlist<elemType>::clearList() {
  size = 0;
}

template <class elemType>
void linkedlist<elemType>::insertAt(int index, elemType element) {
  if (index < 0 || element >= size) {
    throw std::out_of_range("INVALID: INSERTION PARAMETERS!");
  }
  if (isFull()) {
    throw std::out_of_range("INVALID: Full Array!");
  }
  Node* current = head;
}

#endif
