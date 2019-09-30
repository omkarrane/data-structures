#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n class Heap
{
private:
  vector<T> arr;
  int size = 0;

public:
  Heap(int);

  int get_left_child_index(int);
  int get_right_child_index(int);
  int get_parent_index(int);

  bool has_left_child(int);
  bool has_right_child(int);
  bool has_parent(int);

  T get_element_at(int);
  T get_left_child(int);
  T get_right_child(int);
  T get_parent(int);

  void heapify_up();
  void heapify_down();
  T peek();
  T poll();
  void insert(T);
};

type_n
Heap<T>::Heap(int size)
{
  this->size = size;
};

type_n int Heap<T>::get_left_child_index(int index)
{
  if (index == 0)
    throw "Invalid Index Exception";

  return index * 2 + 1;
};

type_n int Heap<T>::get_right_child_index(int index)
{
  if (index == 0)
    throw "Invalid Index Exception";

  return index * 2 + 2;
};

type_n bool Heap<T>::has_left_child(int index)
{
  return get_left_child_index(index) <= size;
};

type_n bool Heap<T>::has_right_child(int index)
{
  return get_right_child_index(index) <= size;
};

type_n T Heap<T>::get_element_at(int index)
{
  if (index > size || index < 0)
    throw "Invalid Index Exception";

  return arr[index];
};

type_n T Heap<T>::get_left_child(int index)
{
  return arr[get_left_child_index(index)];
};

type_n T Heap<T>::get_right_child(int index)
{
  return arr[get_right_child_index(index)];
};

type_n int Heap<T>::get_parent_index(int index)
{
  if (index < 0 || index >= size)
    throw "Invalid Index Exception";

  if (index & 1)
    return (index / 2);
  else
    return (index / 2) - 1;
};

type_n T Heap<T>::get_parent(int index)
{
  return arr[get_parent_index(index)];
};

type_n bool Heap<T>::has_parent(int index)
{
  return get_parent_index(index) > 0;
};

type_n T Heap<T>::peek()
{
  if (size == 0)
    throw "Empty Heap Exception";

  return arr[0];
};

type_n T Heap<T>::poll()
{
  if (size == 0)
    throw "Empty Heap Exception";

  T removed_element = arr[0];
  arr[0] = arr[arr.size() - 1];
  size--;
  heapify_down();
  return removed_element;
};

type_n void Heap<T>::insert(T element)
{
  if(arr.size() > size)
    throw "Heap Full Exception";

  arr.insert(element);
  size++;
  heapify_up();
};

type_n void Heap<T>::heapify_up()
{

};

type_n void Heap<T>::heapify_down()
{

};


int main()
{
  Heap<int> h = Heap<int>(10);
  return 0;
}