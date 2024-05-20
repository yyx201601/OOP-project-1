#include <iostream>
#include "Inventory.h"

int main() {
    Inventory inventory;
    int choice;

    while (true) {
        std::cout << "1. Purchase Equipment" << std::endl;
        std::cout << "2. Sell Equipment" << std::endl;
        std::cout << "3. Display Inventory" << std::endl;
        std::cout << "4. List Available Equipment" << std::endl;
        std::cout << "5. Find Equipment by Type" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                inventory.purchaseEquipment();
                break;
            case 2:
                inventory.sellEquipment();
                break;
            case 3:
                inventory.displayInventory();
                break;
            case 4:
                inventory.listAvailableEquipment();
                break;
            case 5: {
                std::string type;
                std::cout << "Enter equipment type to find: ";
                std::cin >> type;
                inventory.findEquipmentByType(type);
                break;
            }
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}