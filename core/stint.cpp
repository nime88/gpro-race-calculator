#include "core/stint.h"

const array<QString,15> Stint::field_names_ = { "Name (Track)", "SLaps", "SFuel", "SConsumption", "SFinalP",
                                              "SHumidity", "STemperature", "STyreType", "SWeather", "SKm",
                                              "RClear", "RWet", "RDefend", "RMalfunction", "ROvertake"};

Stint::Stint(): track_name(""), laps_(0), fuel_(0), consumption_(0), final_percentage_(0),
   humidity_(0),  temperature_(0), tyre_type_(""), weather_(""), km_(0),
   risk_clear_(0), risk_wet_(0), risk_defend_(0), risk_malfunction_(0), risk_overtake_(0),
   track_(0), car_(0), driver_(0)
{
}

std::shared_ptr<StintType> Stint::getValues()
{
    std::shared_ptr<StintType> temp_type = std::shared_ptr<StintType>(new StintType);

    temp_type->track_name = track_name;

    temp_type->laps = laps_;
    temp_type->fuel = fuel_;
    temp_type->consumption = consumption_;
    temp_type->final_percentage = final_percentage_;
    temp_type->humidity = humidity_;
    temp_type->temperature = temperature_;
    temp_type->tyre_type = tyre_type_;
    temp_type->weather = weather_;
    temp_type->km = km_;

    temp_type->risk_clear = risk_clear_;
    temp_type->risk_defend = risk_defend_;
    temp_type->risk_malfunction = risk_malfunction_;
    temp_type->risk_overtake = risk_overtake_;
    temp_type->risk_wet = risk_wet_;

    if (car_ != 0) {
        temp_type->car_acceleration = car_->getStat(CAR_ACCELERATION);
        temp_type->car_brakes_lvl = car_->getLvl(CAR_BRAKES);
        temp_type->car_brakes_wear = car_->getWear(CAR_BRAKES);
        temp_type->car_chassis_lvl = car_->getLvl(CAR_CHASSIS);
        temp_type->car_chassis_wear = car_->getWear(CAR_CHASSIS);

        temp_type->car_cooling_lvl = car_->getLvl(CAR_COOLING);
        temp_type->car_cooling_wear = car_->getWear(CAR_COOLING);
        temp_type->car_electronics_lvl = car_->getLvl(CAR_ELECTRONICS);
        temp_type->car_electronics_wear = car_->getWear(CAR_ELECTRONICS);
        temp_type->car_engine_lvl = car_->getLvl(CAR_ENGINE);
        temp_type->car_engine_wear = car_->getWear(CAR_ENGINE);

        temp_type->car_front_wing_lvl = car_->getLvl(CAR_FRONT_WING);
        temp_type->car_front_wing_wear = car_->getWear(CAR_FRONT_WING);
        temp_type->car_gearbox_lvl = car_->getLvl(CAR_GEARBOX);
        temp_type->car_gearbox_wear = car_->getWear(CAR_GEARBOX);
        temp_type->car_handling = car_->getStat(CAR_HANDLING);
        temp_type->car_power = car_->getStat(CAR_POWER);

        temp_type->car_rear_wing_lvl = car_->getLvl(CAR_REAR_WING);
        temp_type->car_rear_wing_wear = car_->getWear(CAR_REAR_WING);
        temp_type->car_sidepods_lvl = car_->getLvl(CAR_SIDEPODS);
        temp_type->car_sidepods_wear = car_->getWear(CAR_SIDEPODS);
        temp_type->car_suspension_lvl = car_->getLvl(CAR_SUSPENSION);
        temp_type->car_suspension_wear = car_->getWear(CAR_SUSPENSION);

        temp_type->car_underbody_lvl = car_->getLvl(CAR_UNDERBODY);
        temp_type->car_underbody_wear = car_->getWear(CAR_UNDERBODY);
    }

    if (driver_ != 0) {
        temp_type->driver_aggressiveness = driver_->getValue(DRIVER_AGGRESSIVENESS);
        temp_type->driver_charisma = driver_->getValue(DRIVER_CHARISMA);
        temp_type->driver_concentration = driver_->getValue(DRIVER_CONCENTRATION);
        temp_type->driver_experience = driver_->getValue(DRIVER_EXPERIENCE);
        temp_type->driver_motivation = driver_->getValue(DRIVER_MOTIVATION);
        temp_type->driver_stamina = driver_->getValue(DRIVER_STAMINA);
        temp_type->driver_talent = driver_->getValue(DRIVER_TALENT);
        temp_type->driver_technical_insight = driver_->getValue(DRIVER_TECHNICAL_INSIGHT);
        temp_type->driver_weight = driver_->getValue(DRIVER_WEIGHT);
    }

    if (track_ != 0) {
        // from track
        temp_type->track_power = track_->getTrackQString(TrackSlots::TRACK_POWER).toInt();
        temp_type->track_handling = track_->getTrackQString(TrackSlots::TRACK_HANDLING).toInt();
        temp_type->track_acceleration = track_->getTrackQString(TrackSlots::TRACK_ACCELERATION).toInt();
        temp_type->track_downforce = Downforce(track_->getTrackQString(TrackSlots::TRACK_DOWNFORCE));
        temp_type->track_suspension = Suspension(track_->getTrackQString(TrackSlots::TRACK_SUSPENSION));
        temp_type->track_tyre_wear = TyreWear(track_->getTrackQString(TrackSlots::TRACK_TYRE_WEAR));
        temp_type->lap_length = track_->getTrackQString(TrackSlots::TRACK_LAP_LENGTH).toDouble();
        temp_type->corners = track_->getTrackQString(TrackSlots::TRACK_CORNERS).toInt();
        temp_type->grip = Grip(track_->getTrackQString(TrackSlots::TRACK_GRIP));
    }

    return temp_type;
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
