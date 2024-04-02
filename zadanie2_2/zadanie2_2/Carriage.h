// Carriage.h
#ifndef CARRIAGE_H
#define CARRIAGE_H

#include <string>

class Carriage {
protected:
    int id;
    std::string type;
    double weight;
    double length;

public:
    Carriage(int id, std::string type, double weight, double length)
        : id(id), type(std::move(type)), weight(weight), length(length) {}

    virtual ~Carriage() {}

    // Геттеры
    int getId() const { return id; }
    std::string getType() const { return type; }
    double getWeight() const { return weight; }
    double getLength() const { return length; }

    // Сеттеры
    void setId(int newId) { id = newId; }
    void setType(const std::string& newType) { type = newType; }
    void setWeight(double newWeight) { weight = newWeight; }
    void setLength(double newLength) { length = newLength; }

    // Виртуальные методы для переопределения в производных классах
    virtual void displayInfo() const = 0;
};

#endif // CARRIAGE_H
