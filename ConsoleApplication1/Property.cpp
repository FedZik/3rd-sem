#include "Property.h"

Property::Property(const std::string& location, double price, double area)
    : location(location), price(price), area(area) {
}

Property::~Property() {}

Property* Property::createProperty(const std::string& location, double price, double area) {
    return new Property(location, price, area);
}

std::string Property::getLocation() const {
    return location;
}

double Property::getPrice() const {
    return price;
}

double Property::getArea() const {
    return area;
}
