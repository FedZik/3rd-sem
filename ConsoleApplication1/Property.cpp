#include "Property.h"

Property::Property(const std::string& location, double price, double area)
    : location(location), price(price), area(area) {
}

double Property::getPrice() const {
    return price;
}

double Property::getArea() const {
    return area;
}

std::string Property::getLocation() const {
    return location;
}
