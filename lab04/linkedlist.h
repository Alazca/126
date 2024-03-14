#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>

template <class T>
class linkedlist {
private:
  struct Node {
    T data;
    Node* next;
  };

  Node* head;
  int size;
  int max_size;

public:
  linkedlist();
  ~linkedlist();
  bool isEmpty() const;
  bool isFull() const;
  int testMax(const int&);  // added to test functionality of is full
  int listSize() const;
  int maxListsize() const;
  void print() const;
  bool isItemAtEqual(int, T) const;
  void insertAt(int, T);
  void insertEnd(T);
  void removeAt(int);
  int retrieveAt(int);
  void replaceAt(int, T);
  void clearList();
  linkedlist& operator=(const linkedlist&);
};

template <class T>
linkedlist<T>::linkedlist() {
  size = 0;
  max_size = 100;
  head = nullptr;
}

template <class T>
linkedlist<T>::~linkedlist() {
  if (size >= 1) {
    clearList();
  }
}

template <class T>
int linkedlist<T>::testMax(const int& newMax) {
  return max_size = newMax;
}

template <class T>
bool linkedlist<T>::isEmpty() const {
  return size == 0;
}

template <class T>
bool linkedlist<T>::isFull() const {
  return size == max_size;
}

template <class T>
int linkedlist<T>::listSize() const {
  return size;
}

template <class T>
int linkedlist<T>::maxListsize() const {
  return max_size;
}

template <class T>
void linkedlist<T>::print() const {
  Node* nodePtr = head;
  int i = 0;
  if (isEmpty()) {
    std::cout << "List is Empty!" << std::endl;
    return;
  }
  std::cout << std::endl;
  while (nodePtr) {
    std::cout << "Index: " << i << " "
              << "Element: " << nodePtr->data << " " << std::endl;
    nodePtr = nodePtr->next;
    i++;
  }
  std::cout << std::endl;
}

template <class T>
bool linkedlist<T>::isItemAtEqual(int index, T element) const {
  Node* nodePtr = head;
  if (index < 0 || index > size) {
    throw std::out_of_range("INVALID: INDEX or OUT OF RANGE PARAMETERS!");
  }
  for (int i = 0; i < index; i++) {
    nodePtr = nodePtr->next;
  }
  return nodePtr->data == element;
}

template <class T>
void linkedlist<T>::clearList() {
  Node* nodePtr = head;
  Node* nextNode = nullptr;
  while (nodePtr != nullptr) {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
  size = 0;
}

template <class T>
void linkedlist<T>::insertAt(int index, T element) {
  Node* nodePtr = nullptr;
  Node* newNode = new Node;
  newNode->data = element;
  newNode->next = nullptr;

  if (index < 0 || index > size) {
    throw std::out_of_range(
        "INVALID INSERTION: INDEX or OUT OF RANGE PARAMETERS!");
  }
  if (isFull()) {
    throw std::out_of_range("INVALID: Target is full!");
  }
  if (isEmpty()) {
    head = newNode;
    newNode->next = nullptr;
  }
  nodePtr = head;
  Node* prevPtr = nullptr;
  int i = 0;
  while (nodePtr != nullptr) {
    prevPtr = nodePtr;
    nodePtr = nodePtr->next;

    i++;
    if (i == index) {
      break;
    }
  }
  prevPtr->next = newNode;
  newNode->next = nodePtr;

  size++;
}

template <class T>
void linkedlist<T>::insertEnd(T element) {
  Node* nodePtr = nullptr;
  Node* newNode = new Node;
  newNode->data = element;
  newNode->next = nullptr;

  if (isFull()) {
    throw std::out_of_range("INVALID: Target is full!");
  }
  if (isEmpty()) {
    head = newNode;
    newNode->next = nullptr;
  }
  nodePtr = head;
  while (nodePtr->next) {
    nodePtr = nodePtr->next;
  }
  nodePtr->next = newNode;
  size++;
}

template <class T>
void linkedlist<T>::removeAt(int index) {
  Node* nodePtr = nullptr;
  Node* prePtr = nullptr;
  if (isEmpty()) {
    std::cout << "List is empty! No node to remove!" << std::endl;
    return;
  }
  if (head->next == 0) {
    nodePtr = head->next;
    delete nodePtr;
    head = head->next;
  }
  nodePtr = head;
  while (nodePtr->next != nullptr) {
    prePtr = nodePtr;
    nodePtr = nodePtr->next;
  }
  if (nodePtr) {
    prePtr->next = nodePtr->next;
    delete nodePtr;
    nodePtr->next = nullptr;
  }
  size--;
}

template <class T>
int linkedlist<T>::retrieveAt(int index) {
  Node* nodePtr = nullptr;

  if (index < 0 || index > size) {
    throw std::out_of_range(
        "INVALID RETRIEVAL: Index or OUT OF RANGE PARAMETERS!");
  }
  nodePtr = head;
  while (nodePtr->next != nullptr) {
    nodePtr = nodePtr->next;
  }
  return nodePtr->data;
}

template <class T>
void linkedlist<T>::replaceAt(int index, T element) {
  Node* nodePtr = nullptr;

  if (index < 0 || index > size) {
    throw std::out_of_range(
        "invalid retrieval: index or out of range parameters!");
  }
  nodePtr = head;
  while (nodePtr->next != nullptr) {
    nodePtr = nodePtr->next;
  }
  if (nodePtr) {
    nodePtr->data = element;
  }
}

// TODO- FINISH THE ASSIGNMENT OPERATOR
template <class T>
linkedlist<T>& linkedlist<T>::operator=(const linkedlist<T>& rhs) {
  if (this != &rhs) {
    clearList();
  }
  return *this;
}
#endif
