// Restaurant.h
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>
#include "Dish.h"

class Restaurant {
private:
    std::string name;
    std::string address;
    std::string type;
    double rating;
    std::vector<Dish> menu;

public:
    Restaurant(std::string name, std::string address, std::string type, double rating)
        : name(name), address(address), type(type), rating(rating) {}

    void addDish(const Dish& dish) {
        menu.push_back(dish);
    }

    std::vector<Dish>& getMenu() {
        return menu;
    }

    void displayInfo() const {
        std::cout << "Restaurant Name: " << name << "\n";
        std::cout << "Address: " << address << "\n";
        std::cout << "Type: " << type << "\n";
        std::cout << "Rating: " << rating << "/5\n";
        std::cout << "Menu: " << "\n";
        for (const auto& dish : menu) {
            dish.displayInfo();
        }
    }
};

#endif // RESTAURANT_H
