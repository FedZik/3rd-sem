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
    void addProperty(std::shared_ptr<Property> property);
    void addClient(const Client& client);

    // ¬озвращает указатель на клиента или nullptr
    Client* searchClientByPassport(const std::string& passportNumber);

    std::vector<std::shared_ptr<Property>> searchByCriteria(double minPrice, double maxPrice, double minArea, const std::string& location);
    double calculateProfit(double commissionRate);
    void showAllProperties() const;
};

#endif // REALESTATEMANAGER_H
