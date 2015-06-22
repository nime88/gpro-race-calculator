#include "driver.h"
const array<QString,11> Driver::driver_field_names_ = {
       "Name (Track)", "Overall", "Concentration",
       "Talent", "Aggresiveness", "Experience", "Tech. Insight",
       "Stamina", "Charisma", "Motivation", "Weight"
   };

Driver::Driver(): track_("")
{
    stats_.fill(0);
}

void Driver::setMiscValue(DriverMiscSlots slot, const QVariant& value)
{
    switch (slot) {
    case DRIVER_TRACK_NAME: track_ = value.toString(); break;
    default:
        break;
    }
}

void Driver::setStatValue(DriverStatSlots slot, const QVariant &value)
{
    stats_.at(slot) = value.toInt();
}
