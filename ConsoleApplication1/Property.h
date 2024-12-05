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
    virtual ~Property() = default;

    virtual std::string getInfo() const = 0;

    double getPrice() const;
    double getArea() const;
    std::string getLocation() const;
};

#endif // PROPERTY_H
