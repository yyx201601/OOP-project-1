#ifndef WHEAT_H
#define WHEAT_H

#include "Crop.h"

class Wheat : public Crop {
public:
    Wheat(); // default constructor
    Wheat(string crop_name, int grow_time, float purchase_price);

    void grow() override; // function to grow the crop
    void harvest() override; // function to harvest the crop
    void print_info() const override; // function to print information about the crop
};

#endif
