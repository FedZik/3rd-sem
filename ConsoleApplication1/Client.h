#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    std::string passportNumber;
    std::string fullName;

public:
    Client(const std::string& passportNumber, const std::string& fullName);
    std::string getPassportNumber() const;
    std::string getFullName() const;
};

#endif // CLIENT_H
