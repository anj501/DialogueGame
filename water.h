#include <iostream>
#include <string>
using namespace std;

#ifndef WATER_H
#define WATER_H

class water {
    public:
        void wateropener();
        void scoring();
        void defending();
        void rebounding();
        int score;
        int defense;
        int rebound;
        string character;
};

#endif