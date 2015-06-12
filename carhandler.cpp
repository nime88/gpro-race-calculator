#include "carhandler.h"

#include <algorithm>
#include <iostream>

#include <QTableWidget>

CarHandler::CarHandler(): car_(Car),
    power_item_(new QTableWidgetItem()),
    handling_item_(new QTableWidgetItem()),
    acceleration_item_(new QTableWidgetItem())
{
    //TODO make sure this will work (fixed to match c++11
    //array specification, compiler should say something now)
    car_lvl_fields_.fill(new QTableWidgetItem());
    car_wear_fields_.fill(new QTableWidgetItem());
}

void CarHandler::initFields(std::shared_ptr<QWidget> parent)
{
    QTableWidget* temp_table = parent->findChild<QTableWidget*>("car_lvl_table");

    if (temp_table == 0) return;

    // setting up fields
    for(CarHandlerSlots i = CHASSIS_SLOT; i < CHASSIS_SLOT + 11; ++i) {
        car_lvl_fields_.at(i)->setText(QString::number(getCarLvl(i)));
        car_wear_fields_.at(i)->setText(QString::number(getCarWear(i)));
        temp_table->setItem(i-CHASSIS_SLOT,0,car_lvl_fields_.at(i));
        temp_table->setItem(i-CHASSIS_SLOT,1,car_wear_fields_.at(i));
    }

    // then doing same to the power  table
    std::shared_ptr<QTableWidget> temp_table_2 =
            std::shared_ptr<QTableWidget>(parent->findChild<QTableWidget*>("car_power_table"));

    if (temp_table_2 == 0) return;

    // setting up the items
    power_item_->setText(QString::number(getPower()));
    handling_item_->setText(QString::number(getHandling()));
    acceleration_item_->setText(QString::number(getAcceleration()));

    temp_table_2->setItem(0,0,power_item_);
    temp_table_2->setItem(1,0,handling_item_);
    temp_table_2->setItem(2,0,acceleration_item_);
}
