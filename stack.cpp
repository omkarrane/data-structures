#include <bits/stdc++.h>

using namespace std;

#define type_n template <typename T>

type_n class Stack
{
public:
  list<T> arr;

  bool empty();
  T top();
  void push(T);
  T pop();
  int length();
};

type_n bool Stack<T>::empty()
{
  return arr.empty();
};

type_n T Stack<T>::top()
{
  return arr.back();
};

type_n void Stack<T>::push(T elem)
{
  arr.push_back(elem);
};

type_n T Stack<T>::pop()
{
  if(empty())
    throw "Stack Underflow";
  T elem_popped = top();
  arr.pop_back();
  return elem_popped;
};

type_n int Stack<T>::length()
{
  return arr.size();
};

int main()
{
  Stack<int> s = Stack<int>();
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  int len = s.length();
  cout << "Stack top is " << s.top() << endl;
  cout << "Length of stack is " << len;

  cout << endl;

  for(int i = 0; i < len; i++)
  {
    cout << s.pop() << " ";
  };
  
  cout << endl;
  
  return 0;
}