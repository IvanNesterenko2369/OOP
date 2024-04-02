#ifndef PASSENGERCARRIAGE_H
#define PASSENGERCARRIAGE_H

#include "Carriage.h"
#include <string>
#include <iostream>

class PassengerCarriage : public Carriage {
private:
    int seatsCount; // ��������, ��� ����� ���������� ����������, ���� ��� �������� ��� �����.
    std::string comfortLevel;

public:
    PassengerCarriage(int id, const std::string& type, double weight, double length, int seatsCount, const std::string& comfortLevel)
        : Carriage(id, type, weight, length), seatsCount(seatsCount), comfortLevel(comfortLevel) {}

    // ������� � ������� ��� ����� ���������
    int getSeatsCount() const { return seatsCount; }
    std::string getComfortLevel() const { return comfortLevel; }
    void setSeatsCount(int newSeatsCount) { seatsCount = newSeatsCount; }
    void setComfortLevel(const std::string& newComfortLevel) { comfortLevel = newComfortLevel; }

    // �����������, ��� ����� getPassengerCount ���������� ���������� ����, 
    // ��������� ������ ����� ����� ���� ������ ����� ����������.
    int getPassengerCount() const { return seatsCount; }

    // ���������� ������ displayInfo
    void displayInfo() const override {
        std::cout << "������������� ������������ ����������: " << getId()
            << ", ���: " << getType()
            << ", ����: " << getWeight()
            << ", �������: " << getLength()
            << ", ������: " << seatsCount
            << ", �������: " << comfortLevel << std::endl;
    }
};

#endif // PASSENGERCARRIAGE_H
