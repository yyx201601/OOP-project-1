#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Inventory {
private:
    map<string, float> price_list;

public:
    Inventory();

    void displayPrices() const;
};

#endif
