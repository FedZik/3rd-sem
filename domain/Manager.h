#pragma once
#include <vector>
#include <memory>
#include "Property.h"
#include "Client.h"


class Manager
{
private:
 std::vector<std::shared_ptr<Client>> clients;
 std::vector<std::shared_ptr<Property>> properties;

public:
 /**
  * @brief Добавляет нового клиента.
  * @param client указатель на клиента.
  */
 void addClient(const std::shared_ptr<Client>& client);

 /**
  * @brief Получить всех клиентов.
  * @return Возвращает клиентов.
  */
 std::vector<std::shared_ptr<Client>> getClients() const;

 /**
  * @brief Отображает всех клиентов.
  */
 void displayClients() const;
};
