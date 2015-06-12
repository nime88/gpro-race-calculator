#include "car.h"

const array<char, 16> Car::car_lvl_names_ = {"Car.\"Name (Track)\"", "Car.Season", "Car.Power", "Car.Handling",
                                        "Car.Acceleration", "Car.Chassis", "Car.Engine", "Car.\"Front Wing\"",
                                        "Car.\"Rear Wing\"", "Car.Underbody", "Car.Sidepods", "Car.Cooling",
                                        "Car.Gearbox", "Car.Brakes", "Car.Suspension", "Car.Electronics"};

const array<char,13> Car::car_wear_names_ = {"CarWear.\"Name (Track)\"", "CarWear.Season", "CarWear.\"Front Wing Wear\"",
                                        "CarWear.\"Rear Wing Wear\"", "CarWear.\"Engine Wear\"", "CarWear.\"Brakes Wear\"",
                                        "CarWear.\"Gearbox Wear\"", "CarWear.\"Suspension Wear\"", "CarWear.\"Chassis Wear\"",
                                        "CarWear.\"Cooling Wear\"", "CarWear.\"Electronics Wear\"", "CarWear.\"Sidepods Wear\"",
                                        "CarWear.\"Underbody Wear\""};


Car::Car():
    track_name_(""), season_(0)
{
    //TODO make sure these fully fill the table
    car_stats_.fill(0);
    part_lvl_.fill(0);
    part_wear_.fill(0);
}

QString Car::getFieldAsQString(CarSlots slot)
{
    switch (slot) {
        case CAR_TRACK_NAME: return track_name_;
        case CAR_SEASON: return QString::number(season_);
        case CAR_POWER: return QString::number(car_stats_.at(CAR_POWER-stats_diff));
        case CAR_HANDLING: return QString::number(car_stats_.at(CAR_HANDLING-stats_diff));
        case CAR_ACCELERATION: return QString::number(car_stats_.at(CAR_ACCELERATION-stats_diff));
        case CAR_CHASSIS_LVL: return QString::number(part_lvl_.at(CAR_CHASSIS_LVL-lvl_diff_));
        case CAR_ENGINE_LVL: return QString::number(part_lvl_.at(CAR_ENGINE_LVL-lvl_diff_));
        case CAR_FRONT_WING_LVL: return QString::number(part_lvl_.at(CAR_FRONT_WING_LVL-lvl_diff_));
        case CAR_REAR_WING_LVL: return QString::number(part_lvl_.at(CAR_REAR_WING_LVL-lvl_diff_));
        case CAR_UNDERBODY_LVL: return QString::number(part_lvl_.at(CAR_UNDERBODY_LVL-lvl_diff_));
        case CAR_SIDEPODS_LVL: return QString::number(part_lvl_.at(CAR_SIDEPODS_LVL-lvl_diff_));
        case CAR_COOLING_LVL: return QString::number(part_lvl_.at(CAR_COOLING_LVL-lvl_diff_));
        case CAR_GEARBOX_LVL: return QString::number(part_lvl_.at(CAR_GEARBOX_LVL-lvl_diff_));
        case CAR_BRAKES_LVL: return QString::number(part_lvl_.at(CAR_BRAKES_LVL-lvl_diff_));
        case CAR_SUSPENSION_LVL: return QString::number(part_lvl_.at(CAR_SUSPENSION_LVL-lvl_diff_));
        case CAR_ELECTRONICS_LVL: return QString::number(part_lvl_.at(CAR_ELECTRONICS_LVL-lvl_diff_));
        case CAR_CHASSIS_WEAR: return QString::number(part_wear_.at(CAR_CHASSIS_WEAR-wear_diff));
        case CAR_ENGINE_WEAR: return QString::number(part_wear_.at(CAR_ENGINE_WEAR-wear_diff));
        case CAR_FRONT_WING_WEAR: return QString::number(part_wear_.at(CAR_FRONT_WING_WEAR-wear_diff));
        case CAR_REAR_WING_WEAR: return QString::number(part_wear_.at(CAR_REAR_WING_WEAR-wear_diff));
        case CAR_UNDERBODY_WEAR: return QString::number(part_wear_.at(CAR_UNDERBODY_WEAR-wear_diff));
        case CAR_SIDEPODS_WEAR: return QString::number(part_wear_.at(CAR_SIDEPODS_WEAR-wear_diff));
        case CAR_COOLING_WEAR: return QString::number(part_wear_.at(CAR_COOLING_WEAR-wear_diff));
        case CAR_GEARBOX_WEAR: return QString::number(part_wear_.at(CAR_GEARBOX_WEAR-wear_diff));
        case CAR_BRAKES_WEAR: return QString::number(part_wear_.at(CAR_BRAKES_WEAR-wear_diff));
        case CAR_SUSPENSION_WEAR: return QString::number(part_wear_.at(CAR_SUSPENSION_WEAR-wear_diff));
        case CAR_ELECTRONICS_WEAR: return QString::number(part_wear_.at(CAR_ELECTRONICS_WEAR-wear_diff));
    default:
        break;
    }

    return QString();
}

