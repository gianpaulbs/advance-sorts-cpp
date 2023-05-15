#ifndef __NODE_HPP__
#define __NODE_HPP__
#include "../utils/resources.hpp"

template <class N>
class Node {
  private:
    N element;
    Node<N>* prev;
    Node<N>* next;
    Node(N c) {
      element = c;
      next = nullptr;
      prev = nullptr;
    }

    template<class S> friend class Stack;
  };

#endif