#ifndef __STACK_HPP__
#define __STACK_HPP__
#include "node.hpp"

template <class S>
class Stack {
  private:
    Node<S>* start;
    size_t size;

  public:
    Stack(Node<S>* start = nullptr) :start(start) {
      size = 0;
    }

    void push(S e) {
      Node<S>* _new = new Node<S>(e);
      if (start != nullptr) {
          start->prev = _new;
          _new->next = start;
      }
      start = _new;
      size++;
    }

    void pop() {
      if (start != nullptr) {
          if (size == 1) {
              delete start;
          }
          else {
              start = start->next;
              delete start->prev;
          }

          size--;
      }
    }

    void iterate(function<void(S)> fn) {
      Node<S>* aux = start;

      while (aux != nullptr) {
          fn(aux->element);
          aux = aux->next;
      }
    }

    S peek() {
      if (start != nullptr)
          return start->element;
    }

    size_t getSize() { return size; }
};

#endif