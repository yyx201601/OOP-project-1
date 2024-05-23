#ifndef CROP_H
#define CROP_H

#include <iostream>
#include <string>
using namespace std;

class Crop {
protected:
    string name; // name of the crop
    int grow_stage; // current growth stage of the crop
    int maturity_time; // time it takes for the crop to mature
    float purchase_price; // Price at which the crop was planted

public:
    Crop(); // default constructor
    Crop(string crop_name, int grow_time, float purchase_price); // constructor with parameters
    virtual ~Crop() {} // virtual destructor

    virtual void grow() = 0; // pure virtual function to grow the crop
    virtual void harvest() = 0; // pure virtual function to harvest the crop
    virtual void print_info() const = 0; // pure virtual function to print information about the crop

    string getName() const;
    int getGrowStage() const;
    int getMaturityTime() const;
    float getPrice() const;
};

#endif
