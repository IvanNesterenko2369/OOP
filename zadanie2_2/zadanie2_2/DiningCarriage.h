#ifndef DININGCARRIAGE_H
#define DININGCARRIAGE_H

#include "Carriage.h"
#include <iostream> 

class DiningCarriage : public Carriage {
private:
    int tablesCount;
    bool hasKitchen;

public:
    DiningCarriage(int id, const std::string& type, double weight, double length, int tablesCount, bool hasKitchen)
        : Carriage(id, type, weight, length), tablesCount(tablesCount), hasKitchen(hasKitchen) {}

    int getTablesCount() const { return tablesCount; }
    bool getHasKitchen() const { return hasKitchen; }
    void setTablesCount(int newTablesCount) { tablesCount = newTablesCount; }
    void setHasKitchen(bool newHasKitchen) { hasKitchen = newHasKitchen; }

    void displayInfo() const override {
        std::cout << "Dining Carriage ID: " << getId()
            << ", Type: " << getType()
            << ", Weight: " << getWeight()
            << ", Length: " << getLength()
            << ", Tables: " << getTablesCount()
            << ", Has Kitchen: " << (getHasKitchen() ? "Yes" : "No") << std::endl;
    }
};

#endif // DININGCARRIAGE_H
