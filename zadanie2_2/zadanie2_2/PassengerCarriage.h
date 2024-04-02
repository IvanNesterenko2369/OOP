#ifndef PASSENGERCARRIAGE_H
#define PASSENGERCARRIAGE_H

#include "Carriage.h"
#include <string>
#include <iostream>

class PassengerCarriage : public Carriage {
private:
    int seatsCount; // Возможно, это также количество пассажиров, если они занимают все места.
    std::string comfortLevel;

public:
    PassengerCarriage(int id, const std::string& type, double weight, double length, int seatsCount, const std::string& comfortLevel)
        : Carriage(id, type, weight, length), seatsCount(seatsCount), comfortLevel(comfortLevel) {}

    // Геттеры и сеттеры для новых атрибутов
    int getSeatsCount() const { return seatsCount; }
    std::string getComfortLevel() const { return comfortLevel; }
    void setSeatsCount(int newSeatsCount) { seatsCount = newSeatsCount; }
    void setComfortLevel(const std::string& newComfortLevel) { comfortLevel = newComfortLevel; }

    // Предположим, что метод getPassengerCount возвращает количество мест, 
    // поскольку каждое место может быть занято одним пассажиром.
    int getPassengerCount() const { return seatsCount; }

    // Реализация метода displayInfo
    void displayInfo() const override {
        std::cout << "Ідентифікатор пасажирських перевезень: " << getId()
            << ", Тип: " << getType()
            << ", Вага: " << getWeight()
            << ", Довжина: " << getLength()
            << ", Сидіння: " << seatsCount
            << ", Комфорт: " << comfortLevel << std::endl;
    }
};

#endif // PASSENGERCARRIAGE_H
