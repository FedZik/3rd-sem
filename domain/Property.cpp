#include "Property.h"
#include "Client.h"

Property::Property(const std::string& address, double price)
    : address(address), price(price), owner(nullptr) {}

std::string Property::getAddress() const
{
    return address;
}

double Property::getPrice() const
{
    return price;
}

std::shared_ptr<Client> Property::getOwner() const
{
    return owner;
}

void Property::setOwner(const std::shared_ptr<Client>& client)
{
    owner = client;
}
