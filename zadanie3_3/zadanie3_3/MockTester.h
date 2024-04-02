// MockTester.h
#ifndef MOCK_TESTER_H
#define MOCK_TESTER_H

#include <iostream>
#include <random>
#include "DeliveryManager.h"
#include "Client.h"
#include "Restaurant.h"

class MockTester {
private:
    DeliveryManager& deliveryManager;
    std::vector<Client> clients;
    std::vector<Restaurant> restaurants;

    // Генератор випадкових чисел для імітації вибору
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

public:
    MockTester(DeliveryManager& manager, const std::vector<Client>& clients, const std::vector<Restaurant>& restaurants)
        : deliveryManager(manager), clients(clients), restaurants(restaurants), gen(rd()), dis(0, restaurants.size() - 1) {}

    void runTest() {
        // Имитация выбора ресторана
        Restaurant& selectedRestaurant = restaurants[dis(gen)];

        // Имитация формирования заказа
        std::vector<Dish> dishes = selectedRestaurant.getMenu(); 
        Order newOrder(dishes, selectedRestaurant, deliveryManager.selectCourier(), &clients[0]); // Используем адрес клиента

        // Имитация отправления заказа
        deliveryManager.updateOrderStatus(newOrder, OrderStatus::OutForDelivery);

        // Имитация отслеживания доставки
        deliveryManager.trackDelivery(newOrder);

        // Вывод информации о заказе
        newOrder.displayInfo();
    }

};

#endif // MOCK_TESTER_H
