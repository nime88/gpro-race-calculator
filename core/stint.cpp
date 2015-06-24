#include "core/stint.h"

const array<QString,10> Stint::field_names_ = { "Name (Track)", "SLaps", "SFuel", "SConsumption", "SFinalP",
                                              "SHumidity", "STemperature", "STyreType", "SWeather", "SKm"};

Stint::Stint(): track_name(""), laps_(0), fuel_(0), consumption_(0), final_percentage_(0),
   humidity_(0),  temperature_(0), tyre_type_(""), weather_(""), km_(0),
   track_(0), car_(0), driver_(0)
{
}
