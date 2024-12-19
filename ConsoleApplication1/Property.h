#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

class Property {
private:
    std::string location;
    double price;
    double area;

protected:
    Property(const std::string& location, double price, double area);

public:
    virtual ~Property() = 0;
    static Property* createProperty(const std::string& location, double price, double area);

    std::string getLocation() const;
    double getPrice() const;
    double getArea() const;
};

#endif // PROPERTY_H