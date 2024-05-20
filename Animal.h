#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Animal {
protected:
    string animal_type;
    int age;
    string health_status;
    int maturity_age;
    float purchase_price; // Price at which the animal was bought

public:
    Animal(); // default constructor
    Animal(string animal_type, int age, string health_status, int maturity_age, float purchase_price); // constructor with parameters

    virtual void print_info() const;
    void feed(); // function to feed the animal and improve health status
    void age_up(); // function to increment the age of the animal

    string get_type() const;
    int get_age() const;
    string get_health_status() const;
    float get_price() const;
    bool is_mature() const; // check if the animal is mature

    static map<string, float> animal_prices; // static member for animal prices
};

#endif
