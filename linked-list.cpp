#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n
class Node
{
  T data = NULL;
  Node *prev;
  Node *next;
};



type_n
class DoublyLinkedList
{
  Node<T> *head;
  Node<T> *tail;
  int size;

  DoublyLinkedList();
  DoublyLinkedList(T data);
};

type_n
DoublyLinkedList<T>::DoublyLinkedList()
{
  this->head = this->tail = NULL;
  this->size = 0;
};

type_n
DoublyLinkedList<T>::DoublyLinkedList(T data)
{
  Node<T> temp_node = new Node();
  temp_node.data = data;
  temp_node.next = NULL;
  temp_node.prev = NULL;
  this->head = temp_node;
  this->tail = temp_node;
  size = 1;
};


int main()
{
  return 0;
}