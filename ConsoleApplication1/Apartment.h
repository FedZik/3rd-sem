#ifndef APARTMENT_H
#define APARTMENT_H

#include "Property.h"

class Apartment : public Property {
private:
    int floorNumber;

public:
    Apartment(const std::string& location, double price, double area, int floorNumber);

    int getFloorNumber() const;
};

#endif
