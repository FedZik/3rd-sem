#include "House.h"
#include <sstream>

House::House(const std::string& location, double price, double area, int floors)
    : Property(location, price, area), floors(floors) {
}

std::string House::getInfo() const {
    std::ostringstream oss;
    oss << "House located at " << location << ", Price: " << price << ", Area: " << area << " sqm, Floors: " << floors;
    return oss.str();
}
