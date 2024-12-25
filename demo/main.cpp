#include <memory>
#include "../domain/Manager.h"
#include "../domain/Property.h"
#include "../domain/Client.h"


int main() {
    auto manager = std::make_shared<Manager>();

    auto client1 = std::make_shared<Client>("John Doe", "1234-5678");
    auto client2 = std::make_shared<Client>("Jane Smith", "8765-4321");

    manager->addClient(client1);
    manager->addClient(client2);

    auto property1 = std::make_shared<Property>("123 Main Street", 250000.0);
    auto property2 = std::make_shared<Property>("456 Elm Street", 320000.0);

    client1->deal(property1);
    client2->deal(property2);

    manager->displayClients();

    return 0;
}
