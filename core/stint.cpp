#include "core/stint.h"

const array<QString,15> Stint::field_names_ = { "Name (Track)", "SLaps", "SFuel", "SConsumption", "SFinalP",
                                              "SHumidity", "STemperature", "STyreType", "SWeather", "SKm",
                                              "RClear", "RWet", "RDefend", "RMalfunction", "ROvertake"};

Stint::Stint(): track_name(""), laps_(0), fuel_(0), consumption_(0), final_percentage_(0),
   humidity_(0),  temperature_(0), tyre_type_(""), weather_(""), km_(0),
   track_(0), car_(0), driver_(0)
{
}

void Stint::setValue(StintSlots slot, const QVariant& value)
{
    switch (slot) {
    case STINT_CONSUMPTION:  consumption_ = value.toDouble(); break;
        case STINT_FINAL_PERCENTAGE:  final_percentage_ = value.toInt(); break;
        case STINT_FUEL:  fuel_ = value.toDouble(); break;
        case STINT_HUMIDITY:  humidity_ = value.toDouble(); break;
        case STINT_KM:  km_ = value.toDouble(); break;

        case STINT_LAPS:  laps_ = value.toInt(); break;
        case STINT_TEMPERATURE:  temperature_ = value.toDouble(); break;
        case STINT_TRACK_NAME:  track_name = value.toString(); break;
        case STINT_TYRE_TYPE:  tyre_type_ = Tyre(value.toString()); break;
        case STINT_WEATHER:  weather_ = Weather(value.toString()); break;

        case RISK_CLEAR:  risk_clear_ = value.toInt(); break;
        case RISK_DEFEND:  risk_defend_ = value.toInt(); break;
        case RISK_MALFUNCTION:  risk_malfunction_ = value.toInt(); break;
        case RISK_OVERTAKE:  risk_overtake_ = value.toInt(); break;
        case RISK_WET:  risk_wet_ = value.toInt(); break;
    }
}
