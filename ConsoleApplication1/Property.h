#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

class Property {
protected:
    std::string location;
    double price;
    double area;

public:
    Property(const std::string& location, double price, double area);
    virtual ~Property();

    std::string getLocation() const;
    double getPrice() const;
    double getArea() const;
};

#endif
