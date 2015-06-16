#ifndef CARGROUPBOX_H
#define CARGROUPBOX_H

#include <memory>
#include <array>
using std::array;

#include <QGroupBox>
#include <QTableWidget>

#include "car.h"
#include "carhandler.h"

class CarHandler;

class CarGroupBox : public QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<Car> car_;
    std::shared_ptr<CarHandler> car_handler_;

    array<int,11> car_lvl_;
    array<int,11> car_wear_;
    array<int,3> car_power_;

    QTableWidget* car_lvl_items_;
    QTableWidget* car_power_items_;

public:
    CarGroupBox(QWidget* parent);

    void setHandlers(std::shared_ptr<CarHandler> car_handler) { car_handler_ = car_handler; }
    void setCar(std::shared_ptr<Car> car) { car_ = car; }

    const array<int,11>& getCarLvl() { return car_lvl_; }
    const array<int,11>& getCarWear() { return car_wear_; }
    const array<int,3>& getCarAbility() { return car_power_; }

public slots:
    void carPartChanged(QTableWidgetItem* item);
    void carAbilityChanged(QTableWidgetItem* item);
};

#endif // CARGROUPBOX_H
