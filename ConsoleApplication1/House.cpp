#include "House.h"

House::House(const std::string& location, double price, double area, int numberOfFloors)
    : Property(location, price, area), numberOfFloors(numberOfFloors) {
}

int House::getNumberOfFloors() const {
    return numberOfFloors;
}
