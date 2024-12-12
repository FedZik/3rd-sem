#include <iostream>
#include <memory>
#include "RealEstateManager.h"
#include "Apartment.h"
#include "House.h"

int main() {
    RealEstateManager manager;

    Client client("123456789", "John Doe");
    manager.addClient(client);

    auto house = std::make_shared<House>("New York", 500000, 300, 2);
    manager.addProperty(house);

    auto apartment = std::make_shared<Apartment>("Chicago", 200000, 120, 3);
    manager.addProperty(apartment);

    manager.showAllProperties();

    auto foundClient = manager.searchClientByPassport("123456789");
    if (foundClient) {
        std::cout << "Client found: " << foundClient->getFullName() << std::endl;
    }

    auto properties = manager.searchByCriteria(100000, 600000, 100, "New York");
    std::cout << "Properties found in New York: " << properties.size() << std::endl;

    double profit = manager.calculateProfit(0.05); // 5% комиссия
    std::cout << "Total profit: " << profit << std::endl;

    return 0;
}
