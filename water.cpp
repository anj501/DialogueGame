#include <iostream>
#include <string>
using namespace std;

#include "water.h"

void water::wateropener() {
    int i;
    cout << "Which character would you like to choose" << endl;
    cout << "Water Scorer" << endl;
    cout << "Scoring rating: 100, Defending Rating: 50, Rebounding Rating: 75 " << endl;
    cout << "Water Defender" << endl;
    cout << "Scoring Rating: 50, Defending Rating: 100, Rebounding Rating: 75" << endl;
    cout << "Water All-Around" << endl;
    cout << "Scoring Rating: 75, Defending Rating: 75, Rebounding Rating: 75" << endl;
    getline (cin, character);
    for (i = 0; i < character.size(); ++i) {
        character.at(i) = tolower(character.at(i));
    }
    while ((character != "water scorer") && (character != "water defender") && (character != "water all-around")) {
        cout << "Please enter 'Water Scorer', 'Water Defender', or 'Water All-Around'" << endl;
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
void water::scoring() {
    if (character == "water scorer") {
        srand(time(nullptr));
        score = 8 + (rand() % 3); 
    }
    else if (character == "water defender") {
        srand(time(nullptr));
        score = 5 + (rand() % 3); 
    }
    else if (character == "water all-around") {
        srand(time(nullptr));
        score = 4 + (rand() % 3); 
    }
}

void water::defending() {
    if (character == "water scorer") {
        srand(time(nullptr));
        defense = 1 + (rand() % 3);
    }
    else if (character == "water defender") {
        srand(time(nullptr));
        defense = 3 + (rand() % 3);
    }
    else if (character == "water all-around") {
        srand(time(nullptr));
        defense = 4 + (rand() % 3);
    }
}

void water::rebounding() {
    srand(time(nullptr));
    rebound = 1 + (rand() % 4);
}