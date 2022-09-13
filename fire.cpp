#include <iostream>
#include <string>
using namespace std;

#include "fire.h"

void fire::fireopener() {
    int i;
    cout << "Which character would you like to choose" << endl;
    cout << "Fire Scorer" << endl;
    cout << "Scoring rating: 100, Defending Rating: 50, Rebounding Rating: 75 " << endl;
    cout << "Fire Defender" << endl;
    cout << "Scoring Rating: 50, Defending Rating: 100, Rebounding Rating: 75" << endl;
    cout << "Fire All-Around" << endl;
    cout << "Scoring Rating: 75, Defending Rating: 75, Rebounding Rating: 75" << endl;
    getline (cin, character);
    for (i = 0; i < character.size(); ++i) {
        character.at(i) = tolower(character.at(i));
    }
    while ((character != "fire scorer") && (character != "fire defender") && (character != "fire all-around")) {
        cout << "Please enter 'Fire Scorer', 'Fire Defender', or 'Fire All-Around" << endl;
        getline (cin, character);
        for (i = 0; i < character.size(); ++i) {
            character.at(i) = tolower(character.at(i));
        }
    }
    character.at(0) = toupper(character.at(0));
    for (i = 1; i < character.size(); ++i) {
        if ((character.at(i-1) == ' ') || (character.at(i-1) == '-')) {
            character.at(i) = toupper(character.at(i));
        }
    }
    cout << character << " was chosen" << endl;
    for (i = 0; i < character.size(); ++i) {
        character.at(i) = tolower(character.at(i));
    }
    scoring();
    defending();
    rebounding();
}
void fire::scoring() {
    if (character == "fire scorer") {
        srand(time(nullptr));
        score = 8 + (rand() % 3);
    }
    else if (character == "fire defender") {
        srand(time(nullptr));
        score = 5 + (rand() % 3);
    }
    else if (character == "fire all-around") {
        srand(time(nullptr));
        score = 4 + (rand() % 3);
    }
}

void fire::defending() {
    if (character == "fire scorer") {
        srand(time(nullptr));
        defense = 1 + (rand() % 3);
    }
    else if (character == "fire defender") {
        srand(time(nullptr));
        defense = 3 + (rand() % 3);
    }
    else if (character == "fire all-around") {
        srand(time(nullptr));
        defense = 4 + (rand() % 3);
    }
}

void fire::rebounding() {
    srand(time(nullptr));
    rebound = 1 + (rand() % 4);
}