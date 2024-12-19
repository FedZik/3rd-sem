#include "House.h"

House::House(const std::string& location, double price, double area, int rooms)
    : Property(location, price, area), rooms(rooms) {
}

House* House::createInstance(const std::string& location, double price, double area, int rooms) {
    return new House(location, price, area, rooms);
}

int House::getRooms() const {
    return rooms;
}
