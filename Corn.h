#ifndef CORN_H
#define CORN_H

#include "Crop.h"

class Corn : public Crop {
public:
    Corn(); // default constructor
    Corn(string crop_name, int grow_time, float purchase_price); // constructor with parameters
    void print_info() override; // function to print information about the crop
};

#endif
