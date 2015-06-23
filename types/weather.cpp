#include "weather.h"

Weather::Weather(const QString &weather): type_(0)
{
    QString low_conv = weather.toLower();

    if (low_conv == types.at(0).toLower()) type_ = 0;
    else if (low_conv == types.at(1).toLower())  type_ = 1;
    else type_ = 0;
}
