// card_list.cpp
// Author: Emily Rodrigues
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include <iostream>

using namespace std;

CardBST::CardBST() : root(nullptr) {}

CardBST::~CardBST() { clear(root); }

void CardBST::clear(Node *n) {
    if (!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

bool CardBST::insert(const Card& card) {
    if (!root) {
        root = new Node(card);
        return true;
    }
    return insert(card, root);
}

bool CardBST::insert(const Card& card, Node *n) {
    if (card == n->info) return false;
    if (card < n->info) {
        if (!n->left) {
            n->left = new Node(card);
            n->left->parent = n;
            return true;
        }
        return insert(card, n->left);
    } else {
        if (!n->right) {
            n->right = new Node(card);
            n->right->parent = n;
            return true;
        }
        return insert(card, n->right);
    }
}

bool CardBST::contains(const Card& card) const {
    return getNodeFor(card, root) != nullptr;
}

CardBST::Node* CardBST::getNodeFor(const Card& card, Node* n) const {
    if (!n) return nullptr;
    if (card == n->info) return n;
    if (card < n->info) return getNodeFor(card, n->left);
    return getNodeFor(card, n->right);
}


CardBST::Iterator& CardBST::Iterator::operator++() {
    if (!curr) return *this;
    if (curr->right) {
        curr = curr->right;
        while (curr->left) curr = curr->left;
    } else {
        Node* p = curr->parent;
        while (p && curr == p->right) {
            curr = p;
            p = p->parent;
        }
        curr = p;
    }
    return *this;
}

CardBST::Iterator& CardBST::Iterator::operator--() {
    if (!curr) return *this;
    if (curr->left) {
        curr = curr->left;
        while (curr->right) curr = curr->right;
    } else {
        Node* p = curr->parent;
        while (p && curr == p->left) {
            curr = p;
            p = p->parent;
        }
        curr = p;
    }
    return *this;
}

CardBST::Iterator CardBST::begin() const {
    if (!root) return end();
    Node* n = root;
    while (n->left) n = n->left;
    return Iterator(n);
}

CardBST::Iterator CardBST::rbegin() const {
    if (!root) return rend();
    Node* n = root;
    while (n->right) n = n->right;
    return Iterator(n);
}


bool CardBST::remove(const Card& card) {
    Node* n = getNodeFor(card, root);
    if (!n) return false;

    if (!n->left || !n->right) {
        Node* child = (n->left) ? n->left : n->right;
        if (n == root) {
            root = child;
            if (child) child->parent = nullptr;
        } else {
            if (n == n->parent->left) n->parent->left = child;
            else n->parent->right = child;
            if (child) child->parent = n->parent;
        }
        delete n;
    } 
    else {
        Node* successor = n->right;
        while (successor->left) successor = successor->left;
        
        Card temp = successor->info;
        remove(temp); 
        n->info = temp; 
    }
    return true;
}


void playGame(CardBST& alice, CardBST& bob) {
    bool found = true;
    while (found) {
        found = false;
        for (auto it = alice.begin(); it != alice.end(); ++it) {
            if (bob.contains(*it)) {
                cout << "Alice picked matching card " << *it << endl;
                Card match = *it;
                alice.remove(match);
                bob.remove(match);
                found = true;
                break;
            }
        }
        if (!found) break;

        found = false;
        for (auto it = bob.rbegin(); it != bob.rend(); --it) {
            if (alice.contains(*it)) {
                cout << "Bob picked matching card " << *it << endl;
                Card match = *it;
                alice.remove(match);
                bob.remove(match);
                found = true;
                break;
            }
        }
    }
}


