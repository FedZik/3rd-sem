#ifndef HOUSE_H
#define HOUSE_H

#include "Property.h"

class House : public Property {
private:
    int numberOfFloors;

public:
    House(const std::string& location, double price, double area, int numberOfFloors);

    int getNumberOfFloors() const;
};

#endif
