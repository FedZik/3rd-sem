#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Property.h"

/**
 * @brief Класс, представляющий клиента.
 */
class Client : public std::enable_shared_from_this<Client>
{
private:
 std::shared_ptr<std::string> fullName;
 std::shared_ptr<std::string> passportNumber;
 std::vector<std::shared_ptr<Property>> properties;

public:
 /**
  * @brief Конструктор клиента.
  * @param fullName Полное имя клиента.
  * @param passportNumber Паспортный номер клиента.
  */
 Client(const std::string& fullName, const std::string& passportNumber);

 /**
  * @brief Получает полное имя клиента.
  * @return Полное имя клиента.
  */
 std::string getFullName() const;

 /**
  * @brief Получает паспортный номер клиента.
  * @return Паспортный номер клиента.
  */
 std::string getPassportNumber() const;

 /**
  * @brief Добавить собственность клиенту.
  * @param property Указатель на объект собственности.
  */
 void addProperty(const std::shared_ptr<Property>& property);

 /**
  * @brief Получить список всех собственности клиента.
  * @return Вектор с объектами собственности клиента.
  */
 std::vector<std::shared_ptr<Property>> getProperties() const;

 /**
  * @brief Сделка — привязка собственности к клиенту (клиент становится владельцем).
  * @param property Объект собственности.
  */
 void deal(const std::shared_ptr<Property>& property);
};
