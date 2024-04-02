// Order.cpp
#include "Order.h"
#include "Client.h" 


void Order::displayInfo() const {
    std::cout << "Order Details:\n";
    for (const auto& dish : dishes) {
        dish.displayInfo();
    }
    std::cout << "Total Amount: $" << totalAmount << "\n"
        << "Status: " << static_cast<int>(status) << "\n";
    restaurant.displayInfo();
    courier.displayInfo();
    
    if (client) {
        client->displayInfo();
    }
}
