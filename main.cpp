#include <iostream>
#include <string>
using namespace std;

#include "game.h"
#include "fire.h"
#include "ice.h"
#include "water.h"

void characters(string& type);
void challenger(string& team);
void offense(game a, game b, int& ascore, int& bscore, int& helper);
void reboundpreference(game player, bool& gotrebound, int& helper);
void defendingpreference(game player, int& helper);
void normal(game a, game b, int& ascore, int& bscore, int& helper);
void gettingrebound(game player, game opposition, bool& gotrebound, int& helper);

int main() {
    string type;
    string team;
    string input;
    string inputhelper;
    int i;
    game a;
    game b;
    while ((input != "exit") && (inputhelper != "exit")) {
        if ((input != "challenge") && (input != "switch")) {
            cout << "Welcome to 1 v 1 BallSport Game" << endl;
            cout << "Important game features:" << endl;
            cout << "- There are three different types of ballers (fire, water, and ice) with some being effective against others";
            cout << endl;
            cout << "- There are different styles of ballers (scorer, defender, and all-arounder) within the types and they " << endl;
            cout << "  specialize in their strengths." << endl;
            cout << "- Scoring (every character will score unless they cannot obtain a rebound) adds points to your score," << endl;
            cout << "  choosing defensive preference will allow you take away points from your opponent's score, and" << endl;
            cout << "  a rebounding preference will secure a posession for you after you defend" << endl;
            cout << "  (the competitor will be asked if they would like a defensive or rebounding preference)" << endl;
            cout << " -There will be times where the dialogue may be long if a competitor is unable to grab a rebound. You can";
            cout << endl;
            cout << "  either choose to read the entire dialogue or look at the current score and proceed with the game." << endl;
            cout << " -The game will go on until a team reaches 20 points" << endl;
            cout << " -Even if a competitor secures a possession with a rebound, if the opposition scores over 20, the game " << endl; 
            cout << "  will end" << endl;
            cout << "Enter any character (example: a) to complete a game or enter 'exit' to leave game" << endl;
            getline (cin, inputhelper);
            for (i = 0; i < inputhelper.size(); ++i) {
                inputhelper.at(i) = tolower(inputhelper.at(i));
            }
        }
        if (inputhelper != "exit") {
            if (input != "challenge") {
            characters(type);
            a.opener(type);
            }
            challenger(team);
            b.opener(team);
            bool helper;
            string reply;

            cout << "Would you like to start the challenge?" << endl;
            getline (cin, reply);
            for (i = 0; i < reply.size(); ++i) {
                reply.at(i) = tolower(reply.at(i));
            }
            while ((reply != "yes") && (reply != "no")) {
                cout << "Please reply with a 'yes' or 'no'" << endl;
                getline (cin, reply);
                for (i = 0; i < reply.size(); ++i) {
                    reply.at(i) = tolower(reply.at(i));
                }
            }
            if (reply == "yes") {
                int ascore = 0;
                int bscore = 0;
                int ballstart;
                bool gotrebound = true;
                cout << "Game starting..." << endl;
                cout << "The referee decides the ball with start with..." << endl;
                srand(time(nullptr));
                ballstart = 1 + (rand() % 2);
                if (ballstart == 1) {
                    string holder = a.name();
                    cout << holder << endl;
                }
                else if (ballstart == 2) {
                    string bholder = b.name();
                    cout << bholder << endl;
                }
                while ((ascore < 20) && (bscore < 20)) {
                    int helper = 0;
                    if (ballstart == 1) {
                        srand(time(nullptr));
                        int opponentpreference = 1 + (rand() % 2);
                        if (opponentpreference == 1) {
                            helper = 1;
                            reboundpreference(b, gotrebound, helper);
                            offense(a, b, ascore, bscore, helper);
                        }
                        else if (opponentpreference == 2) {
                            helper = 1;
                            defendingpreference(b, helper);
                            normal(a, b, ascore, bscore, helper);
                            gettingrebound(b, a, gotrebound, helper);
                        }
                        if (gotrebound) {
                            ballstart = 2;
                        }
                        else {
                            ballstart = 1;
                        }
                    }
                    else {
                        cout << b.name() << " is about to be on offense. Do you want to set a defending preference or rebounding "; 
                        cout << "preference?" << endl;
                        getline (cin, reply);
                        for (i = 0; i < reply.size(); ++i) {
                            reply.at(i) = tolower(reply.at(i));
                        }
                        while ((reply != "rebounding") && (reply != "defending")) {
                            cout << "Please choose a preference by replying with 'rebounding' or 'defending'" << endl;
                            getline (cin, reply);
                            for (i = 0; i < reply.size(); ++i) {
                                reply.at(i) = tolower(reply.at(i));
                            }
                        }
                        if (reply == "rebounding") {
                            helper = 2;
                            reboundpreference(a, gotrebound, helper);
                            offense(a, b, ascore, bscore, helper);
                        }
                        else if (reply == "defending") {
                            helper = 2;
                            defendingpreference(a, helper);
                            normal(a, b, ascore, bscore, helper);
                            gettingrebound(a, b, gotrebound, helper);
                        }
                        if (gotrebound) {
                            ballstart = 1;
                        }
                        else {
                            ballstart = 2;
                        }
                    }
                }
                cout << "If you would like to challenge another team enter 'challenge'" << endl;
                cout << "If you would like to switch your baller and challenger enter 'switch'" << endl;
                cout << "If you would like to leave the game enter 'exit'" << endl;
                getline (cin, input);
                for (i = 0; i < input.size(); ++i) {
                    input.at(i) = tolower(input.at(i));
                }
                while ((input != "challenge") && (input != "switch") && (input != "exit")) {
                    cout << "Please enter 'challenge', 'switch', or 'exit'" << endl;
                    getline (cin, input);
                    for (i = 0; i < input.size(); ++i) {
                        input.at(i) = tolower(input.at(i));
                    }
                }
            }
        }
    }
    return 0;
}

