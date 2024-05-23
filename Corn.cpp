#include "Corn.h"
#include <iostream>

Corn::Corn() : Crop() {}

Corn::Corn(string crop_name, int grow_time, float purchase_price)
    : Crop(crop_name, grow_time, purchase_price) {}

void Corn::grow() {
    grow_stage++;
    std::cout << name << " is growing. Current grow stage: " << grow_stage << std::endl;
}

void Corn::harvest() {
    if (grow_stage >= maturity_time) {
        std::cout << name << " has been harvested!" << std::endl;
        grow_stage = 0;
    } else {
        std::cout << name << " is not ready to be harvested yet." << std::endl;
    }
}

void Corn::print_info() const {
    std::cout << "Crop: " << name << std::endl;
    std::cout << "Grow stage: " << grow_stage << std::endl;
    std::cout << "Maturity time: " << maturity_time << std::endl;
    std::cout << "Sold price: " << purchase_price * 2 << std::endl;
}
