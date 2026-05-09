#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argc, char** argv) { 
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    ifstream cardFile1(argv[1]);
    ifstream cardFile2(argv[2]);

    if (cardFile1.fail() || cardFile2.fail()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    set<Card> alice_hand;
    set<Card> bob_hand;
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

    bool game_continues = true;
    while (game_continues) {
        game_continues = false;

        for (auto it = alice_hand.begin(); it != alice_hand.end(); ++it) {
            if (bob_hand.count(*it)) { 
                cout << "Alice picked matching card " << *it << endl;
                Card match = *it;
                alice_hand.erase(match);
                bob_hand.erase(match);
                game_continues = true; 
                break; 
            }
        }

        if (!game_continues) break; 

        game_continues = false;
        for (auto it = bob_hand.rbegin(); it != bob_hand.rend(); ++it) {
            if (alice_hand.count(*it)) {
                cout << "Bob picked matching card " << *it << endl;
                Card match = *it;
                alice_hand.erase(match);
                bob_hand.erase(match);
                game_continues = true;
                break; 
            }
        }
    }

    cout << endl << "Alice's cards:" << endl;
    for (const auto& c : alice_hand) cout << c << endl;

    cout << endl << "Bob's cards:" << endl;
    for (const auto& c : bob_hand) cout << c << endl;

    return 0;
}
