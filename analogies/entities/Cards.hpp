#ifndef __CARDS_HPP__
#define __CARDS_HPP__

#include "../data-structures/stack.hpp"
#include "Card.hpp"

class Cards {
  private: Stack<Card> cards;
  public:
    Cards() {
      for (size_t i = 0; i < 10; i++) {
          cards.push(Card(rand() % 50));
      }
    }
    
    void printCards() {
      cards.iterate([](Card c) {
        cout << c.getNumber() << " ";
      });
    }

    Stack<Card> getCards() { return cards; }
};

#endif