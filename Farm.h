#ifndef FARM_H
#define FARM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Animal.h"
#include "Crop.h"
#include "Wheat.h"
#include "Corn.h"
#include "Player.h"

using namespace std;

class Farm {
protected:
    int farm_size; // size of the farm
    float available_funds; // available funds
    vector<Crop*> crops; // vector to store crops
    vector<Animal*> animals;  // vector to store animals
    map<string, float> crop_prices; // map to store crop prices
    Player& player; // reference to the player

    void checkAchievements(); // check and update player achievements

public:
    Farm(Player& player, int size = 1, float funds = 1000); // constructor with parameters
    ~Farm(); // destructor

    void plant_crop(const string& crop); // function to plant a crop
    void harvest_crop(const string& crop); // function to harvest a crop
    void buy_animal(const string& animal_type); // function to buy an animal
    void sell_animal(const string& animal_type); // function to sell an animal
    void print_farm_status() const; // function to print the farm status

    vector<Crop*>& getCrops(); // getter for crops
    vector<Animal*>& getAnimals(); // getter for animals
    float getAvailableFunds() const; // getter for available funds

private:
    void cleanup(); // function to clean up dynamically allocated memory
};

#endif
