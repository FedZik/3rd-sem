#include "Client.h"
#include <memory>

Client::Client(const std::string& fullName, const std::string& passportNumber)
    : fullName(std::make_shared<std::string>(fullName)),
      passportNumber(std::make_shared<std::string>(passportNumber)) {}

std::string Client::getFullName() const
{
    return *fullName;
}

std::string Client::getPassportNumber() const
{
    return *passportNumber;
}

void Client::addProperty(const std::shared_ptr<Property>& property)
{
    properties.push_back(property);
}

std::vector<std::shared_ptr<Property>> Client::getProperties() const
{
    return properties;
}

void Client::deal(const std::shared_ptr<Property>& property) {
    property->setOwner(shared_from_this());
    addProperty(property);
}
