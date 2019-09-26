#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n class Node
{
public:
  T data;
  Node<T> *prev = NULL;
  Node<T> *next = NULL;

  Node(T);
};

type_n
Node<T>::Node(T elem)
{
  this->data = elem;
};

type_n class DoublyLinkedList
{
public:
  Node<T> *head = NULL;
  Node<T> *tail = NULL;
  int size = 0;

  void add_first(T);
  void add_last(T);
  void add_at(T, int);
  int length();
  bool empty();
  void remove_first();
  void remove_last();
  void remove_at(int);
  void print();
};

type_n void DoublyLinkedList<T>::add_first(T elem)
{
  if (empty())
  {
    head = tail = new Node<T>(elem);
    head->next = tail;
    tail->prev = head;
  }
  else
  {
    Node<T> *new_node = new Node<T>(elem);
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
  }

  size++;
};

type_n void DoublyLinkedList<T>::add_last(T elem)
{
  if (empty())
  {
    head = tail = new Node<T>(elem);
    head->next = tail;
    tail->prev = head;
  }
  else
  {
    Node<T> *new_node = new Node<T>(elem);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }

  size++;
};

type_n int DoublyLinkedList<T>::length()
{
  return size;
};

type_n bool DoublyLinkedList<T>::empty()
{
  return length() == 0;
};

type_n void DoublyLinkedList<T>::add_at(T elem, int pos)
{
  if(pos == 1)
    return add_first(elem);
  else if(pos == length())
    return add_last(elem);

  int curr_pos = 1;
  Node<T> *itr = head;

  while (curr_pos < pos)
  {
    itr = itr->next;
    curr_pos++;
  };

  Node<T> *new_node = new Node<T>(elem);
  new_node->next = itr->next;
  new_node->prev = itr;
  itr->next->prev = new_node;
  itr->next = new_node;
  size++;
};

type_n void DoublyLinkedList<T>::remove_first()
{
  Node<T> *itr = head;
  head->next->prev = NULL;
  head = head->next;
  free(itr);
  size--;
}

type_n void DoublyLinkedList<T>::remove_last()
{
  Node<T> *itr = tail;
  tail->prev->next = NULL;
  tail = tail->prev;
  free(itr);
  size--;
};

type_n void DoublyLinkedList<T>::remove_at(int pos)
{
  if(pos == 1)
    return remove_first();
  else if(pos == length())
    return remove_last();

  int curr_pos = 1;
  Node<T> *itr = head;

  while (curr_pos < pos)
  {
    itr = itr->next;
    curr_pos++;
  };

  itr->prev->next = itr->next;
  itr->next->prev = itr->prev;
  free(itr);
  size--;
};

type_n void DoublyLinkedList<T>::print()
{
  Node<T> *itr = head;
  while (itr != NULL)
  {
    cout << itr->data << endl;
    itr = itr->next;
  };
};

int main()
{
  DoublyLinkedList<string> dll = DoublyLinkedList<string>();
  dll.add_last("abc");
  dll.add_last("def");
  dll.add_last("xyz");
  dll.add_first("123");
  dll.add_at("pqr", 1);
  dll.remove_at(5);
  dll.remove_last();
  dll.remove_first();
  dll.print();

  return 0;
};