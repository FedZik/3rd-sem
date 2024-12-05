#include <iostream>
#include "House.h"
#include "Apartment.h"
#include "RealEstateManager.h"

int main() {
    RealEstateManager manager;

    manager.addProperty(std::make_shared<House>("New York", 500000, 300, 2));
    manager.addProperty(std::make_shared<Apartment>("Los Angeles", 300000, 100, 5));

    manager.addClient(Client("123456789", "John Doe"));
    manager.addClient(Client("987654321", "Jane Doe"));

    std::cout << "All Properties:\n";
    manager.showAllProperties();

    std::cout << "\nSearching client with passport 123456789:\n";
    Client* client = manager.searchClientByPassport("123456789");
    if (client != nullptr) {
        std::cout << "Client found: " << client->getFullName() << "\n";
    }
    else {
        std::cout << "Client not found.\n";
    }

    return 0;
}
