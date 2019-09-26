#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n
class Node
{
  public:
    T data;
    Node<T>* prev = NULL;
    Node<T>* next = NULL;

    Node(T);
};

type_n
Node<T>::Node(T elem)
{
  this->data = elem;
};

type_n
class DoublyLinkedList
{
  public:
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    int size = 0;

    void add_last(T);
    int length();
    bool empty();
    void add_at(T, int);
    Node<T>* remove_last();
    Node<T>* remove_at(int);
    void print();
};

type_n
void DoublyLinkedList<T>::add_last(T elem)
{
  if (empty())
    head = tail = new Node<T>(elem);
  else
  {
    tail->next = new Node<T>(elem);
    tail = tail->next;
  }

  size++;
};

type_n
int DoublyLinkedList<T>::length()
{
  return size;
};

type_n
bool DoublyLinkedList<T>::empty()
{
  return length() == 0;
};

type_n
void DoublyLinkedList<T>::add_at(T elem,int pos)
{
  int curr_pos = 1;
  Node<T>* itr = head;
  
  while(curr_pos < pos)
  {
    itr = itr->next;
    curr_pos++;
  };

  Node<T>* new_node = new Node<T>(elem);
  new_node->next = itr->next;
  new_node->prev = itr;
  itr->next->prev = new_node;
  itr->next = new_node;
  size++;
};

type_n
Node<T>* DoublyLinkedList<T>::remove_last()
{
  Node<T>* itr = tail;
  tail->prev->next = NULL;
  tail = tail->prev;
  free(itr);
  size--;
};

type_n
Node<T>* DoublyLinkedList<T>::remove_at(int pos)
{
  int curr_pos = 0;
  Node<T>* itr = head;
  
  while(curr_pos <= pos)
  {
    itr = itr->next;
    curr_pos++;
  };

  itr->prev->next = itr->next;
  itr->next->prev = itr->prev;
  free(itr);
  size--;
};

type_n
void DoublyLinkedList<T>::print()
{
  Node<T>* itr = head;
  while(itr != NULL)
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
  dll.add_at("pqr", 2);
  dll.remove_at(1);
  dll.remove_last();
  dll.print();
  
  return 0;
}