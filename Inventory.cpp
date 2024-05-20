#include "Inventory.h"

// Initialize the price list in the constructor
Inventory::Inventory() {
    price_list["Wheat"] = 50.0;
    price_list["Corn"] = 75.0;
    price_list["Chicken"] = 200.0;
    price_list["Cow"] = 1500.0;
}

// Display the price list
void Inventory::displayPrices() const {
    cout << "Price List:" << endl;
    for (const auto& item : price_list) {
        cout << item.first << ": $" << item.second << endl;
    }
}
