#include "Train.h"
#include "PassengerCarriage.h"
#include "FreightCarriage.h"
#include "DiningCarriage.h"
#include "SleepingCarriage.h"

int main() {
    // Создание вагонов
    PassengerCarriage pCarriage(1, "Пасажир", 50000, 30, 100, "Комфорт");
    FreightCarriage fCarriage(2, "Вантажні перевезення", 60000, 35, 20000, "Вугілля");
    DiningCarriage dCarriage(3, "Їдальня", 30000, 25, 20, true);
    SleepingCarriage sCarriage(4, "Спати", 40000, 20, 10, true);

    // Создание поезда
    Train train("Express", "A1");

    // Добавление вагонов в поезд
    train.addCarriageAtStart(&pCarriage);
    train.addCarriageAtEnd(&fCarriage);
    train.addCarriageAtStart(&dCarriage);
    train.addCarriageAtEnd(&sCarriage);

    // Печать информации о вагонах
    train.printAllCarriagesInfo();

    // Пример агрегации данных
    std::cout << "Загальна кількість пасажирів: " << train.getTotalNumberOfPassengers() << std::endl;
    Carriage* maxCapacityCarriage = train.getCarriageWithMaxCapacity();
    if (maxCapacityCarriage) {
        std::cout << "Візок з максимальною вантажопідйомністю ID: " << maxCapacityCarriage->getId() << std::endl;
    }

    

    return 0;
}
