// card.cpp
// Author: Emily Rodrigues
// Implementation of the classes defined in card.h

#include "card.h"

int Card::suitWeight() const {
  if (suit == 'c') return 1;
  if (suit == 'd') return 2;
  if (suit == 's') return 3;
  if (suit == 'h') return 4;
  return 0;
}

int Card::valueWeight() const {
    if (value == "a") return 1;
    if (value == "j") return 11;
    if (value == "q") return 12;
    if (value == "k") return 13;
    return std::stoi(value); 
}

bool Card::operator<(const Card& other) const {
    if (this->suitWeight() != other.suitWeight()) {
        return this->suitWeight() < other.suitWeight();
    }
    return this->valueWeight() < other.valueWeight();
}

bool Card::operator==(const Card& other) const {
    return (suit == other.suit && value == other.value);
}
