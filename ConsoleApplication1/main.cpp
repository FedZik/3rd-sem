#include <iostream>
#include "Client.h"
#include "House.h"
#include "Apartment.h"

int main() {
    Client* client = Client::createInstance("John Doe", "AB1234567");
    Property* house = House::createInstance("12 First Street", 250000, 120.5, 5);
    Property* apartment = Apartment::createInstance("34 Second Street", 150000, 80.0, 3);

    client->addProperty(house);
    client->addProperty(apartment);

    std::cout << "Client: " << client->getFullName() << "\n";
    std::cout << "Properties owned:\n";

    for (const auto& property : client->getProperties()) {
        std::cout << "- " << property->getLocation() << ", $" << property->getPrice() << ", " << property->getArea() << " sq/m\n";
    }

    return 0;
}
