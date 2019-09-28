#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n class Queue
{
  private:
    list<T> arr;

  public:
    void enqueue(T elem);
    T dequeue();
    int length();
    T peek();
    bool empty();
};

type_n void Queue<T>::enqueue(T elem)
{
  arr.push_back(elem);
};

type_n T Queue<T>::dequeue()
{
  if(empty())
    throw "Queue Underflow";
  
  T elem_dequeued = arr.front();
  arr.pop_front();
  return elem_dequeued;
};

type_n int Queue<T>::length()
{
  return arr.size();
};

type_n T Queue<T>::peek()
{
  return arr.front();
};

type_n bool Queue<T>::empty()
{
  return arr.empty();
};


int main()
{
  Queue<int> q = Queue<int>();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);

  int len = q.length();
  cout << "First Element to be removed is " << q.peek() << endl;
  cout << "Length of the queue is " << len << endl;

  while(!q.empty())
  {
    cout << q.dequeue() << " ";
  };
  cout << endl;

  return 0;
}