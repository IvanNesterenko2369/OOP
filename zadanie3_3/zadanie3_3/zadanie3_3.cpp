// zadanie3_3.cpp
#include <iostream>
#include "Restaurant.h"
#include "Dish.h"
#include "Courier.h"
#include "Client.h"
#include "Order.h"
#include "DeliveryManager.h"
#include "MockTester.h"

int main() {
    setlocale(LC_ALL, "ukr");
    // Ініціалізація тестових даних
    std::vector<Dish> menu = {
        Dish("Піца Маргарита", "Піца Маргарита класична", 9.99, 350, "Пшениця, сир"),
        Dish("Паста карбонара", "Паста з вершковим соусом", 12.50, 300, "Пшениця, яйця")
    };
    Restaurant testRestaurant("Піцерія Піца Плейс", "вул. Головна, 123", "Італійська", 4.5);
    for (const auto& dish : menu) {
        testRestaurant.addDish(dish);
    }

    Courier testCourier("Джон Доу.", "123456789", 4.8, "Велосипед");
    std::vector<Courier> couriers = { testCourier };

    Client testClient("Джейн Сміт", "вул. В'язів, 456", "987654321");
    std::vector<Client> clients = { testClient };

    DeliveryManager manager(couriers);
    MockTester tester(manager, clients, { testRestaurant });

    // Запуск тестування
    tester.runTest();

    return 0;
}
