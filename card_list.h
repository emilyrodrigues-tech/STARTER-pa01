// card_list.h
// Author: Emily Rodrigues
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <iostream>

class CardBST {
public:
    struct Node {
        Card info;
        Node *left, *right, *parent;
        Node(Card v) : info(v), left(nullptr), right(nullptr), parent(nullptr) { }
    };

    class Iterator {
    public:
        Iterator(Node* n = nullptr) : curr(n) { }
        const Card& operator*() const { return curr->info; }
        bool operator==(const Iterator& other) const { return curr == other.curr; }
        bool operator!=(const Iterator& other) const { return curr != other.curr; }
        
        Iterator& operator++(); 
        Iterator& operator--(); 

    private:
        Node* curr;
    };

    CardBST();
    ~CardBST();

    bool insert(const Card& card);
    bool remove(const Card& card);
    bool contains(const Card& card) const;
    
    Iterator begin() const; 
    Iterator end() const { return Iterator(nullptr); }
    Iterator rbegin() const; 
    Iterator rend() const { return Iterator(nullptr); }

private:
    Node *root;
    void clear(Node *n);
    bool insert(const Card& card, Node *n);
    Node* getNodeFor(const Card& card, Node* n) const;
};

void playGame(CardBST& alice, CardBST& bob);

#endif
