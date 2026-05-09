// card.h
// Author: Emily Rodirgues
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
public: 
  Card(char suit, std::string value);

  bool operator<(const Card& other) const;
  bool operator==(const Card& other) const;
  bool operator>(const Card& other) const;

  friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
  char suit;
  std::string value;

  int suiteWeight() const;
  int valueWeight() const;

};
  
#endif
