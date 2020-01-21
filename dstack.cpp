
#include <iostream>
#include <cassert>
#include "dstack.h"

//constructor for dstack
Dstack::Dstack () { 
  top = NULL;
} 

//deconstructor for dstack
Dstack::~Dstack () {
  while (top) {
    Node *np = top;
    top = top->next;
    delete np;
  } 
  assert (top == NULL);
}

//int function that returns the stack size 
int Dstack::size () {
  Node *np = top;
  int count = 0;
  while (np) { 
    count++;
    np = np->next;
  } 
  return count;
}  

//is empty function returns true if stack is empty.
bool Dstack::is_empty () { 
  if (top == NULL) 
    return true;

  return false;
}

//pushes a a vale onto the stack by dynamically allocating a new
//node
void Dstack::push (double d) {
  top = new Node (d, top);
} 

//pops a value off the stack and sets the top to next and deletes
//the old top. d is passed by ref and is used in calc.cpp
void Dstack::pop (double &d) { 
  if (top == NULL) 
    return;

  d = top->data;
  Node *np = top;
  top = top->next;
  delete (np);
} 

//did this for fun, sets passed by ref number d1 and d2 
//then it deletes both of those stacks via while loop
void Dstack::pop_two (double &d1, double &d2) { 
  d1 = top->data;
  d2 = top->next->data;
  int count = 2;
  while (count > 0) { 
    Node *np = top;
    top = top->next;
    delete (np);
    count--;
  } 
} 

 
