#include <iostream>
#include <string>
using namespace std;
#include "fire.h"
#include "water.h"
#include "ice.h"

#ifndef GAME_H
#define GAME_H

class game : public fire, public water, public ice {
    public:
        void opener(string& currtype);
        const int& points() const;
        void transferringpoints();
        const int& minus() const;
        void transferringminus();
        const int& putback() const;
        void transferringputback();
        const string& name() const;
        void transferringname();
        fire a;
        water b;
        ice c;
    private:
        int currpoints;
        int currdefense;
        int currrebound;
        string currcharacter;
        string type;
};

#endif