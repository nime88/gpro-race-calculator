#include "handlers/carhandler.h"

#include <algorithm>
#include <iostream>

#include <QTableWidget>

CarHandler::CarHandler(): car_(new Car), dc_group_box_(0)
{
    car_lvl_.fill(0);
    car_wear_.fill(0);
    car_power_.fill(0);
}

void CarHandler::initFields(DCGroupBox *parent)
{
    dc_group_box_ = parent;
}

void CarHandler::setLvls(const array<int, 11> &lvls)
{
    car_lvl_ = lvls;
    car_->setLvl(CAR_CHASSIS, lvls.at(0));
    car_->setLvl(CAR_ENGINE, lvls.at(1));
    car_->setLvl(CAR_FRONT_WING, lvls.at(2));
    car_->setLvl(CAR_REAR_WING, lvls.at(3));
    car_->setLvl(CAR_UNDERBODY, lvls.at(4));
    car_->setLvl(CAR_SIDEPODS, lvls.at(5));
    car_->setLvl(CAR_COOLING, lvls.at(6));
    car_->setLvl(CAR_GEARBOX, lvls.at(7));
    car_->setLvl(CAR_BRAKES, lvls.at(8));
    car_->setLvl(CAR_SUSPENSION, lvls.at(9));
    car_->setLvl(CAR_ELECTRONICS, lvls.at(10));
}

void CarHandler::setWears(const array<int, 11> &wears)
{
    car_wear_ = wears;
    car_->setWear(CAR_CHASSIS, wears.at(0));
    car_->setWear(CAR_ENGINE, wears.at(1));
    car_->setWear(CAR_FRONT_WING, wears.at(2));
    car_->setWear(CAR_REAR_WING, wears.at(3));
    car_->setWear(CAR_UNDERBODY, wears.at(4));
    car_->setWear(CAR_SIDEPODS, wears.at(5));
    car_->setWear(CAR_COOLING, wears.at(6));
    car_->setWear(CAR_GEARBOX, wears.at(7));
    car_->setWear(CAR_BRAKES, wears.at(8));
    car_->setWear(CAR_SUSPENSION, wears.at(9));
    car_->setWear(CAR_ELECTRONICS, wears.at(10));
}

void CarHandler::setStats(const array<int, 3> &stats)
{
    car_power_ = stats;
    car_->setStat(CAR_POWER, stats.at(0));
    car_->setStat(CAR_HANDLING, stats.at(1));
    car_->setStat(CAR_ACCELERATION, stats.at(2));
}
