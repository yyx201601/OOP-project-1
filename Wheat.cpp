#include "Wheat.h"
#include <iostream>

Wheat::Wheat() : Crop() {}

Wheat::Wheat(string crop_name, int grow_time, float purchase_price)
    : Crop(crop_name, grow_time, purchase_price) {}

void Wheat::grow() {
    grow_stage++;
    cout << name << " is growing. Current grow stage: " << grow_stage << endl;
}

void Wheat::harvest() {
    if (grow_stage >= maturity_time) {
        cout << name << " has been harvested!" << endl;
        grow_stage = 0;
    } else {
        cout << name << " is not ready to be harvested yet." << endl;
    }
}

void Wheat::print_info() const {
    cout << "Crop: " << name << endl;
    cout << "Grow stage: " << grow_stage << endl;
    cout << "Maturity time: " << maturity_time << endl;
    cout << "Sold price: " << purchase_price * 2 << endl;
}
