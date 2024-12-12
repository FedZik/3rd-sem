#include "RealEstateManager.h"
#include <iostream>

void RealEstateManager::addProperty(const std::shared_ptr<Property>& property) {
    properties.push_back(property);
}

void RealEstateManager::addClient(const Client& client) {
    clients.push_back(client);
}

std::vector<std::shared_ptr<Property>> RealEstateManager::searchByCriteria(double minPrice, double maxPrice, double minArea, const std::string& location) const {
    std::vector<std::shared_ptr<Property>> results;

    for (const auto& property : properties) {
        if (property->getPrice() >= minPrice && property->getPrice() <= maxPrice &&
            property->getArea() >= minArea && property->getLocation() == location) {
            results.push_back(property);
        }
    }

    return results;
}

Client* RealEstateManager::searchClientByPassport(const std::string& passportNumber) {
    for (auto& client : clients) {
        if (client.getPassportNumber() == passportNumber) {
            return &client;
        }
    }
    return nullptr;
}

void RealEstateManager::showAllProperties() const {
    for (const auto& property : properties) {
        std::cout << "Location: " << property->getLocation()
            << ", Price: " << property->getPrice()
            << ", Area: " << property->getArea() << std::endl;
    }
}

double RealEstateManager::calculateProfit(double commissionRate) const {
    double totalProfit = 0.0;
    for (const auto& property : properties) {
        totalProfit += property->getPrice() * commissionRate;
    }
    return totalProfit;
}
