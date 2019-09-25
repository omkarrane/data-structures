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

    void add_last(T elem);
    int length();
    bool empty();
};

type_n
void DoublyLinkedList<T>::add_last(T elem)
{
  Node<T>* temp_node = new Node<T>(elem);
  if (empty())
    head = tail = temp_node;
  else
  {
    tail->next = temp_node;
    tail = tail->next;
  }

  size++;
  free(temp_node);
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

int main()
{
  DoublyLinkedList<string> dll = DoublyLinkedList<string>();
  dll.add_last("abc");
  dll.add_last("def");
  cout << "Length -> " << dll.length();
  return 0;
}