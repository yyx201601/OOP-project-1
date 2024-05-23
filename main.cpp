#include <iostream>
#include <string>
#include <map>
#include "Farm.h"
#include "Crop.h"
#include "Animal.h"
#include "Player.h"
#include "Inventory.h"
#include "Wheat.h"
#include "Corn.h"
#include <limits>

using namespace std;

void displayMenu() {
    cout << endl;
    cout << "Please choose a selection you want to do: " << endl;
    cout << "1. Look up farm status" << endl;
    cout << "2. Check inventory" << endl;
    cout << "3. Plant crops" << endl;
    cout << "4. Buy animals" << endl;
    cout << "5. Feed animals" << endl;
    cout << "6. Sell crops" << endl;
    cout << "7. Sell animals" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

void updateFarmStatus(Farm& farm) {
    // Simulate crop growth
    for (Crop* crop : farm.getCrops()) {
        crop->grow();
    }
    // Simulate other daily updates here if necessary
}

void printFarmStatus(Farm& farm, const Player& player, int day) {
    cout << endl;
    cout << "Time: Day " << day << endl;
    cout << "Available funds: " << farm.getAvailableFunds() << " dollars" << endl;
    cout << "Player level: " << player.getLevel() << endl;
    cout << "There are " << (10 - farm.getCrops().size()) << " lands left." << endl;
    cout << "There are " << farm.getCrops().size() << " crops growing." << endl;
    cout << "There are " << farm.getAnimals().size() << " animals." << endl;
    cout << "Achievements: ";
    for (const string& achievement : player.getAchievements()) {
        cout << achievement << " ";
    }
    cout << endl;
}

int main() {
    string playerName;
    cout << "Welcome to the Virtual Farm Management Game. Please enter your name: ";
    cin >> playerName;
    Player player(playerName, 1);

    cout << "Welcome to " << playerName << "'s farm." << endl;
    cout << endl;
    cout << "Game rule: " << endl;
    cout << "1. Your goal is earning money as much as you can by planting crops and feeding animals." << endl;
    cout << "2. You will have 500 original funds to buy seeds and animals." << endl;
    cout << "3. You have to feed animals if you want them grow up." << endl;
    cout << "4. Three rounds, one day." << endl;
    cout << "5. The sold price is double of purchase price." << endl;
    cout << endl;

    Farm myFarm(player, 10, 500); // Farm size 10, initial funds 500
    Inventory inventory;
    int crop_quantity;
    int animal_quantity;
    int sell_crop_quantity;
    int sell_animal_quantity;
    int day = 1;
    int turnCounter = 0;
    bool gameRunning = true;

    while (gameRunning) {
        printFarmStatus(myFarm, player, day);
        displayMenu();
        
        int choice;
        cin >> choice;
        
        string cropType;
        string animalType;

        if (cin.fail()) { // check for invalid input
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
            cout << "Invalid choice." << endl;
        } else {
            switch (choice) {
                case 1:
                    myFarm.print_farm_status();
                    break;
                case 2:
                    inventory.displayPrices();
                    break;
                case 3:
                    cout << "Enter crop type to buy and plant: ";
                    cin >> cropType;
                    cout << "Enter quantity: ";
                    cin >> crop_quantity;
                    while (crop_quantity > 10 - static_cast<int>(myFarm.getCrops().size())) {
                        cout << "Not enough land to plant. Please enter a smaller quantity: ";
                        cin >> crop_quantity;
                    }
                    for (int i = 0; i < crop_quantity; i++) {
                        myFarm.plant_crop(cropType);
                    }
                    break;
                case 4:
                    cout << "Enter animal type to buy: ";
                    cin >> animalType;
                    cout << "Enter quantity: ";
                    cin >> animal_quantity;
                    for (int i = 0; i < animal_quantity; i++) {
                        myFarm.buy_animal(animalType);
                    }
                    cout << "Bought a " << animalType << "." << endl;
                    break;
                case 5:
                    for (Animal* animal : myFarm.getAnimals()) {
                        animal->feed();
                    }
                    break;
                case 6:
                    cout << "Enter crop type to sell: ";
                    cin >> cropType;
                    cout << "Enter quantity: ";
                    cin >> sell_crop_quantity;
                    while (sell_crop_quantity > crop_quantity) {
                        cout << "Not enough crops to sell. Please enter a smaller quantity: ";
                        cin >> sell_crop_quantity;
                    }
                    for (int i = 0; i < sell_crop_quantity; i++) {
                        myFarm.harvest_crop(cropType);
                    }
                    cout << "Harvested and sold " << cropType << " crop." << endl;
                    break;
                case 7:
                    cout << "Enter animal type to sell: ";
                    cin >> animalType;
                    cout << "Enter quantity: ";
                    cin >> sell_animal_quantity;
                    while (sell_animal_quantity > animal_quantity) {
                        cout << "Not enough animals to sell. Please enter a smaller quantity: ";
                        cin >> sell_animal_quantity;
                    }
                    for (int i = 0; i < sell_animal_quantity; i++) {
                        myFarm.sell_animal(animalType);
                    }
                    cout << "Sold " << animalType << "." << endl;
                    break;
                case 8:
                    gameRunning = false;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        }

        turnCounter++;

        // Increase day count every 3 turns
        if (turnCounter == 3) {
            day++;
            updateFarmStatus(myFarm); // Update farm status at the end of each day
            turnCounter = 0;
        }
    }

    return 0;
}
