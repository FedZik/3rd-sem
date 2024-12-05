#include "Client.h"

Client::Client(const std::string& passportNumber, const std::string& fullName)
    : passportNumber(passportNumber), fullName(fullName) {
}

std::string Client::getPassportNumber() const {
    return passportNumber;
}

std::string Client::getFullName() const {
    return fullName;
}
