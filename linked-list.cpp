#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

class Node
{
  public:
    int data;
    Node *prev;
    Node *next;

    Node(int, Node*, Node*);
};

Node::Node(int elem, Node* prev = NULL, Node* next = NULL)
{
  this->data = elem;
  this->prev = prev;
  this->next = next;
}

class DoublyLinkedList
{
  public:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

    void add_last(int elem);
    int length();
    bool empty();
};

void DoublyLinkedList::add_last(int elem)
{
  Node* temp_node = new Node(elem);
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

int DoublyLinkedList::length()
{
  return size;
};

bool DoublyLinkedList::empty()
{
  return length() == 0;
};

int main()
{
  DoublyLinkedList dll = DoublyLinkedList();
  dll.add_last(5);
  dll.add_last(6);
  cout << "Length -> " << dll.length();
  return 0;
}