//program 4
//sundsbarm, bradley
//bsundsbarm
#ifndef DSTACK_H_
#define DSTACK_H_

#include <iostream>

class Dstack { 
  public:
    Dstack ();
    ~Dstack ();
    void push (double d);
    void pop_two (double &d1, double &d2);
    bool is_empty ();
    int size ();
    void pop (double &d);
  private:
    class Node { 
      public:
        double data;
        Node *next;
        Node (double d, Node *n) {
          data = d; next = n;
        } 
    };
    Node *top;
};

#endif
