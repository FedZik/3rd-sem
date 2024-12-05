#include "pch.h"
#include "../ConsoleApplication1/RealEstateManager.h"
#include "../ConsoleApplication1/House.h"
#include "../ConsoleApplication1/Apartment.h"
#include "../ConsoleApplication1/Client.h"

TEST(RealEstateManagerTests, AddClientTest) {
    RealEstateManager manager;
    Client client("123456789", "John Doe");

    manager.addClient(client);

    Client* foundClient = manager.searchClientByPassport("123456789");
    ASSERT_NE(foundClient, nullptr);  // Проверяем, что клиент найден
    ASSERT_EQ(foundClient->getFullName(), "John Doe");  // Проверка имени клиента
}

TEST(RealEstateManagerTests, AddPropertyTest) {
    RealEstateManager manager;
    auto house = std::make_shared<House>("New York", 500000, 300, 2);

    manager.addProperty(house);

    auto properties = manager.searchByCriteria(0, 1000000, 0, "New York");
    ASSERT_EQ(properties.size(), 1);  // Проверка, что добавлена одна недвижимость
    ASSERT_EQ(properties[0]->getLocation(), "New York");  // Проверка локации
    ASSERT_EQ(properties[0]->getPrice(), 500000.0);  // Проверка цены
}

TEST(RealEstateManagerTests, SearchClientNotFoundTest) {
    RealEstateManager manager;
    Client* client = manager.searchClientByPassport("987654321");

    ASSERT_EQ(client, nullptr);  // Проверка, что клиент не найден
}

TEST(RealEstateManagerTests, CalculateProfitTest) {
    RealEstateManager manager;
    manager.addProperty(std::make_shared<House>("Boston", 300000, 250, 2));
    manager.addProperty(std::make_shared<Apartment>("Chicago", 200000, 120, 3));

    double profit = manager.calculateProfit(0.05);  // 5% комиссии
    ASSERT_EQ(profit, 25000.0);  // Проверка вычисления прибыли
}

// Добавим тест на поиск недвижимости по критериям
TEST(RealEstateManagerTests, SearchByCriteriaTest) {
    RealEstateManager manager;
    manager.addProperty(std::make_shared<House>("New York", 500000, 300, 2));
    manager.addProperty(std::make_shared<Apartment>("New York", 400000, 120, 1));

    auto properties = manager.searchByCriteria(400000, 600000, 100, "New York");
    ASSERT_EQ(properties.size(), 2);  // Проверка, что две недвижимости найдены
}