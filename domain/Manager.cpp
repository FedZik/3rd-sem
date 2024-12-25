#include "Manager.h"
#include <iostream>

void Manager::addClient(const std::shared_ptr<Client>& client) {
    clients.push_back(client);
}

std::vector<std::shared_ptr<Client>> Manager::getClients() const {
    return clients;
}

void Manager::displayClients() const {
    for (const auto& client : clients) {
        std::cout << "Client: " << client->getFullName() << "\n";
        auto properties = client->getProperties();
        for (const auto& property : properties) {
            std::cout << "  Property: " << property->getAddress()
                      << ", Price: " << property->getPrice()
                      << ", Owner: " << client->getFullName() << "\n";
        }
    }
}
