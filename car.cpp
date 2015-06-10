#include "car.h"

Car::Car()
{
}

QString Car::getFieldAsQString(CarSlots slot)
{
    switch (slot) {
        case CAR_TRACK_NAME: return track_name_;
        case CAR_SEASON: return QString::number(season_);
        case CAR_POWER: return QString::number(car_stats_[CAR_POWER-stats_diff]);
        case CAR_HANDLING: return QString::number(car_stats_[CAR_HANDLING-stats_diff]);
        case CAR_ACCELERATION: return QString::number(car_stats_[CAR_ACCELERATION-stats_diff]);
        case CAR_CHASSIS_LVL: return QString::number(part_lvl_[CAR_CHASSIS_LVL-lvl_diff_]);
        case CAR_ENGINE_LVL: return QString::number(part_lvl_[CAR_ENGINE_LVL-lvl_diff_]);
        case CAR_FRONT_WING_LVL: return QString::number(part_lvl_[CAR_FRONT_WING_LVL-lvl_diff_]);
        case CAR_REAR_WING_LVL: return QString::number(part_lvl_[CAR_REAR_WING_LVL-lvl_diff_]);
        case CAR_UNDERBODY_LVL: return QString::number(part_lvl_[CAR_UNDERBODY_LVL-lvl_diff_]);
        case CAR_SIDEPODS_LVL: return QString::number(part_lvl_[CAR_SIDEPODS_LVL-lvl_diff_]);
        case CAR_COOLING_LVL: return QString::number(part_lvl_[CAR_COOLING_LVL-lvl_diff_]);
        case CAR_GEARBOX_LVL: return QString::number(part_lvl_[CAR_GEARBOX_LVL-lvl_diff_]);
        case CAR_BRAKES_LVL: return QString::number(part_lvl_[CAR_BRAKES_LVL-lvl_diff_]);
        case CAR_SUSPENSION_LVL: return QString::number(part_lvl_[CAR_SUSPENSION_LVL-lvl_diff_]);
        case CAR_ELECTRONICS_LVL: return QString::number(part_lvl_[CAR_ELECTRONICS_LVL-lvl_diff_]);
        case CAR_CHASSIS_WEAR: return QString::number(part_wear_[CAR_CHASSIS_WEAR-wear_diff]);
        case CAR_ENGINE_WEAR: return QString::number(part_wear_[CAR_ENGINE_WEAR-wear_diff]);
        case CAR_FRONT_WING_WEAR: return QString::number(part_wear_[CAR_FRONT_WING_WEAR-wear_diff]);
        case CAR_REAR_WING_WEAR: return QString::number(part_wear_[CAR_REAR_WING_WEAR-wear_diff]);
        case CAR_UNDERBODY_WEAR: return QString::number(part_wear_[CAR_UNDERBODY_WEAR-wear_diff]);
        case CAR_SIDEPODS_WEAR: return QString::number(part_wear_[CAR_SIDEPODS_WEAR-wear_diff]);
        case CAR_COOLING_WEAR: return QString::number(part_wear_[CAR_COOLING_WEAR-wear_diff]);
        case CAR_GEARBOX_WEAR: return QString::number(part_wear_[CAR_GEARBOX_WEAR-wear_diff]);
        case CAR_BRAKES_WEAR: return QString::number(part_wear_[CAR_BRAKES_WEAR-wear_diff]);
        case CAR_SUSPENSION_WEAR: return QString::number(part_wear_[CAR_SUSPENSION_WEAR-wear_diff]);
        case CAR_ELECTRONICS_WEAR: return QString::number(part_wear_[CAR_ELECTRONICS_WEAR-wear_diff]);
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
        case CAR_POWER: return car_stats_[CAR_POWER-stats_diff];
        case CAR_HANDLING: return car_stats_[CAR_HANDLING-stats_diff];
        case CAR_ACCELERATION: return car_stats_[CAR_ACCELERATION-stats_diff];
        case CAR_CHASSIS_LVL: return part_lvl_[CAR_CHASSIS_LVL-lvl_diff_];
        case CAR_ENGINE_LVL: return part_lvl_[CAR_ENGINE_LVL-lvl_diff_];
        case CAR_FRONT_WING_LVL: return part_lvl_[CAR_FRONT_WING_LVL-lvl_diff_];
        case CAR_REAR_WING_LVL: return part_lvl_[CAR_REAR_WING_LVL-lvl_diff_];
        case CAR_UNDERBODY_LVL: return part_lvl_[CAR_UNDERBODY_LVL-lvl_diff_];
        case CAR_SIDEPODS_LVL: return part_lvl_[CAR_SIDEPODS_LVL-lvl_diff_];
        case CAR_COOLING_LVL: return part_lvl_[CAR_COOLING_LVL-lvl_diff_];
        case CAR_GEARBOX_LVL: return part_lvl_[CAR_GEARBOX_LVL-lvl_diff_];
        case CAR_BRAKES_LVL: return part_lvl_[CAR_BRAKES_LVL-lvl_diff_];
        case CAR_SUSPENSION_LVL: return part_lvl_[CAR_SUSPENSION_LVL-lvl_diff_];
        case CAR_ELECTRONICS_LVL: return part_lvl_[CAR_ELECTRONICS_LVL-lvl_diff_];
        case CAR_CHASSIS_WEAR: return part_wear_[CAR_CHASSIS_WEAR-wear_diff];
        case CAR_ENGINE_WEAR: return part_wear_[CAR_ENGINE_WEAR-wear_diff];
        case CAR_FRONT_WING_WEAR: return part_wear_[CAR_FRONT_WING_WEAR-wear_diff];
        case CAR_REAR_WING_WEAR: return part_wear_[CAR_REAR_WING_WEAR-wear_diff];
        case CAR_UNDERBODY_WEAR: return part_wear_[CAR_UNDERBODY_WEAR-wear_diff];
        case CAR_SIDEPODS_WEAR: return part_wear_[CAR_SIDEPODS_WEAR-wear_diff];
        case CAR_COOLING_WEAR: return part_wear_[CAR_COOLING_WEAR-wear_diff];
        case CAR_GEARBOX_WEAR: return part_wear_[CAR_GEARBOX_WEAR-wear_diff];
        case CAR_BRAKES_WEAR: return part_wear_[CAR_BRAKES_WEAR-wear_diff];
        case CAR_SUSPENSION_WEAR: return part_wear_[CAR_SUSPENSION_WEAR-wear_diff];
        case CAR_ELECTRONICS_WEAR: return part_wear_[CAR_ELECTRONICS_WEAR-wear_diff];
    default:
        break;
    }
}
