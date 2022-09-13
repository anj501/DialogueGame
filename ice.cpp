#include <iostream>
#include <string>
using namespace std;

#include "ice.h"

void ice::iceopener() {
    int i;
    cout << "Which character would you like to choose" << endl;
    cout << "Ice Scorer" << endl;
    cout << "Scoring rating: 100, Defending Rating: 50, Rebounding Rating: 75 " << endl;
    cout << "Ice Defender" << endl;
    cout << "Scoring Rating: 50, Defending Rating: 100, Rebounding Rating: 75" << endl;
    cout << "Ice All-Around" << endl;
    cout << "Scoring Rating: 75, Defending Rating: 75, Rebounding Rating: 75" << endl;
    getline (cin, character);
    for (i = 0; i < character.size(); ++i) {
        character.at(i) = tolower(character.at(i));
    }
    while ((character != "ice scorer") && (character != "ice defender") && (character != "ice all-around")) {
        cout << "Please enter 'Ice Scorer', 'Ice Defender', or 'Ice All-Around'" << endl;
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
void ice::scoring() {
    if (character == "ice scorer") {
        srand(time(nullptr));
        score = 8 + (rand() % 3); 
    }
    else if (character == "ice defender") {
        srand(time(nullptr));
        score = 5 + (rand() % 3); 
    }
    else if (character == "ice all-around") {
        srand(time(nullptr));
        score = 4 + (rand() % 3); 
    }
}

void ice::defending() {
    if (character == "ice scorer") {
        srand(time(nullptr));
        defense = 1 + (rand() % 3);
    }
    else if (character == "ice defender") {
        srand(time(nullptr));
        defense = 3 + (rand() % 3);
    }
    else if (character == "ice all-around") {
        srand(time(nullptr));
        defense = 4 + (rand() % 3);
    }
}

void ice::rebounding() {
    srand(time(nullptr));
    rebound = 1 + (rand() % 4);
}