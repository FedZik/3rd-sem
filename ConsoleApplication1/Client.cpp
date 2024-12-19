#include "Client.h"

Client::Client(const std::string& fullName, const std::string& passportNumber)
    : fullName(fullName), passportNumber(passportNumber) {
}

Client* Client::createInstance(const std::string& fullName, const std::string& passportNumber) {
    return new Client(fullName, passportNumber);
}

std::string Client::getFullName() const {
    return fullName;
}

std::string Client::getPassportNumber() const {
    return passportNumber;
}

void Client::addProperty(Property* property) {
    properties.push_back(property);
}

const std::vector<Property*>& Client::getProperties() const {
    return properties;
}
