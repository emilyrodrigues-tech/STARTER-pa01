// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    ifstream cardFile1(argv[1]);
    ifstream cardFile2(argv[2]);

    if (cardFile1.fail() || cardFile2.fail()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    CardBST alice_hand;
    CardBST bob_hand;
    char suit;
    string value;

    while (cardFile1 >> suit >> value) {
        alice_hand.insert(Card(suit, value));
    }
    cardFile1.close();

    while (cardFile2 >> suit >> value) {
        bob_hand.insert(Card(suit, value));
    }
    cardFile2.close();

    playGame(alice_hand, bob_hand);

    cout << endl << "Alice's cards:" << endl;
    for (auto it = alice_hand.begin(); it != alice_hand.end(); ++it) {
        cout << *it << endl;
    }

    cout << endl << "Bob's cards:" << endl;
    for (auto it = bob_hand.begin(); it != bob_hand.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
