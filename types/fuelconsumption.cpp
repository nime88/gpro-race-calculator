#include "fuelconsumption.h"

FuelConsumption::FuelConsumption(const QString& fuel_consumption): type_(2)
{
    QString low_conv = fuel_consumption.toLower();

    if (low_conv == types_.at(0).toLower()) type_ = 0;
    else if (low_conv == types_.at(1).toLower())  type_ = 1;
    else if (low_conv == types_.at(2).toLower())  type_ = 2;
    else if (low_conv == types_.at(3).toLower())  type_ = 3;
    else if (low_conv == types_.at(4).toLower())  type_ = 4;
    else type_ = 2;
}
