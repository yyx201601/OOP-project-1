#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string name, int level) : name(name), level(level) {}

string Player::getName() const {
    return name;
}

int Player::getLevel() const {
    return level;
}

void Player::setLevel(int level) {
    this->level = level;
}

void Player::addAchievement(const string& achievement) {
    achievements.push_back(achievement);
}

vector<string> Player::getAchievements() const {
    return achievements;
}

void Player::displayInfo() const {
    cout << "Player: " << name << "\nLevel: " << level << "\nAchievements: ";
    for (const string& achievement : achievements) {
        cout << achievement << " ";
    }
    cout << endl;
}
