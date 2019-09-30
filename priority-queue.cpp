#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n class Heap
{
private:
  T arr[];
  int size = 0;

public:
  Heap(int);
  int get_left_child_index(int);
  int get_right_child_index(int);
  bool has_left_child(int);
  bool has_right_child(int);
  T get_element_at(int);
  T get_left_child(int);
  T get_right_child(int);
  int get_parent_index(int);
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
  return ((index * 2) + 1) <= size;
};

type_n bool Heap<T>::has_right_child(int index)
{
  return ((index * 2) + 2) <= size;
};

type_n
    T
    Heap<T>::get_element_at(int index)
{
  if (index > size || index < 0)
    throw "Invalid Index Exception";

  return arr[index];
};

type_n
    T
    Heap<T>::get_left_child(int index)
{
  return arr[get_left_child_index(index)];
};

type_n
    T
    Heap<T>::get_right_child(int index)
{
  return arr[get_right_child_index(index)];
};

type_n int Heap<T>::get_parent_index(int index)
{
  if (index < 0 || index >= size)
    throw "Invalid Index Exception";

  return 0; // TODO: Implement logic for finding parent index
};

int main()
{
  Heap<int> h = Heap<int>(10);
  return 0;
}