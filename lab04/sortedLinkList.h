#ifndef SORTEDLINKEDLIST_HPP_
#define SORTEDLINKEDLIST_HPP_
#include <iostream>

template <class S>
class sortedlinkedlist {
private:
  struct Node {
    S data;
    Node* next;
  };

  Node* head;
  int size;
  int max_size;

public:
  sortedlinkedlist();
  ~sortedlinkedlist();
  bool isEmpty() const;
  bool isFull() const;
  int listSize() const;
  int maxListsize() const;
  bool isItemInList(const S&) const;
  void insert(const S&);
  void remove(const S&);
  S retrieveAt(const int&) const;
  void print() const;
  void clearlist();
  sortedlinkedlist& operator=(const sortedlinkedlist&);
};

template <class S>
sortedlinkedlist<S>::sortedlinkedlist() {
  size = 0;
  max_size = 100;
  head = nullptr;
}

template <class S>
sortedlinkedlist<S>::~sortedlinkedlist() {
  if (size >= 1) {
    clearlist();
  }
}

template <class S>
bool sortedlinkedlist<S>::isEmpty() const {
  return size == 0;
}

template <class S>
bool sortedlinkedlist<S>::isFull() const {
  return size == max_size;
}

template <class S>
int sortedlinkedlist<S>::listSize() const {
  return size;
}

template <class S>
int sortedlinkedlist<S>::maxListsize() const {
  return max_size;
}

template <class S>
void sortedlinkedlist<S>::print() const {
  Node* nodePtr = head;
  int i = 0;
  if (isEmpty()) {
    std::cout << "Sorted List is Empty!" << std::endl;
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

template <class S>
bool sortedlinkedlist<S>::isItemInList(const S& element) const {
  bool flag = false;
  Node* nodePtr = head;
  if (isEmpty()) {
    return flag;
  }
  while (nodePtr->next != nullptr) {
    if (nodePtr->data == element) {
      flag = true;
    }
    nodePtr = nodePtr->next;
  }
  return flag;
}

template <class S>
void sortedlinkedlist<S>::clearlist() {
  Node* nodePtr = head;
  Node* nextNode = nullptr;
  while (nodePtr != nullptr) {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
    size--;
  }
  head = nullptr;
}

template <class S>
void sortedlinkedlist<S>::insert(const S& element) {
  if (isFull()) {
    throw std::out_of_range("INVALID: Target is full!");
  }
  Node* nodePtr = nullptr;
  Node* prevPtr = nullptr;
  Node* newNode = new Node;
  newNode->data = element;
  newNode->next = nullptr;
  if (isEmpty() || element < head->data) {
    newNode->next = head;
    head = newNode;
  }
  nodePtr = head;
  while (nodePtr != nullptr && nodePtr->data <= element) {
    prevPtr = nodePtr;
    nodePtr = nodePtr->next;
  }
  prevPtr->next = newNode;
  newNode->next = nodePtr;

  size++;
}

template <class S>
void sortedlinkedlist<S>::remove(const S& element) {
  Node* nodePtr = head;
  Node* prePtr = nullptr;
  if (isEmpty()) {
    std::cout << "List is empty! No node to remove!" << std::endl;
    return;
  }
  if (nodePtr == nullptr) {
    std::cout << "Element not found in the list!" << std::endl;
    return;
  }
  if (nodePtr->data == element) {
    head = head->next;
    delete nodePtr;
    size--;
    return;
  }
  while (nodePtr != nullptr && nodePtr->data != element) {
    prePtr = nodePtr;
    nodePtr = nodePtr->next;
  }
  prePtr->next = nodePtr->next;
  delete nodePtr;
  size--;
}

template <class S>
S sortedlinkedlist<S>::retrieveAt(const int& index) const {
  Node* nodePtr = nullptr;
  if (index < 0 || index > size) {
    throw std::out_of_range(
        "INVALID RETRIEVAL: Index or OUT OF RANGE PARAMETERS!");
  }
  nodePtr = head;
  for (int i = 0; i < index; ++i) {
    nodePtr = nodePtr->next;
  }
  return nodePtr->data;
}

template <class S>
sortedlinkedlist<S>& sortedlinkedlist<S>::operator=(
    const sortedlinkedlist<S>& rhs) {
  // Check for self-assignment
  if (this == &rhs) {
    return *this;
  }
  clearlist();
  size = rhs.size;
  max_size = rhs.max_size;
  if (rhs.head == nullptr) {
    return *this;
  }
  Node* nodePtr = rhs.head;
  Node* prevPtr = nullptr;
  while (nodePtr != nullptr) {
    Node* newNode = new Node;
    newNode->data = nodePtr->data;
    newNode->next = nullptr;

    if (prevPtr == nullptr) {
      head = newNode;
    } else {
      prevPtr->next = newNode;
    }
    prevPtr = newNode;
    nodePtr = nodePtr->next;
  }
  return *this;
}
#endif
