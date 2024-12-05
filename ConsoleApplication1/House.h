#ifndef HOUSE_H
#define HOUSE_H

#include "Property.h"

class House : public Property {
private:
    int floors;

public:
    House(const std::string& location, double price, double area, int floors);
    std::string getInfo() const override;
};

#endif // HOUSE_H
