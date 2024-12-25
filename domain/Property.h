#pragma once
#include <string>
#include <memory>


class Client;

class Property
{
private:
 std::string address;
 double price;
 std::shared_ptr<Client> owner;

public:
 /**
  * @brief Конструктор
  * @param address Адрес
  * @param price Цена
  */
 Property(const std::string& address, double price);

 /**
  * @brief Получает адрес собственности.
  * @return Адрес собственности.
  */
 std::string getAddress() const;

 /**
  * @brief Получает цену собственности.
  * @return Цена собственности.
  */
 double getPrice() const;

 /**
  * @brief Получает владельца собственности.
  * @return Владелец собственности.
  */
 std::shared_ptr<Client> getOwner() const;

 /**
  * @brief Устанавливает владельца собственности.
  * @param client Владелец, который приобретает собственность.
  */
 void setOwner(const std::shared_ptr<Client>& client);
};
