#include "entities/Cards.hpp"
#include "utils/sorts.hpp"

int main() {
  srand(time(0));

  Cards cards;
  Sorts sorts;

  cout << "Pila original: ";
  cards.printCards();
  
  cout << endl;
  
  cout << "Pila ordenada: ";
  cards.printCards();
  return 0;
}