#include "Crop.h"
#include <iostream>

// Default constructor
Crop::Crop() : name(" "), grow_stage(0), maturity_time(0), purchase_price(0.0) {}

// Constructor with parameters
Crop::Crop(string crop_name, int grow_time, float purchase_price) 
    : name(crop_name), grow_stage(0), maturity_time(grow_time), purchase_price(purchase_price) {}

void Crop::grow() {
    grow_stage++;
    cout << name << " is growing. Current grow stage: " << grow_stage << endl;
}

void Crop::harvest() {
    // Check if the crop is ready to be harvested
    if (grow_stage >= maturity_time) {
        cout << name << " has been harvested!" << endl;
        grow_stage = 0;
    } else {
        cout << name << " is not ready to be harvested yet." << endl;
    }
}

string Crop::getName() const {
    return name;
}

int Crop::getGrowStage() const {
    return grow_stage;
}

int Crop::getMaturityTime() const {
    return maturity_time;
}

float Crop::getPrice() const {
    return purchase_price;
}
