// FreightCarriage.h
#ifndef FREIGHTCARRIAGE_H
#define FREIGHTCARRIAGE_H

#include "Carriage.h"
#include <string>
#include <iostream>

class FreightCarriage : public Carriage {
private:
    double maxLoadCapacity;
    std::string cargoType;

public:
    FreightCarriage(int id, const std::string& type, double weight, double length, double maxLoadCapacity, const std::string& cargoType)
        : Carriage(id, type, weight, length), maxLoadCapacity(maxLoadCapacity), cargoType(cargoType) {}

    double getMaxLoadCapacity() const { return maxLoadCapacity; }
    std::string getCargoType() const { return cargoType; }
    void setMaxLoadCapacity(double newMaxLoadCapacity) { maxLoadCapacity = newMaxLoadCapacity; }
    void setCargoType(const std::string& newCargoType) { cargoType = newCargoType; }

    void displayInfo() const override {
        std::cout << "Freight Carriage ID: " << getId()
            << ", Type: " << getType()
            << ", Weight: " << getWeight()
            << ", Length: " << getLength()
            << ", Max Load Capacity: " << maxLoadCapacity
            << ", Cargo Type: " << cargoType << std::endl;
    }
};

#endif // FREIGHTCARRIAGE_H
