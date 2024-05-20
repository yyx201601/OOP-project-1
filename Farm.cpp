#include "Farm.h"
#include "Wheat.h"
#include "Corn.h"
#include <algorithm> // Include algorithm header for std::find
using namespace std;

// Constructor with parameters
Farm::Farm(Player& player, int size, float funds) : player(player), farm_size(size), available_funds(funds) {
    crop_prices["Wheat"] = 50.0;
    crop_prices["Corn"] = 75.0;
    // Add more crops and their prices as needed
}

// Destructor
Farm::~Farm() {
    cleanup();
}

// Function to clean up dynamically allocated memory
void Farm::cleanup() {
    for (Crop* crop : crops) {
        delete crop;
    }
    crops.clear();

    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

// Function to check and update player achievements
void Farm::checkAchievements() {
    if (available_funds >= 2000 && find(player.getAchievements().begin(), player.getAchievements().end(), string("Good job!")) == player.getAchievements().end()) {
        player.addAchievement("Good job!");
    } else if (available_funds >= 1000 && find(player.getAchievements().begin(), player.getAchievements().end(), string("Double!!")) == player.getAchievements().end()) {
        player.addAchievement("Double!!");
    }
}

// Function to plant a crop
void Farm::plant_crop(const string& crop) {
    // Check if the crop is in the crop_prices map
    auto it = crop_prices.find(crop);
    if (it != crop_prices.end()) {
        if (available_funds >= it->second) {
            available_funds -= it->second;
            if (crop == "Wheat") {
                crops.push_back(new Wheat("Wheat", 3, it->second)); // Assuming 3 is the maturity time
            } else if (crop == "Corn") {
                crops.push_back(new Corn("Corn", 5, it->second)); // Assuming 5 is the maturity time
            }
            cout << crop << " has been planted." << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    } else {
        cout << "Crop not recognized." << endl;
    }
    checkAchievements();
}
 
// Function to harvest a crop
void Farm::harvest_crop(const string& crop) {
    auto it = crops.begin();
    while (it != crops.end()) {
        if ((*it)->getName() == crop) {
            // Sell price is 2 times the purchase price
            available_funds += 2 * (*it)->getPrice();
            delete *it;
            it = crops.erase(it);
            cout << "Harvested and sold " << crop << " crop." << endl;
            player.setLevel(player.getLevel() + 1); // Increase player level
            checkAchievements();
            return;
        } else {
            ++it;
        }
    }
    cout << "No " << crop << " crop to harvest." << endl;
}

// Function to buy an animal
void Farm::buy_animal(const string& animal_type) {
    auto it = Animal::animal_prices.find(animal_type);
    if (it != Animal::animal_prices.end()) {
        if (available_funds >= it->second) {
            available_funds -= it->second;
            animals.push_back(new Animal(animal_type, 0, "Healthy", 3, it->second));
            cout << "Bought a " << animal_type << "." << endl;
        } else {
            cout << "Insufficient funds to buy " << animal_type << "." << endl;
        }
    } else {
        cout << "Animal type not recognized." << endl;
    }
    checkAchievements();
}

// Function to sell an animal
void Farm::sell_animal(const string& animal_type) {
    auto it = animals.begin();
    while (it != animals.end()) {
        if ((*it)->get_type() == animal_type) {
            if ((*it)->is_mature()) {
                // Sell price is 2 times the purchase price
                available_funds += 2 * (*it)->get_price();
                delete *it;
                it = animals.erase(it);
                cout << "Sold a " << animal_type << "." << endl;
                player.setLevel(player.getLevel() + 1); // Increase player level
                checkAchievements();
                return;
            } else {
                cout << animal_type << " is not mature yet and cannot be sold." << endl;
                return;
            }
        } else {
            ++it;
        }
    }
    cout << "No " << animal_type << " to sell." << endl;
}

// Function to print the farm status
void Farm::print_farm_status() const {
    cout << "Farm size: " << farm_size << endl;
    cout << "Available funds: " << available_funds << endl;
    cout << "Crops: " << endl;
    for (Crop* crop : crops) {
        crop->print_info();
    }
    cout << "Animals: " << endl;
    for (const Animal* animal : animals) {
        animal->print_info();
    }
}

// Getter for crops
vector<Crop*>& Farm::getCrops() {
    return crops;
}

// Getter for animals
vector<Animal*>& Farm::getAnimals() {
    return animals;
}

// Getter for available funds
float Farm::getAvailableFunds() const {
    return available_funds;
}
