#include "driver.h"
const array<QString,12> Driver::driver_field_names_ = {
       "Driver.\"Name (Track)\"", "Driver.Season", "Driver.Overall", "Driver.Concentration",
       "Driver.Talent", "Driver.Aggresiveness", "Driver.Experience", "Driver.\"Tech. Insight\"",
       "Driver.Stamina", "Driver.Charisma", "Driver.Motivation", "Driver.Weight"
   };

Driver::Driver(): track_(""), season_(0)
{
    stats_.fill(0);
}

void Driver::setMiscValue(DriverMiscSlots slot, const QVariant& value)
{
    switch (slot) {
    case DRIVER_TRACK_NAME: track_ = value.toString(); break;
    case DRIVER_SEASON: season_ = value.toInt(); break;
    default:
        break;
    }
}

void Driver::setStatValue(DriverStatSlots slot, const QVariant &value)
{
    stats_.at(slot) = value.toInt();
}
