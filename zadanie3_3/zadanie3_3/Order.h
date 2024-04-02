// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "Dish.h"
#include "Restaurant.h"
#include "Courier.h"

// Предварительное объявление класса Client
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
    Client* client; // Используем указатель на Client

public:
    // Конструктор
    Order(const std::vector<Dish>& dishes, const Restaurant& restaurant,
        const Courier& courier, Client* client)
        : dishes(dishes), restaurant(restaurant), courier(courier),
        client(client), totalAmount(0.0), status(OrderStatus::Pending) {
        calculateTotal();
    }

    // Подсчет общей стоимости заказа
    void calculateTotal() {
        totalAmount = 0; // Сброс общей суммы перед подсчетом
        for (const auto& dish : dishes) {
            totalAmount += dish.getPrice(); 
        }
    }

    // Получение статуса заказа
    OrderStatus getStatus() const {
        return status;
    }

    // Обновление статуса заказа
    void updateStatus(OrderStatus newStatus) {
        status = newStatus;
    }

    // Объявление метода для отображения информации о заказе
    void displayInfo() const;
};

#endif // ORDER_H
