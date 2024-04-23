#ifndef ARRAYLIST_HPP_
#define ARRAYLIST_HPP_
#include <iostream>

using namespace std;

int MAX_SIZE = 100;

template<class T>
class arrayList {
private:
    T* data;
    int capacity;
    int size;

public:
    arrayList();
    ~arrayList();
    void push(const T&);
    T pop();
    T& top() const;
    int getSize() const;
    bool empty() const;
};

template<class T>
arrayList<T>::arrayList(){
  capacity = MAX_SIZE; 
  data = new T[capacity];
  size = 0;
}

template<class T>
arrayList<T>::~arrayList(){
  delete[] data;
  size = 0;
}

template<class T>
void arrayList<T>::push(const T& element){
  if (size == capacity){
    capacity *= 2;
    T* push = new T[capacity];
    for(int i = 0;i < size;i++){
      push[i] = data[i];
    }
    data = push; 
    delete[] data;
  }
  data[size++] = element;
}

template<class T>
bool arrayList<T>::empty() const{
  return (size == 0);
}

template<class T>
T arrayList<T>::pop(){
  if(empty()){
    throw out_of_range("ERROR: ARRAY IS EMPTY!");
  }
  return data[--size];
}

template<class T>
T& arrayList<T>::top() const{
  if(empty()){
    throw out_of_range("ERROR: ARRAY IS EMPTY!");
  }
  return data[size - 1];
}

#endif

