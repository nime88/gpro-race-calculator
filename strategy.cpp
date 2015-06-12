#include "strategy.h"

#include <QTableWidget>

Strategy::Strategy():
    q1_temperature_(0), q2_temperature_(0), race_temperature_(0.0),
    q1_humidity_(0), q2_humidity_(0), race_humidity_(0.0),
    q1_temperature_item_(0), q2_temperature_item_(0), race_temperature_item_(0),
    q1_humidity_item_(0), q2_humidity_item_(0), race_humidity_item_(0)
{
}

void Strategy::initFields(std::shared_ptr<QWidget> parent)
{
    QTableWidget* temp_table = parent->findChild<QTableWidget*>("weather_table");

    if (temp_table == 0) return;

    // setting up the items
    q1_temperature_item_ = new QTableWidgetItem();
    q1_temperature_item_->setText(QString::number(getQ1Temperature()));
    q2_temperature_item_ = new QTableWidgetItem();
    q2_temperature_item_->setText(QString::number(getQ2Temperature()));
    race_temperature_item_ = new QTableWidgetItem();
    race_temperature_item_->setText(QString::number(getRaceTemperature()));
    q1_humidity_item_ = new QTableWidgetItem();
    q1_humidity_item_->setText(QString::number(getQ1Humidity()));
    q2_humidity_item_ = new QTableWidgetItem();
    q2_humidity_item_->setText(QString::number(getQ2Humidity()));
    race_humidity_item_ = new QTableWidgetItem();
    race_humidity_item_->setText(QString::number(getRaceHumidity()));

    temp_table->setItem(0,0,q1_temperature_item_);
    temp_table->setItem(1,0,q2_temperature_item_);
    temp_table->setItem(2,0,race_temperature_item_);
    temp_table->setItem(0,1,q1_humidity_item_);
    temp_table->setItem(1,1,q2_humidity_item_);
    temp_table->setItem(2,1,race_humidity_item_);
}
