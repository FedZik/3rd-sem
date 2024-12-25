#include <gtest/gtest.h>
#include "../domain/Client.h"
#include "../domain/Property.h"
#include "../domain/Manager.h"

// Тест для конструктора и методов класса Client
TEST(ClientTest, ConstructorAndGetters) {
    auto client = std::make_shared<Client>("John Doe", "1234-5678");

    // Проверка, что конструктор правильно инициализирует поля
    EXPECT_EQ(client->getFullName(), "John Doe");
    EXPECT_EQ(client->getPassportNumber(), "1234-5678");
}

// Тест для метода deal (сделка) в классе Client
TEST(ClientTest, DealProperty) {
    auto client = std::make_shared<Client>("John Doe", "1234-5678");
    auto property = std::make_shared<Property>("123 Main Street", 250000.0);

    client->deal(property);

    // Проверка, что свойство было добавлено клиенту
    EXPECT_EQ(client->getProperties().size(), 1);
    EXPECT_EQ(client->getProperties()[0], property);

    // Проверка, что собственность правильно назначена владельцу
    EXPECT_EQ(property->getOwner(), client);
}

// Тест для методов класса Property
TEST(PropertyTest, ConstructorAndGetters) {
    auto property = std::make_shared<Property>("123 Main Street", 250000.0);

    EXPECT_EQ(property->getAddress(), "123 Main Street");
    EXPECT_EQ(property->getPrice(), 250000.0);
    EXPECT_EQ(property->getOwner(), nullptr); // Изначально владельца нет
}

// Тест для метода setOwner в классе Property
TEST(PropertyTest, SetOwner) {
    auto client = std::make_shared<Client>("John Doe", "1234-5678");
    auto property = std::make_shared<Property>("123 Main Street", 250000.0);

    property->setOwner(client);

    EXPECT_EQ(property->getOwner(), client);
}

// Тест для класса Manager
TEST(ManagerTest, AddClientAndDisplayClients) {
    auto manager = std::make_shared<Manager>();
    auto client1 = std::make_shared<Client>("John Doe", "1234-5678");
    auto client2 = std::make_shared<Client>("Jane Smith", "8765-4321");

    manager->addClient(client1);
    manager->addClient(client2);

    // Проверка, что клиенты были добавлены в менеджер
    auto clients = manager->getClients();
    EXPECT_EQ(clients.size(), 2);
    EXPECT_EQ(clients[0]->getFullName(), "John Doe");
    EXPECT_EQ(clients[1]->getFullName(), "Jane Smith");
}

