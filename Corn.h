#ifndef CORN_H
#define CORN_H

#include "Crop.h"
#include <string>

class Corn : public Crop {
public:
    Corn(); // default constructor
    Corn(string crop_name, int grow_time, float purchase_price);

    void grow() override; // function to grow the crop
    void harvest() override; // function to harvest the crop
    void print_info() const override; // function to print information about the crop
};

#endif
