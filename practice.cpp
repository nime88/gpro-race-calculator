#include "practice.h"

const array<QString,12> Practice::field_names_  = {"Name (Track)", "Net Time",
                                      "Front Wing", "Rear Wing", "Engine",
                                      "Brakes", "Gear", "Suspension",
                                      "Tyre Type", "Weather", "Temperature",
                                      "Humidity"};

Practice::Practice():
    track_name_(QString("")), time_(0), tyre_type_(QString("")),
    weather_(QString("")), temperature_(0), humidity_(0)

{
    settings_.fill(500);
}

std::shared_ptr<PracticeType> Practice::getValues() {
    std::shared_ptr<PracticeType> temp_v_vec = std::shared_ptr<PracticeType>(new PracticeType());
    // from practice
    temp_v_vec->track_name = track_name_;
    temp_v_vec->time = time_;
    temp_v_vec->front_wing = settings_.at(0);
    temp_v_vec->rear_wing = settings_.at(1);
    temp_v_vec->engine = settings_.at(2);
    temp_v_vec->brakes = settings_.at(3);
    temp_v_vec->gear = settings_.at(4);
    temp_v_vec->suspension = settings_.at(5);
    temp_v_vec->tyre_type = tyre_type_;
    temp_v_vec->weather = (weather_ == "Dry" ? WEATHER_DRY : WEATHER_WET);
    temp_v_vec->temperature = temperature_;
    temp_v_vec->humidity = humidity_;

    // from track
    temp_v_vec->track_power = track_->getTrackQString(TrackSlots::TRACK_POWER).toInt();
    temp_v_vec->track_handling = track_->getTrackQString(TrackSlots::TRACK_HANDLING).toInt();
    temp_v_vec->track_acceleration = track_->getTrackQString(TrackSlots::TRACK_ACCELERATION).toInt();
    Downforce df;
    if (track_->getTrackQString(TrackSlots::TRACK_DOWNFORCE) == "Low") df = DOWNFORCE_LOW;
    else if (track_->getTrackQString(TrackSlots::TRACK_DOWNFORCE) == "High") df = DOWNFORCE_HIGH;
    else df = DOWNFORCE_MEDIUM;
    temp_v_vec->track_downforce = df;
    Suspension susp;
    if (track_->getTrackQString(TrackSlots::TRACK_SUSPENSION) == "Soft") susp = SUSPENSION_SOFT;
    else if (track_->getTrackQString(TrackSlots::TRACK_SUSPENSION) == "Hard") susp = SUSPENSION_HARD;
    else susp = SUSPENSION_MEDIUM;
    temp_v_vec->track_suspension = susp;
    temp_v_vec->lap_length = track_->getTrackQString(TrackSlots::TRACK_LAP_LENGTH).toDouble();
    temp_v_vec->corners = track_->getTrackQString(TrackSlots::TRACK_CORNERS).toInt();
    Grip grippi;
    if (track_->getTrackQString(TrackSlots::TRACK_GRIP) == "Very low") grippi = GRIP_VERY_LOW;
    else if (track_->getTrackQString(TrackSlots::TRACK_GRIP) == "Low") grippi = GRIP_LOW;
    else if (track_->getTrackQString(TrackSlots::TRACK_GRIP) == "High") grippi = GRIP_HIGH;
    else if (track_->getTrackQString(TrackSlots::TRACK_GRIP) == "Very high") grippi = GRIP_VERY_HIGH;
    else grippi = GRIP_MEDIUM;
    temp_v_vec->grip = grippi;

    // from car
    temp_v_vec->car_power = car_->getStat(CAR_POWER);
    temp_v_vec->car_handling = car_->getStat(CAR_HANDLING);
    temp_v_vec->car_acceleration = car_->getStat(CAR_ACCELERATION);
    temp_v_vec->car_chassis_lvl = car_->getLvl(CAR_CHASSIS);
    temp_v_vec->car_engine_lvl = car_->getLvl(CAR_ENGINE);
    temp_v_vec->car_front_wing_lvl = car_->getLvl(CAR_FRONT_WING);
    temp_v_vec->car_rear_wing_lvl = car_->getLvl(CAR_REAR_WING);
    temp_v_vec->car_underbody_lvl = car_->getLvl(CAR_UNDERBODY);
    temp_v_vec->car_sidepods_lvl = car_->getLvl(CAR_SIDEPODS);
    temp_v_vec->car_cooling_lvl = car_->getLvl(CAR_COOLING);
    temp_v_vec->car_gearbox_lvl = car_->getLvl(CAR_GEARBOX);
    temp_v_vec->car_brakes_lvl = car_->getLvl(CAR_BRAKES);
    temp_v_vec->car_suspension_lvl = car_->getLvl(CAR_SUSPENSION);
    temp_v_vec->car_electronics_lvl = car_->getLvl(CAR_ELECTRONICS);

    // from driver
    temp_v_vec->driver_concentration = driver_->getValue(DRIVER_CONCENTRATION);
    temp_v_vec->driver_talent = driver_->getValue(DRIVER_TALENT);
    temp_v_vec->driver_aggressiveness = driver_->getValue(DRIVER_AGGRESSIVENESS);
    temp_v_vec->driver_experience = driver_->getValue(DRIVER_EXPERIENCE);
    temp_v_vec->driver_technical_insight = driver_->getValue(DRIVER_TECHNICAL_INSIGHT);
    temp_v_vec->driver_stamina = driver_->getValue(DRIVER_STAMINA);
    temp_v_vec->driver_charisma = driver_->getValue(DRIVER_CHARISMA);
    temp_v_vec->driver_motivation = driver_->getValue(DRIVER_MOTIVATION);
    temp_v_vec->driver_weight = driver_->getValue(DRIVER_WEIGHT);

    return temp_v_vec;
}

void Practice::setValue(PracticeSlots slot, const QVariant& value)
{
    switch (slot) {
    case PRACTICE_BRAKES:  settings_.at(3) = value.toInt(); break;
        case PRACTICE_ENGINE: settings_.at(2) = value.toInt();  break;
        case PRACTICE_FRONT_WING: settings_.at(0) = value.toInt();  break;
        case PRACTICE_GEAR: settings_.at(4) = value.toInt();  break;
        case PRACTICE_HUMIITY: humidity_ = value.toInt();  break;
    case PRACTICE_NET_TIME: {
        QString temp_string = value.toString();
        double mins = temp_string.section("",0,0).toDouble();
        double secs = temp_string.section("",2,3).toDouble();
        double hunds = temp_string.section("",5,7).toDouble();
        time_ = mins * 60 + secs + hunds / 1000;
        break;
    }
        case PRACTICE_REAR_WING: settings_.at(1) = value.toInt(); break;
        case PRACTICE_SUSPENSION: settings_.at(5) = value.toInt();  break;
        case PRACTICE_TEMPERATURE: temperature_ = value.toInt();  break;
        case PRACTICE_TRACK_NAME: break;
        case PRACTICE_TYRE_TYPE: tyre_type_ = value.toString();  break;
        case PRACTICE_WEATHER: weather_ = value.toString();  break;
    default:
        break;
    }
}
