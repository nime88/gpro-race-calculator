#include "carhandler.h"

#include <algorithm>
#include <iostream>

#include <QTableWidget>

CarHandler::CarHandler(): car_(Car), car_group_box_(0)
{
    car_lvl_.fill(0);
    car_wear_.fill(0);
    car_power_.fill(0);
}

void CarHandler::initFields(CarGroupBox* parent)
{
    car_group_box_ = parent;

    car_lvl_ = car_group_box_->getCarLvl();
    car_wear_ = car_group_box_->getCarWear();
    car_power_ = car_group_box_->getCarAbility();
}
