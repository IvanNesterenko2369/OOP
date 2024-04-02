// Train.cpp
#include "Train.h"
#include "FreightCarriage.h"
#include "PassengerCarriage.h"

Train::~Train() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->data; // Удаляем данные вагона
        delete current; // Удаляем узел
        current = next;
    }
}

void Train::addCarriageAtEnd(Carriage* carriage) {
    Node* newNode = new Node(carriage);
    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Train::addCarriageAtStart(Carriage* carriage) {
    head = new Node(carriage, head);
}

void Train::insertCarriageAt(Carriage* carriage, int index) {
    if (index <= 0) {
        addCarriageAtStart(carriage);
    }
    else {
        Node* current = head;
        for (int i = 0; current != nullptr && i < index - 1; ++i) {
            current = current->next;
        }
        if (current) {
            current->next = new Node(carriage, current->next);
        }
    }
}

Carriage* Train::removeCarriageAtEnd() {
    if (!head) return nullptr;
    if (!head->next) {
        Carriage* carriage = head->data;
        delete head;
        head = nullptr;
        return carriage;
    }
    Node* current = head;
    while (current->next->next) {
        current = current->next;
    }
    Carriage* carriage = current->next->data;
    delete current->next;
    current->next = nullptr;
    return carriage;
}


void Train::printAllCarriagesInfo() const {
    Node* current = head;
    while (current) {
        current->data->displayInfo();
        current = current->next;
    }
}

// Реализация агрегирующих функций

int Train::getTotalNumberOfPassengers() const {
    int total = 0;
    Node* current = head;
    while (current) {
        //  каждый PassengerCarriage имеет метод getPassengerCount()
        if (current->data->getType() == "Пасажир") {
            total += static_cast<PassengerCarriage*>(current->data)->getPassengerCount();
        }
        current = current->next;
    }
    return total;
}

Carriage* Train::getCarriageWithMaxCapacity() const {
    Node* current = head;
    Carriage* maxCarriage = nullptr;
    double maxCapacity = 0;
    while (current) {
        if (current->data->getType() == "Вантажні перевезення") {
            double capacity = static_cast<FreightCarriage*>(current->data)->getMaxLoadCapacity();
            if (capacity > maxCapacity) {
                maxCapacity = capacity;
                maxCarriage = current->data;
            }
        }
        current = current->next;
    }
    return maxCarriage;
}

std::vector<Carriage*> Train::getCarriagesByType(const std::string& type) const {
    std::vector<Carriage*> carriages;
    Node* current = head;
    while (current) {
        if (current->data->getType() == type) {
            carriages.push_back(current->data);
        }
        current = current->next;
    }
    return carriages;
}
