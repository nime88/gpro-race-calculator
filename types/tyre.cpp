#include "tyre.h"

Tyre::Tyre(const QString &tyre_type): type_(2)
{
    QString low_conv = tyre_type.toLower();

    if (low_conv == types.at(0).toLower()) type_ = 0;
    else if (low_conv == types.at(1).toLower())  type_ = 1;
    else if (low_conv == types.at(2).toLower())  type_ = 2;
    else if (low_conv == types.at(3).toLower())  type_ = 3;
    else if (low_conv == types.at(4).toLower())  type_ = 4;
    else type_ = 2;
}
