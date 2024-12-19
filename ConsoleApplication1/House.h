#pragma once
#include "Property.h"

class House : public Property {
private:
    int rooms;

    House(const std::string& location, double price, double area, int rooms);

public:
    static House* createInstance(const std::string& location, double price, double area, int rooms);

    int getRooms() const;
};