// Train.h
#ifndef TRAIN_H
#define TRAIN_H

#include "Carriage.h"
#include <string>
#include <iostream>
#include <vector>

class Train {
private:
    // ����������� ���� ��� �������� ������
    struct Node {
        Carriage* data;
        Node* next;
        Node(Carriage* data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head; // ������ ������ �������
    std::string name;
    std::string routeNumber;

public:
    Train(const std::string& name, const std::string& routeNumber)
        : head(nullptr), name(name), routeNumber(routeNumber) {}

    ~Train();

    // ������ ��� ������ �� ������� �������
    void addCarriageAtEnd(Carriage* carriage);
    void addCarriageAtStart(Carriage* carriage);
    void insertCarriageAt(Carriage* carriage, int index);
    Carriage* removeCarriageAtEnd();
    Carriage* removeCarriageAtStart();
    Carriage* removeCarriageById(int carriageId);
    Carriage* getCarriageAt(int index) const;
    int findCarriageIndexById(int carriageId) const;

    // ������������ �������
    int getTotalNumberOfPassengers() const;
    Carriage* getCarriageWithMaxCapacity() const;
    std::vector<Carriage*> getCarriagesByType(const std::string& type) const;

    // ����� ��� ������ ���������� � ���� ������� � ������
    void printAllCarriagesInfo() const;

    // �������������� ������� � �������
    std::string getName() const { return name; }
    std::string getRouteNumber() const { return routeNumber; }
    void setName(const std::string& newName) { name = newName; }
    void setRouteNumber(const std::string& newRouteNumber) { routeNumber = newRouteNumber; }
};

#endif // TRAIN_H
