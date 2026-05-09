// card_list.h
// Author: Emily Rodrigues
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include "card.h"
#include <iostream>

class CardBST {
public:
    CardBST();
    ~CardBST();

    bool insert(const Card& card);
    bool remove(const Card& card);
    bool contains(const Card& card) const;
    void printInOrder() const;

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
        Node* getSuccessor(Node* n);
        Node* getPredecessor(Node* n);
    };

    Iterator begin() const;  
    Iterator end() const;    
    Iterator rbegin() const; 
    Iterator rend() const;   

private:
    Node *root;
    void clear(Node *n);
};

#endif
