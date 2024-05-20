#include "Wheat.h"

Wheat::Wheat() : Crop() {}

Wheat::Wheat(string crop_name, int grow_time, float purchase_price) 
    : Crop(crop_name, grow_time, purchase_price) {}

void Wheat::print_info() {
    cout << "Crop: " << name << endl;
    cout << "Grow stage: " << grow_stage << endl;
    cout << "Maturity time: " << maturity_time << endl;
    cout << "Purchase price: " << purchase_price << endl;
}
