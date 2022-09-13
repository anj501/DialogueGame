#include <iostream>
#include <string>
using namespace std;

#include "game.h"

void game::opener(string& type) {
    if (type == "fire type") {
        this->type = type;
        a.fireopener();
    }
    else if (type == "water type") {
        this->type = type;
        b.wateropener();
    }
    else if (type == "ice type") {
        c.iceopener();
    }
    transferringpoints();
    transferringminus();
    transferringputback();
    transferringname();
}
void game::transferringpoints() {
    if (type == "fire type") {
        this->currpoints = a.score;
    }
    else if (type == "water type") {
        this->currpoints = b.score;
    }
    else {
        this->currpoints = c.score;
    }
}
const int& game::points() const {
    return currpoints;
}
void game::transferringminus() {
    if (type == "fire type") {
        this->currdefense = a.defense;
    }
    else if (type == "water type") {
        this->currdefense = b.defense;
    }
    else{
        this ->currdefense = c.defense;
    }
}
const int& game::minus() const {
    return currdefense;
}
void game::transferringputback() {
    if (type == "fire type") {
        this->currrebound = a.rebound;
    }
    else if (type == "water type") {
        this->currrebound = b.rebound;
    }
    else{
        this->currrebound = c.rebound;
    }
}
const int& game::putback() const {
    return currrebound;
}
void game::transferringname() {
    int i;
    if (type == "fire type") {
        currcharacter = a.character;
        currcharacter.at(0) = toupper(currcharacter.at(0));
        for (i = 1; i < currcharacter.size(); ++i) {
            if ((currcharacter.at(i-1) == ' ') || (currcharacter.at(i-1) == '-')) {
                currcharacter.at(i) = toupper(currcharacter.at(i));
            }
        }
    }
    else if (type == "water type") {
        currcharacter = b.character;
        currcharacter.at(0) = toupper(currcharacter.at(0));
        for (i = 1; i < currcharacter.size(); ++i) {
            if ((currcharacter.at(i-1) == ' ') || (currcharacter.at(i-1) == '-')) {
                currcharacter.at(i) = toupper(currcharacter.at(i));
            }
        }
    }
    else{
        currcharacter = c.character;
        currcharacter.at(0) = toupper(currcharacter.at(0));
        for (i = 1; i < currcharacter.size(); ++i) {
            if ((currcharacter.at(i-1) == ' ') || (currcharacter.at(i-1) == '-')) {
                currcharacter.at(i) = toupper(currcharacter.at(i));
            }
        }
    }
}
const string& game::name() const {
    return currcharacter;
}