#ifndef ARRAYLIST_HPP_
#define ARRAYLIST_HPP_

#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

template <class T>
class arrayList {
private:
  // I've thought about using these member variables
  // int element;
  // int array[];
  T* array;
  int size;
  int capacity;

public:
  arrayList();
  arrayList(const T&);
  ~arrayList();
  bool isEmpty() const;
  bool isFull() const;
  int listSize() const;
  int maxListSize() const;
  void print();
  bool isItemAtEqual(int, const T&) const;
  void insertAt(int, const T&);
  void insertEnd(const T&);
  void removeAt(int);
  T retrieveAt(int) const;
  void replaceAt(int, const T&);
  void clearList();
  arrayList<T>& operator=(const arrayList<T>&);
};

template <class T>
// Default Constructor
arrayList<T>::arrayList(const T& capacity_) {
  if (capacity_ < MAX_SIZE) {
    capacity = capacity_;
  }
  size = 0;
  array = new T[capacity];
}

template <class T>
arrayList<T>::~arrayList() {
  delete[] array;
}

template <class T>
bool arrayList<T>::isEmpty() const {
  return size == 0;
}

template <class T>
bool arrayList<T>::isFull() const {
  return size == capacity;
}

template <class T>
int arrayList<T>::listSize() const {
  return size;
}

template <class T>
int arrayList<T>::maxListSize() const {
  return capacity;
}

template <class T>
void arrayList<T>::print() {
  for (int i = 0; i < size; i++) {
    cout << "Index " << i << " = " << array[i] << endl;
  }
  cout << endl;
}

template <class T>
bool arrayList<T>::isItemAtEqual(int index, const T& element) const {
  // Checks to see if index is positive number or within overall size of array
  if (index < 0 || index >= size) {
    throw out_of_range("Out of Range Equal Assertion!");
  }
  return array[index] == element;
}

template <class T>
void arrayList<T>::insertAt(int index, const T& element) {
  if (index < 0 || index >= size) {
    throw out_of_range("Out of range Insertion!");
  }
  if (this->isFull()) {
    throw out_of_range("At capacity, can not insert");
  }
  for (int i = size; i > index; i--) {
    array[i] = array[i - 1];
  }
  array[index] = element;
  size++;
}

template <class T>
void arrayList<T>::insertEnd(const T& element) {
  if (this->isFull()) {
    throw out_of_range("At capacity, can not insert");
  }
  if (size < capacity) {
    array[size++] = element;
  }
}

template <class T>
void arrayList<T>::removeAt(int index) {
  if (index < 0 || index >= size) {
    throw out_of_range("Out of Range Removal!");
  }
  for (int i = index; i > size - 1; i++) {
    array[i] = array[i + 1];
  }
  size--;
}

template <class T>
T arrayList<T>::retrieveAt(int index) const {
  if (index < 0 || index >= size) {
    throw out_of_range("Out of Range Retrieval!");
  }
  return array[index];
}

template <class T>
void arrayList<T>::replaceAt(int index, const T& element) {
  if (index < 0 || index >= size) {
    throw out_of_range("Out of Range Replacement!");
  }
  array[index] = element;
}

template <class T>
void arrayList<T>::clearList() {
  size = 0;
  cout << "List was cleared!\n";
}

template <class T>
arrayList<T>& arrayList<T>::operator=(const arrayList<T>& rhs) {
  // Checks if array is not equal first, if it is not the same, replace it
  // 100%
  if (this != &rhs) {
    delete[] array;
    this->size = rhs.size;
    this->capacity = rhs.capacity;
    array = new T[capacity];
    for (int i = 0; i < size; i++) {
      array[i] = rhs.array[i];
    }
  }
  return *this;
}
#endif