void characters(string& type) {
    int i;
    cout << "Which type would you like to choose?" << endl;
    cout << "Fire Type" << endl;
    cout << "-Effective against Ice Players" << endl;
    cout << "Ice Type" << endl;
    cout << "-Effective against Water Players" << endl;
    cout << "Water Type" << endl;
    cout << "-Effective against Fire PLayers" << endl;
    getline (cin, type);
    for (i = 0; i < type.size(); ++i) {
        type.at(i) = tolower(type.at(i));
    }
    while ((type != "fire type") && (type != "ice type") && (type != "water type")) {
        cout << "Please reply with 'Fire Type', 'Ice Type', or 'Water Type'" << endl;
        getline (cin, type);
        for (i = 0; i < type.size(); ++i) {
            type.at(i) = tolower(type.at(i));
        }
    }
}
void challenger(string& team) {
    int i;
    string a = "assisters";
    string s = "sramblers";
    string d = "dribblers";
    cout << "What team would you like to challenge" << endl;
    cout << "Teams available: " << endl;
    cout << "-Assisters" << endl;
    cout << "-Scramblers" << endl;
    cout << "-Dribblers" << endl;
    getline (cin, team);
    for (i = 0; i < team.size(); ++i) {
        team.at(i) = tolower(team.at(i));
    }
    while ((team != "assisters") && (team != "scramblers") && (team != "dribblers")) {
        cout << "Please reply with 'Assisters', 'Scramblers', and 'Dribblers'" << endl;
        getline (cin, team);
        for (i = 0; i < team.size(); ++i) {
            team.at(i) = tolower(team.at(i));
        }
    }
    cout << "You have chosen to challenge the " << team << endl;
    srand(time(nullptr));
    int decider = 1 + (rand() % 3);
    if (decider == 1) {
        a = "fire type";
        s = "ice type";
        d = "water type";
    }
    else if (decider == 2) {
        a = "ice type";
        s = "water type";
        d = "fire type";
    }
    else {
        a = "water type";
        s = "fire type";
        d = "ice type";
    }
    
    if (team == "assisters") {
        team = a;
    }
    else if (team == "scramblers") {
        team = s;
    }
    else {
        team = d;
    }
    cout << "This team consists of ballers that are " << team << endl;
}
void offense(game a, game b, int& ascore, int& bscore, int& helper) {
    if (helper == 1) {
        cout << a.name() << " (chosen player) scores " << a.points() << " point(s)" << endl;
        ascore = ascore + a.points();
        if ((((a.name()).at(0) == 'F') && ((b.name()).at(0) == 'W')) || (((a.name()).at(0) == 'I') && ((b.name()).at(0) == 'F')) ||
            (((a.name()).at(0) == 'W') && ((b.name()).at(0) == 'I'))) {
                ascore = ascore - 1;
                cout << "The scoring ability of " << a.name() << " (chosen player) was not as effective against " << endl;
                cout << b.name() << "'s type" << endl;
                cout << "One point will be subtracted from " << a.name() << "'s score because of this" << endl;
            }
    }
    else {
        cout << b.name() << " scores " << b.points() << " point(s)" << endl;
        bscore = bscore + b.points();
        if ((((b.name()).at(0) == 'F') && ((a.name()).at(0) == 'W')) || (((b.name()).at(0) == 'I') && ((a.name()).at(0) == 'F')) ||
            (((b.name()).at(0) == 'W') && ((a.name()).at(0) == 'I'))) {
                bscore = bscore - 1;
                cout << "The scoring ability of " << b.name() << " was not as effective against " << endl;
                cout << "the type of " << a.name() << " (chosen player)" << endl;
                cout << "One point will be subtracted from " << b.name() << "'s score because of this" << endl;
            }
    }
    cout << "The score is " << ascore << " for " << a.name() << " (chosen player) and " << bscore << " for " << b.name() << endl;
    cout << endl;
}
void reboundpreference(game player, bool& gotrebound, int& helper) {
    if (helper == 1) {
        cout << player.name() << " has chosen the rebounding preference and has secured a posession after the current "; 
        cout << "possesion" << endl;
    }
    else if (helper == 2) {
        cout << player.name() << " (chosen player) has chosen the rebounding preference and has secured a posession after the current"; 
        cout << " possesion" << endl;
    }
    cout << endl;
    gotrebound = true;
}
void defendingpreference(game player, int& helper) {
    if (helper == 1) {
        cout << player.name() << " has chosen the defending preference" << endl;
    }
    else if (helper == 2) {
        cout << player.name() << " (chosen player) has chosen the defending preference" << endl;
    }
    cout << endl;
}
void normal(game a, game b, int& ascore, int& bscore, int& helper) {
    int currpoints;
    if (helper == 1) {
        currpoints = a.points() - b.minus();
        ascore = currpoints;
        cout << a.name() << " (chosen player) scores " << a.points() << ", but " << b.minus() << " point(s) were taken away because " <<
        "of the defense by " << b.name() << endl;
        if ((((a.name()).at(0) == 'F') && ((b.name()).at(0) == 'W')) || (((a.name()).at(0) == 'F') && ((b.name()).at(0) == 'W')) ||
            (((a.name()).at(0) == 'W') && ((b.name()).at(0) == 'I'))) {
                ascore = ascore - 1;
                cout << "The scoring ability of " << a.name() << " (chosen player) was not as effective against " << endl;
                cout << b.name() << "'s type" << endl;
                cout << "One point will be subtracted from " << a.name() << "'s score because of this" << endl;
            }
    }
    else {
        currpoints = b.points() - a.minus();
        bscore = currpoints;
        cout << b.name() << " scores " << b.points() << ", but " << a.minus() << " point(s) were taken away because ";
        cout << "of the defense by " << a.name() << " (chosen player)" << endl;
        if ((((b.name()).at(0) == 'F') && ((a.name()).at(0) == 'W')) || (((b.name()).at(0) == 'I') && ((a.name()).at(0) == 'F')) ||
            (((b.name()).at(0) == 'W') && ((a.name()).at(0) == 'I'))) {
                bscore = bscore - 1;
                cout << "The scoring ability of " << b.name() << " was not as effective against " << endl;
                cout << "the type of " << a.name() << " (chosen player)" << endl;
                cout << "One point will be subtracted from " << b.name() << "'s score because of this" << endl;
            }
    }
    cout << "The score is " << ascore << " for " << a.name() << " (chosen player) and " << bscore << " for " << b.name() << endl;
    cout << endl;
}

void gettingrebound(game player, game opposition, bool& gotrebound, int& helper) {
    if (helper == 1) {
        if (player.putback() > 2) {
            cout << "Even with defending " << player.name() << " secures a possession with a rebound" << endl;
            gotrebound = true;
        }
        else {
            cout << player.name() << " has not grabbed a rebound and " << opposition.name() << " (chosen player) has grabbed an "; 
            cout << "offensive rebound" << endl;
            gotrebound = false;
        }
    }
    else if (helper == 2) {
        if (player.putback() > 2) {
            cout << "Even with defending " << player.name() << " (chosen player) secures a possession with a rebound" << endl; 
            gotrebound = true;
        }
        else {
            cout << player.name() << " (chosen player) has not grabbed a rebound and " << opposition.name() << " has grabbed ";
            cout << "an offensive rebound" << endl;
            gotrebound = false;
        }
    }
    cout << endl;
}