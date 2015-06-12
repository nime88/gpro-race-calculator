#include "driver.h"
const array<string,12> Driver::driver_field_names_ = {
       "Driver.\"Name (Track)\"", "Driver.Season", "Driver.Overall", "Driver.Concentration",
       "Driver.Talent", "Driver.Aggresiveness", "Driver.Experience", "Driver.\"Tech. Insight\"",
       "Driver.Stamina", "Driver.Charisma", "Driver.Motivation", "Driver.Weight"
   };

Driver::Driver(): track_(""), season_(0)
{
    stats_.fill(0);
}
