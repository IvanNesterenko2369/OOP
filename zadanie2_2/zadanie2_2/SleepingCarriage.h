// SleepingCarriage.h
#ifndef SLEEPINGCARRIAGE_H
#define SLEEPINGCARRIAGE_H

#include "Carriage.h"
#include <iostream>

class SleepingCarriage : public Carriage {
private:
    int compartmentsCount;
    bool hasShowers;

public:
    SleepingCarriage(int id, const std::string& type, double weight, double length, int compartmentsCount, bool hasShowers)
        : Carriage(id, type, weight, length), compartmentsCount(compartmentsCount), hasShowers(hasShowers) {}

    int getCompartmentsCount() const { return compartmentsCount; }
    bool getHasShowers() const { return hasShowers; }
    void setCompartmentsCount(int newCompartmentsCount) { compartmentsCount = newCompartmentsCount; }
    void setHasShowers(bool newHasShowers) { hasShowers = newHasShowers; }

    void displayInfo() const override {
        std::cout << "Ідентифікатор спального вагона ID: " << getId()
            << ", Тип: " << getType()
            << ", Вага: " << getWeight()
            << ", Довжина: " << getLength()
            << ", Відділення: " << compartmentsCount
            << ", Є душові кабіни: " << (hasShowers ? "Так" : "Ні") << std::endl;
    }
};

#endif // SLEEPINGCARRIAGE_H
