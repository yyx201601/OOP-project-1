#include "Animal.h"

// Initialize static member
map<string, float> Animal::animal_prices = {
    {"Cow", 1500.0},
    {"Chicken", 200.0}
};

Animal::Animal() : animal_type("Unknown"), age(0), health_status("Unknown"), maturity_age(0), purchase_price(0.0) {}

Animal::Animal(string animal_type, int age, string health_status, int maturity_age, float purchase_price)
    : animal_type(animal_type), age(age), health_status(health_status), maturity_age(maturity_age), purchase_price(purchase_price) {}

void Animal::print_info() const {
    cout << "Animal type: " << animal_type << endl;
    cout << "Age: " << age << endl;
    cout << "Health status: " << health_status << endl;
    cout << "Maturity age: " << maturity_age << endl;
    cout << "Purchase price: " << purchase_price << endl;
}

void Animal::feed() {
    cout << "Feeding " << animal_type << endl;
    health_status = "Healthy";
    age_up();
}

void Animal::age_up() {
    age++;
    if (age >= maturity_age) {
        cout << animal_type << " has matured." << endl;
    }
}

string Animal::get_type() const {
    return animal_type;
}

int Animal::get_age() const {
    return age;
}

string Animal::get_health_status() const {
    return health_status;
}

float Animal::get_price() const {
    return purchase_price;
}

bool Animal::is_mature() const {
    return age >= maturity_age;
}
