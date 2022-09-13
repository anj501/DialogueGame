#include <iostream>
#include <string>
using namespace std;

#ifndef ICE_H
#define ICE_H

class ice {
    public:
        void iceopener();
        void scoring();
        void defending();
        void rebounding();
        int score;
        int defense;
        int rebound;
        string character;
};

#endif