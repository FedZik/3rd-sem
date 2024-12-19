#pragma once
#pragma once

#include <memory>
#include <string>
#include <vector>

/**
 * @brief ������� ����� ��� ������������� ������������.
 */
class Property {
private:
    /**
     * @brief �������������� ������������.
     */
    std::string location;

    /**
     * @brief ���� ������������.
     */
    double price;

    /**
     * @brief ������� ������������.
     */
    double area;

    /**
     * @brief �������� ����������� ������ Property.
     * @param location ��������������.
     * @param price ����.
     * @param area �������.
     */
    Property(const std::string& location, double price, double area);

public:
    /**
     * @brief ������� ������ Property.
     * @param location ��������������.
     * @param price ����.
     * @param area �������.
     * @return ��������� �� ��������� ������ Property.
     */
    static std::shared_ptr<Property> createProperty(const std::string& location, double price, double area);

    /**
     * @brief ���������� �������������� ������������.
     * @return ��������������.
     */
    std::string getLocation() const;

    /**
     * @brief ���������� ���� ������������.
     * @return ����.
     */
    double getPrice() const;

    /**
     * @brief ���������� ������� ������������.
     * @return �������.
     */
    double getArea() const;
};

/**
 * @brief ����� ��� ������������� ����.
 */
class House : public Property {
private:
    /**
     * @brief ���������� ������ � ����.
     */
    int rooms;

    /**
     * @brief �������� ����������� ������ House.
     * @param location ��������������.
     * @param price ����.
     * @param area �������.
     * @param rooms ���������� ������.
     */
    House(const std::string& location, double price, double area, int rooms);

public:
    /**
     * @brief ������� ������ House.
     * @param location ��������������.
     * @param price ����.
     * @param area �������.
     * @param rooms ���������� ������.
     * @return ��������� �� ��������� ������ House.
     */
    static std::shared_ptr<House> createProperty(const std::string& location, double price, double area, int rooms);

    /**
     * @brief ���������� ���������� ������ � ����.
     * @return ���������� ������.
     */
    int getRooms() const;
};

/**
 * @brief ����� ��� ������������� ��������.
 */
class Apartment : public Property {
private:
    /**
     * @brief ���� ��������.
     */
    int floor;

    /**
     * @brief �������� ����������� ������ Apartment.
     * @param location ��������������.
     * @param price ����.
     * @param area �������.
     * @param floor ����.
     */
    Apartment(const std::string& location, double price, double area, int floor);

public:
    /**
     * @brief ������� ������ Apartment.
     * @param location ��������������.
     * @param price ����.
     * @param area �������.
     * @param floor ����.
     * @return ��������� �� ��������� ������ Apartment.
     */
    static std::shared_ptr<Apartment> createProperty(const std::string& location, double price, double area, int floor);

    /**
     * @brief ���������� ���� ��������.
     * @return ����.
     */
    int getFloor() const;
};
