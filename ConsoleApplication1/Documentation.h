#pragma once
#pragma once

#include <memory>
#include <string>
#include <vector>

/**
 * @brief Базовый класс для представления недвижимости.
 */
class Property {
private:
    /**
     * @brief Местоположение недвижимости.
     */
    std::string location;

    /**
     * @brief Цена недвижимости.
     */
    double price;

    /**
     * @brief Площадь недвижимости.
     */
    double area;

    /**
     * @brief Закрытый конструктор класса Property.
     * @param location Местоположение.
     * @param price Цена.
     * @param area Площадь.
     */
    Property(const std::string& location, double price, double area);

public:
    /**
     * @brief Создает объект Property.
     * @param location Местоположение.
     * @param price Цена.
     * @param area Площадь.
     * @return Указатель на созданный объект Property.
     */
    static std::shared_ptr<Property> createProperty(const std::string& location, double price, double area);

    /**
     * @brief Возвращает местоположение недвижимости.
     * @return Местоположение.
     */
    std::string getLocation() const;

    /**
     * @brief Возвращает цену недвижимости.
     * @return Цена.
     */
    double getPrice() const;

    /**
     * @brief Возвращает площадь недвижимости.
     * @return Площадь.
     */
    double getArea() const;
};

/**
 * @brief Класс для представления дома.
 */
class House : public Property {
private:
    /**
     * @brief Количество комнат в доме.
     */
    int rooms;

    /**
     * @brief Закрытый конструктор класса House.
     * @param location Местоположение.
     * @param price Цена.
     * @param area Площадь.
     * @param rooms Количество комнат.
     */
    House(const std::string& location, double price, double area, int rooms);

public:
    /**
     * @brief Создает объект House.
     * @param location Местоположение.
     * @param price Цена.
     * @param area Площадь.
     * @param rooms Количество комнат.
     * @return Указатель на созданный объект House.
     */
    static std::shared_ptr<House> createProperty(const std::string& location, double price, double area, int rooms);

    /**
     * @brief Возвращает количество комнат в доме.
     * @return Количество комнат.
     */
    int getRooms() const;
};

/**
 * @brief Класс для представления квартиры.
 */
class Apartment : public Property {
private:
    /**
     * @brief Этаж квартиры.
     */
    int floor;

    /**
     * @brief Закрытый конструктор класса Apartment.
     * @param location Местоположение.
     * @param price Цена.
     * @param area Площадь.
     * @param floor Этаж.
     */
    Apartment(const std::string& location, double price, double area, int floor);

public:
    /**
     * @brief Создает объект Apartment.
     * @param location Местоположение.
     * @param price Цена.
     * @param area Площадь.
     * @param floor Этаж.
     * @return Указатель на созданный объект Apartment.
     */
    static std::shared_ptr<Apartment> createProperty(const std::string& location, double price, double area, int floor);

    /**
     * @brief Возвращает этаж квартиры.
     * @return Этаж.
     */
    int getFloor() const;
};
