#include "Apartment.h"

Apartment::Apartment(const std::string& location, double price, double area, int floor)
    : Property(location, price, area), floor(floor) {
}

Apartment* Apartment::createInstance(const std::string& location, double price, double area, int floor) {
    return new Apartment(location, price, area, floor);
}

int Apartment::getFloor() const {
    return floor;
}