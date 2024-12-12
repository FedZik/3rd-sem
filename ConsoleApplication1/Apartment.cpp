#include "Apartment.h"

Apartment::Apartment(const std::string& location, double price, double area, int floorNumber)
    : Property(location, price, area), floorNumber(floorNumber) {
}

int Apartment::getFloorNumber() const {
    return floorNumber;
}
