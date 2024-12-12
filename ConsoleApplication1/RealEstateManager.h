#ifndef REALESTATEMANAGER_H
#define REALESTATEMANAGER_H

#include <vector>
#include <memory>
#include "Property.h"
#include "Client.h"

class RealEstateManager {
private:
    std::vector<std::shared_ptr<Property>> properties;
    std::vector<Client> clients;

public:
    void addProperty(const std::shared_ptr<Property>& property);
    void addClient(const Client& client);
    std::vector<std::shared_ptr<Property>> searchByCriteria(double minPrice, double maxPrice, double minArea, const std::string& location) const;
    Client* searchClientByPassport(const std::string& passportNumber);
    void showAllProperties() const;
    double calculateProfit(double commissionRate) const;
};

#endif
