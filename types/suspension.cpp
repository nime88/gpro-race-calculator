#include "suspension.h"

Suspension::Suspension(const QString &suspension): type_(1)
{
    QString low_conv = suspension.toLower();

    if (low_conv == types_.at(0).toLower()) type_ = 0;
    else if (low_conv == types_.at(1).toLower())  type_ = 1;
    else if (low_conv == types_.at(2).toLower())  type_ = 2;
    else type_ = 1;
}
