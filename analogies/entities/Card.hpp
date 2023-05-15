#ifndef __CARD_HPP__
#define __CARD_HPP__

class Card {
  private: int number;
  public:
    Card() {}
    Card(int number) : number(number) {}

    int getNumber() { return number; }
};

#endif