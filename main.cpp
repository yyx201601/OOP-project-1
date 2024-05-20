#include <iostream>
#include <string>
#include "Farm.h"
#include "Crop.h"
#include "Animal.h"
#include "Player.h"
#include "Inventory.h"
#include "Wheat.h"
#include "Corn.h"

using namespace std;

void displayMenu() {
    cout << "Please choose a selection you want to do:\n";
    cout << "1. Look up farm status\n";
    cout << "2. Check inventory\n";
    cout << "3. Plant crops\n";
    cout << "4. Buy animals\n";
    cout << "5. Feed animals\n";
    cout << "6. Sell crops\n";
    cout << "7. Sell animals\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

void updateFarmStatus(Farm& farm) {
    // Simulate crop growth
    for (Crop* crop : farm.getCrops()) {
        crop->grow();
    }
}

void printFarmStatus(Farm& farm, const Player& player, int day) {
    cout << "\nTime: Day " << day << endl;
    cout << "Available funds: " << farm.getAvailableFunds() << " dollars\n";
    cout << "Player level: " << player.getLevel() << "\n";
    cout << "There are " << (10 - farm.getCrops().size()) << " lands left.\n";
    cout << "There are " << farm.getCrops().size() << " crops growing.\n";
    cout << "There are " << farm.getAnimals().size() << " animals.\n";
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
    cout << "Game rule: " << endl;
    cout << "1. Your goal is earning money as much as you can by planting crops and feeding animals." << endl;
    cout << "2. You will have 500 original funds to buy seeds and animals." << endl;
    cout << "3. You have to feed animals if you want them grow up." << endl;
    cout << "4. Three rounds, one day." << endl;
    cout << "5. The sold price is double of purchase price." << endl;

    Farm myFarm(player, 10, 500); // Farm size 10, initial funds 500
    Inventory inventory;
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
                myFarm.plant_crop(cropType);
                break;
            case 4:
                cout << "Enter animal type to buy: ";
                cin >> animalType;
                myFarm.buy_animal(animalType);
                break;
            case 5:
                for (Animal* animal : myFarm.getAnimals()) {
                    animal->feed();
                }
                break;
            case 6:
                cout << "Enter crop type to sell: ";
                cin >> cropType;
                myFarm.harvest_crop(cropType);
                break;
            case 7:
                cout << "Enter animal type to sell: ";
                cin >> animalType;
                myFarm.sell_animal(animalType);
                break;
            case 8:
                gameRunning = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
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
