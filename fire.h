#include <iostream>
#include <string>
using namespace std;

#ifndef FIRE_H
#define FIRE_H

class fire {
    public:
        void fireopener();
        void scoring();
        void defending();
        void rebounding();
        int score;
        int defense;
        int rebound;
        string character;
};

#endif