int Car::getValueBySlot(CarSlots slot)
{
    switch (slot) {
        case CAR_TRACK_NAME: return 0;
        case CAR_SEASON: return season_;
        case CAR_POWER: return car_stats_.at(CAR_POWER-stats_diff);
        case CAR_HANDLING: return car_stats_.at(CAR_HANDLING-stats_diff);
        case CAR_ACCELERATION: return car_stats_.at(CAR_ACCELERATION-stats_diff);
        case CAR_CHASSIS_LVL: return part_lvl_.at(CAR_CHASSIS_LVL-lvl_diff_);
        case CAR_ENGINE_LVL: return part_lvl_.at(CAR_ENGINE_LVL-lvl_diff_);
        case CAR_FRONT_WING_LVL: return part_lvl_.at(CAR_FRONT_WING_LVL-lvl_diff_);
        case CAR_REAR_WING_LVL: return part_lvl_.at(CAR_REAR_WING_LVL-lvl_diff_);
        case CAR_UNDERBODY_LVL: return part_lvl_.at(CAR_UNDERBODY_LVL-lvl_diff_);
        case CAR_SIDEPODS_LVL: return part_lvl_.at(CAR_SIDEPODS_LVL-lvl_diff_);
        case CAR_COOLING_LVL: return part_lvl_.at(CAR_COOLING_LVL-lvl_diff_);
        case CAR_GEARBOX_LVL: return part_lvl_.at(CAR_GEARBOX_LVL-lvl_diff_);
        case CAR_BRAKES_LVL: return part_lvl_.at(CAR_BRAKES_LVL-lvl_diff_);
        case CAR_SUSPENSION_LVL: return part_lvl_.at(CAR_SUSPENSION_LVL-lvl_diff_);
        case CAR_ELECTRONICS_LVL: return part_lvl_.at(CAR_ELECTRONICS_LVL-lvl_diff_);
        case CAR_CHASSIS_WEAR: return part_wear_.at(CAR_CHASSIS_WEAR-wear_diff);
        case CAR_ENGINE_WEAR: return part_wear_.at(CAR_ENGINE_WEAR-wear_diff);
        case CAR_FRONT_WING_WEAR: return part_wear_.at(CAR_FRONT_WING_WEAR-wear_diff);
        case CAR_REAR_WING_WEAR: return part_wear_.at(CAR_REAR_WING_WEAR-wear_diff);
        case CAR_UNDERBODY_WEAR: return part_wear_.at(CAR_UNDERBODY_WEAR-wear_diff);
        case CAR_SIDEPODS_WEAR: return part_wear_.at(CAR_SIDEPODS_WEAR-wear_diff);
        case CAR_COOLING_WEAR: return part_wear_.at(CAR_COOLING_WEAR-wear_diff);
        case CAR_GEARBOX_WEAR: return part_wear_.at(CAR_GEARBOX_WEAR-wear_diff);
        case CAR_BRAKES_WEAR: return part_wear_.at(CAR_BRAKES_WEAR-wear_diff);
        case CAR_SUSPENSION_WEAR: return part_wear_.at(CAR_SUSPENSION_WEAR-wear_diff);
        case CAR_ELECTRONICS_WEAR: return part_wear_.at(CAR_ELECTRONICS_WEAR-wear_diff);
    default:
        break;
    }

    return -1;
}
