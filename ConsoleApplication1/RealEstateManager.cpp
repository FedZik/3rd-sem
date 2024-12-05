#include "RealEstateManager.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

// Функция добавления недвижимости
void RealEstateManager::addProperty(std::shared_ptr<Property> property) {
    properties.push_back(property);
}

// Функция добавления клиента
void RealEstateManager::addClient(const Client& client) {
    clients.push_back(client);
}

// Поиск клиента по номеру паспорта
Client* RealEstateManager::searchClientByPassport(const std::string& passportNumber) {
    for (auto& client : clients) {
        if (client.getPassportNumber() == passportNumber) {
            return &client;
        }
    }
    return nullptr; // Клиент не найден
}

// Поиск недвижимости по критериям
std::vector<std::shared_ptr<Property>> RealEstateManager::searchByCriteria(double minPrice, double maxPrice, double minArea, const std::string& location) {
    std::vector<std::shared_ptr<Property>> result;

    for (auto& property : properties) {
        if (property->getPrice() >= minPrice &&
            property->getPrice() <= maxPrice &&
            property->getArea() >= minArea &&
            (location.empty() || property->getLocation() == location)) {
            result.push_back(property);
        }
    }

    return result;
}

// Вычисление прибыли компании на основе комиссии
double RealEstateManager::calculateProfit(double commissionRate) {
    double totalProfit = 0.0;

    // Проходим по всем объектам недвижимости и суммируем прибыль от каждой сделки
    for (auto& property : properties) {
        totalProfit += property->getPrice() * commissionRate;
    }

    return totalProfit;
}

// Показать все предложения недвижимости
void RealEstateManager::showAllProperties() const {
    if (properties.empty()) {
        std::cout << "No properties available.\n";
        return;
    }

    std::cout << "Available properties:\n";
    for (const auto& property : properties) {
        std::cout << "Location: " << property->getLocation()
            << ", Price: " << property->getPrice()
            << ", Area: " << property->getArea() << " sq.m.\n";
    }
}

