#pragma once
#include "Property.h"

class Apartment : public Property {
private:
    int floor;

    Apartment(const std::string& location, double price, double area, int floor);

public:
    static Apartment* createInstance(const std::string& location, double price, double area, int floor);

    int getFloor() const;
};
