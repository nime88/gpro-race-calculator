#include "cargroupbox.h"

CarGroupBox::CarGroupBox(QWidget *parent):
    QGroupBox(parent),
    car_lvl_items_(0),
    car_power_items_(0)
{
}

void CarGroupBox::init()
{
    // initializing tables
    car_lvl_items_ = this->findChild<QTableWidget*>("car_lvl_table");
    for (int i = 0; i < car_lvl_items_->rowCount(); ++i) {
        car_lvl_items_->setItem(i,0, new QTableWidgetItem());
        car_lvl_items_->item(i,0)->setText("0");
    }
    for (int i = 0; i < car_lvl_items_->rowCount(); ++i) {
        car_lvl_items_->setItem(i,1, new QTableWidgetItem());
        car_lvl_items_->item(i,1)->setText("0");
    }

    car_power_items_ = this->findChild<QTableWidget*>("car_power_table");
    for (int i = 0; i < car_power_items_->rowCount(); ++i) {
        car_power_items_->setItem(i,0, new QTableWidgetItem());
        car_power_items_->item(i,0)->setText("0");
    }
}

void CarGroupBox::carPartChanged(QTableWidgetItem *item)
{
    bool can_convert = false;
    int value = item->text().toInt(&can_convert);

    int column = item->column();
    int row = item->row();

    if (can_convert && column == 0) {
        if (value < 1) value = 1;
        else if (value > 9) value = 9;
    } else if (can_convert && column == 1) {
        if (value < 0) value = 0;
        else if (value > 99) value = 99;
    } else {
        value = 0;
    }

    if (column == 0) car_lvl_.at(row) = value;
    else car_wear_.at(row) = value;

    item->setText(QString::number(value));
}

void CarGroupBox::carAbilityChanged(QTableWidgetItem *item)
{
    bool can_convert = false;
    int value = item->text().toInt(&can_convert);

    if (can_convert) {
        if (value < 1) value = 1;
        else if (value > 250) value = 250;
    } else if (can_convert && item->column() == 1) {
        if (value < 0) value = 0;
        else if (value > 250) value = 250;
    } else {
        value = 0;
    }

    car_power_.at(item->row()) = value;
    item->setText(QString::number(value));
}
