// DeliveryManager.h
#ifndef DELIVERY_MANAGER_H
#define DELIVERY_MANAGER_H

#include <vector>
#include "Courier.h"
#include "Order.h"

class DeliveryManager {
private:
    std::vector<Courier> couriers;

public:
    DeliveryManager(const std::vector<Courier>& couriers) : couriers(couriers) {}

    Courier& selectCourier() {
        // ����� ������ ���'��� - ��� ��������� �������� ������� ����������.
        return couriers[0];
    }

    void updateOrderStatus(Order& order, OrderStatus status) {
        order.updateStatus(status);
    }

    void trackDelivery(const Order& order) {
        // ����� ���������� �������� ���������� - ��� ������������ ������ �������� ������.
        std::cout << "³��������� ����������. �������� ������: " << static_cast<int>(order.getStatus()) << "\n"; 
    }
};

#endif // DELIVERY_MANAGER_H
