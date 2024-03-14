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
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;  // Don't forget to update head pointer
}

// template <class T>
// void linkedlist<T>::clearList() {
//   Node* nodePtr = head;
//   Node* nextNode = nullptr;
//   while (nodePtr != nullptr) {
//     nextNode = nodePtr->next;
//     delete nodePtr;
//     nodePtr = nextNode;
//   }
//   head = nullptr;
//   size = 0;
// }
//
template <class T>
void linkedlist<T>::insertAt(int index, T element) {
  if (index < 0 || index > size) {
    throw std::out_of_range(
        "INVALID INSERTION: INDEX or OUT OF RANGE PARAMETERS!");
  }
  if (isFull()) {
    throw std::out_of_range("INVALID: Target is full!");
  }

  Node* newNode = new Node;
  newNode->data = element;
  newNode->next = nullptr;

  if (isEmpty() || index == 0) {
    newNode->next = head;
    head = newNode;
    size++;
    return;
  }

  Node* nodePtr = head;
  for (int i = 0; i < index - 1; i++) {
    nodePtr = nodePtr->next;
  }
  newNode->next = nodePtr->next;
  nodePtr->next = newNode;
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

template <class T>
linkedlist<T>& linkedlist<T>::operator=(const linkedlist<T>& rhs) {
  // Check for self-assignment
  if (this == &rhs) {
    return *this;
  }

  // Clear the existing list
  clearList();

  // Copy the size and max_size from rhs
  size = rhs.size;
  max_size = rhs.max_size;

  // If rhs is empty, just return
  if (rhs.head == nullptr) {
    return *this;
  }

  // Copy nodes from rhs
  Node* rhsNodePtr = rhs.head;
  Node* prevPtr = nullptr;
  while (rhsNodePtr != nullptr) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = rhsNodePtr->data;
    newNode->next = nullptr;

    // If this is the first node being added
    if (prevPtr == nullptr) {
      head = newNode;
    } else {
      prevPtr->next = newNode;
    }

    // Move pointers forward
    prevPtr = newNode;
    rhsNodePtr = rhsNodePtr->next;
  }

  return *this;
}

// template <class T>
// linkedlist<T>& linkedlist<T>::operator=(const linkedlist<T>& rhs) {
//   Node* newNode = new Node;
//   Node* nodePtr = rhs.head;
//   Node* prevPtr = nullptr;
//   if (head != nullptr) {
//     clearList();
//     size = rhs.size;
//     max_size = rhs.max_size;
//     while (nodePtr != nullptr) {
//       newNode->data = nodePtr->data;
//       newNode->next = nullptr;
//       if (prevPtr == nullptr) {
//         head = newNode;
//       } else {
//         prevPtr->next = newNode;
//       }
//       prevPtr = newNode;
//       nodePtr = nodePtr->next;
//     }
//   }
//   return *this;
// }
#endif
