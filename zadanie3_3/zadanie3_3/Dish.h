// Dish.h
#ifndef DISH_H
#define DISH_H

#include <string>
#include <iostream>

class Dish {
private:
    std::string name;
    std::string description;
    double price;
    double weight;
    std::string allergens;

public:
    Dish(const std::string& name, const std::string& description, double price, double weight, const std::string& allergens)
        : name(name), description(description), price(price), weight(weight), allergens(allergens) {}

    double getPrice() const {
        return price;
    }

    void displayInfo() const {
        std::cout << "�����: " << name << "\n"
            << "����: " << description << "\n"
            << "ֳ��: $" << price << "\n"
            << "����: " << weight << "g\n"
            << "��������: " << allergens << "\n";
    }
};

#endif // DISH_H
