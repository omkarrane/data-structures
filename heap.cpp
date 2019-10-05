#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n class Heap
{
private:
  vector<T> arr;
  int size = 0;

public:
  Heap();

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
  T remove_at(int);
  void insert(T);
  void swap_elements(int, int);
};

type_n
Heap<T>::Heap()
{
};

type_n int Heap<T>::get_left_child_index(int index)
{
  if (index < 0)
    throw "Invalid Index Exception";

  return index * 2 + 1;
};

type_n int Heap<T>::get_right_child_index(int index)
{
  if (index < 0)
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
  return get_parent_index(index) >= 0;
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
  arr.pop_back();
  size--;
  heapify_down();
  return removed_element;
};

type_n void Heap<T>::insert(T element)
{
  arr.push_back(element);
  size++;
  heapify_up();
};

type_n T Heap<T>::remove_at(int index)
{
  T elem_removed = get_element_at(index);
  swap_elements(index, arr.size() - 1);
  size--;

  T elem = get_element_at(index);
  heapify_down();

  if(elem == get_element_at(index))
    heapify_up();

  return elem_removed;
};

type_n void Heap<T>::heapify_up()
{
  int index = size - 1;
  while(has_parent(index) && get_element_at(index) > get_parent(index))
  {
    swap_elements(index, get_parent_index(index));
    index = get_parent_index(index);
  };
};

type_n void Heap<T>::heapify_down()
{
  int index = 0;
  while(has_left_child(index))
  {
    int smallest_child_index = get_left_child_index(index);

    if(has_right_child(index) && get_element_at(smallest_child_index) > get_right_child(index) && get_element_at(index) > get_right_child(index))
      smallest_child_index = get_right_child_index(index);

    if(get_element_at(smallest_child_index) > get_element_at(index))
    {
      swap_elements(index, smallest_child_index);
      index = smallest_child_index;
    }
    else
      break;
  }
};

type_n void Heap<T>::swap_elements(int pos1, int pos2)
{
  T temp_elem = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp_elem;
};


int main()
{
  Heap<int> h = Heap<int>();
  h.insert(15);
  h.insert(10);
  h.insert(20);
  h.insert(17);
  h.insert(25);
  cout << h.poll() << endl;
  h.insert(50);
  cout << h.poll() << endl;
  cout << h.poll() << endl;
  cout << h.poll() << endl;
  cout << h.remove_at(0) << endl;


  return 0;
}



/*
      15
      
      15
    10

      15        20
    10  20    10  15

      20        20
    10  15    17  15
  17        10  

      20        20         25
    17  15    25  15     20   15
  10  25    10  17      10  17
*/