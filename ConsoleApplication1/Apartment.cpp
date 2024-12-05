#include "Apartment.h"
#include <sstream>

Apartment::Apartment(const std::string& location, double price, double area, int floorNumber)
    : Property(location, price, area), floorNumber(floorNumber) {
}

std::string Apartment::getInfo() const {
    std::ostringstream oss;
    oss << "Apartment located at " << location << ", Price: " << price << ", Area: " << area << " sqm, Floor: " << floorNumber;
    return oss.str();
}
