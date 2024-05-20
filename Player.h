#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Player {
private:
    string name;
    int level;
    vector<string> achievements;

public:
    Player(string name, int level);

    string getName() const;
    int getLevel() const;
    void setLevel(int level);
    void addAchievement(const string& achievement);
    vector<string> getAchievements() const;
    void displayInfo() const;
};

#endif
