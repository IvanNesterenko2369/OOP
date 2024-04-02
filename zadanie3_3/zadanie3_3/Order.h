// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "Dish.h"
#include "Restaurant.h"
#include "Courier.h"

// ��������������� ���������� ������ Client
class Client;

enum class OrderStatus {
    Pending,
    Preparing,
    OutForDelivery,
    Delivered
};

class Order {
private:
    std::vector<Dish> dishes;
    double totalAmount;
    OrderStatus status;
    Restaurant restaurant;
    Courier courier;
    Client* client; // ���������� ��������� �� Client

public:
    // �����������
    Order(const std::vector<Dish>& dishes, const Restaurant& restaurant,
        const Courier& courier, Client* client)
        : dishes(dishes), restaurant(restaurant), courier(courier),
        client(client), totalAmount(0.0), status(OrderStatus::Pending) {
        calculateTotal();
    }

    // ������� ����� ��������� ������
    void calculateTotal() {
        totalAmount = 0; // ����� ����� ����� ����� ���������
        for (const auto& dish : dishes) {
            totalAmount += dish.getPrice(); 
        }
    }

    // ��������� ������� ������
    OrderStatus getStatus() const {
        return status;
    }

    // ���������� ������� ������
    void updateStatus(OrderStatus newStatus) {
        status = newStatus;
    }

    // ���������� ������ ��� ����������� ���������� � ������
    void displayInfo() const;
};

#endif // ORDER_H
