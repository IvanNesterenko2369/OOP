// Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Order.h"
#include <iostream>

class Client {
private:
    std::string name;
    std::string deliveryAddress;
    std::string contactNumber;
    std::vector<Order> orderHistory;

public:
    Client(const std::string& name, const std::string& deliveryAddress, const std::string& contactNumber)
        : name(name), deliveryAddress(deliveryAddress), contactNumber(contactNumber) {}

    void addOrder(const Order& order) {
        orderHistory.push_back(order);
    }

    void displayInfo() const {
        std::cout << "Ім'я клієнта: " << name << "\n"
            << "Адреса доставки: " << deliveryAddress << "\n"
            << "Контактний номер: " << contactNumber << "\n";
        std::cout << "Історія замовлень: \n";
        for (const auto& order : orderHistory) {
            order.displayInfo();
        }
    }
};

#endif // CLIENT_H
