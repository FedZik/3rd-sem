#pragma once
#include <string>
#include <vector>
#include "Property.h"

class Client {
private:
    std::string fullName;
    std::string passportNumber;
    std::vector<Property*> properties;

    Client(const std::string& fullName, const std::string& passportNumber);

public:
    static Client* createInstance(const std::string& fullName, const std::string& passportNumber);

    std::string getFullName() const;
    std::string getPassportNumber() const;
    void addProperty(Property* property);
    const std::vector<Property*>& getProperties() const;
};
