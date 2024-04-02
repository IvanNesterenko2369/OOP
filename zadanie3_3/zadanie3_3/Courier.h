// Courier.h
#ifndef COURIER_H
#define COURIER_H

#include <string>
#include <iostream>

class Courier {
private:
    std::string name;
    std::string contact;
    double rating;
    std::string transportType;

public:
    Courier(const std::string& name, const std::string& contact, double rating, const std::string& transportType)
        : name(name), contact(contact), rating(rating), transportType(transportType) {}

    void displayInfo() const {
        std::cout << "Ім'я кур'єра: " << name << "\n"
            << "Контактна інформація: " << contact << "\n"
            << "Рейтинг: " << rating << "/5\n"
            << "Тип транспорту: " << transportType << "\n";
    }
};

#endif // COURIER_H
