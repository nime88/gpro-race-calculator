#ifndef CAR_H
#define CAR_H

#include <QString>

enum CarSlots { CAR_TRACK_NAME = 0, CAR_SEASON, CAR_POWER, CAR_HANDLING, CAR_ACCELERATION,
                CAR_CHASSIS_LVL, CAR_ENGINE_LVL, CAR_FRONT_WING_LVL, CAR_REAR_WING_LVL, CAR_UNDERBODY_LVL,
                CAR_SIDEPODS_LVL, CAR_COOLING_LVL, CAR_GEARBOX_LVL, CAR_BRAKES_LVL, CAR_SUSPENSION_LVL, CAR_ELECTRONICS_LVL,
                CAR_CHASSIS_WEAR, CAR_ENGINE_WEAR, CAR_FRONT_WING_WEAR, CAR_REAR_WING_WEAR, CAR_UNDERBODY_WEAR,
                CAR_SIDEPODS_WEAR, CAR_COOLING_WEAR, CAR_GEARBOX_WEAR, CAR_BRAKES_WEAR, CAR_SUSPENSION_WEAR,
                CAR_ELECTRONICS_WEAR};

class Car
{
    private:
    // names for database headers (yes the database was created before this program existed)
    static const char car_lvl_names_[] = {"Car.\"Name (Track)\"", "Car.Season", "Car.Power", "Car.Handling",
                                           "Car.Acceleration", "Car.Chassis", "Car.Engine", "Car.\"Front Wing\"",
                                           "Car.\"Rear Wing\"", "Car.Underbody", "Car.Sidepods", "Car.Cooling",
                                           "Car.Gearbox", "Car.Brakes", "Car.Suspension", "Car.Electronics"};
    static const char car_wear_names_[] = {"CarWear.\"Name (Track)\"", "CarWear.Season", "CarWear.\"Front Wing Wear\"",
                                          "CarWear.\"Rear Wing Wear\"", "CarWear.\"Engine Wear\"", "CarWear.\"Brakes Wear\"",
                                          "CarWear.\"Gearbox Wear\"", "CarWear.\"Suspension Wear\"", "CarWear.\"Chassis Wear\"",
                                          "CarWear.\"Cooling Wear\"", "CarWear.\"Electronics Wear\"", "CarWear.\"Sidepods Wear\"",
                                          "CarWear.\"Underbody Wear\""};

    static const int stats_diff = 2;
    static const int lvl_diff_ = 5;
    static const int wear_diff = 16;

    QString track_name_;
    int season_;
    int car_stats_[3];
    int part_lvl_[11];
    int part_wear_[11];

    // lets just make sure we don't accidentially copy car
    Car (const Car&);
    Car& operator=(const Car&);

public:
    Car();

    static const char* const getStatNames() { return car_lvl_names_; }
    static const char* const getWearNames() { return car_wear_names_; }

    // getters
    QString getFieldAsQString(CarSlots slot);
    int getValueBySlot(CarSlots slot);
    inline int getLvlDiff() { return lvl_diff_; }
    inline int getWearDiff() { return wear_diff; }

    // setters
    template <typedef T>
    void setField (const T& value, CarSlots slot) {
        switch (slot) {
            case CAR_TRACK_NAME: track_name_ = value; break;
            case CAR_SEASON: season_ = value; break;
            case CAR_POWER: car_stats_[CAR_POWER-stats_diff] = value; break;
            case CAR_HANDLING: car_stats_[CAR_HANDLING-stats_diff] = value; break;
            case CAR_ACCELERATION: car_stats_[CAR_ACCELERATION-stats_diff] = value; break;
            case CAR_CHASSIS_LVL: part_lvl_[CAR_CHASSIS_LVL-lvl_diff_] = value; break;
            case CAR_ENGINE_LVL: part_lvl_[CAR_ENGINE_LVL-lvl_diff_] = value; break;
            case CAR_FRONT_WING_LVL: part_lvl_[CAR_FRONT_WING_LVL-lvl_diff_] = value; break;
            case CAR_REAR_WING_LVL: part_lvl_[CAR_REAR_WING_LVL-lvl_diff_] = value; break;
            case CAR_UNDERBODY_LVL: part_lvl_[CAR_UNDERBODY_LVL-lvl_diff_] = value; break;
            case CAR_SIDEPODS_LVL: part_lvl_[CAR_SIDEPODS_LVL-lvl_diff_] = value; break;
            case CAR_COOLING_LVL: part_lvl_[CAR_COOLING_LVL-lvl_diff_] = value; break;
            case CAR_GEARBOX_LVL: part_lvl_[CAR_GEARBOX_LVL-lvl_diff_] = value; break;
            case CAR_BRAKES_LVL: part_lvl_[CAR_BRAKES_LVL-lvl_diff_] = value; break;
            case CAR_SUSPENSION_LVL: part_lvl_[CAR_SUSPENSION_LVL-lvl_diff_] = value; break;
            case CAR_ELECTRONICS_LVL: part_lvl_[CAR_ELECTRONICS_LVL-lvl_diff_] = value; break;
            case CAR_CHASSIS_WEAR: part_wear_[CAR_CHASSIS_WEAR-wear_diff] = value; break;
            case CAR_ENGINE_WEAR: part_wear_[CAR_ENGINE_WEAR-wear_diff] = value; break;
            case CAR_FRONT_WING_WEAR: part_wear_[CAR_FRONT_WING_WEAR-wear_diff] = value; break;
            case CAR_REAR_WING_WEAR: part_wear_[CAR_REAR_WING_WEAR-wear_diff] = value; break;
            case CAR_UNDERBODY_WEAR: part_wear_[CAR_UNDERBODY_WEAR-wear_diff] = value; break;
            case CAR_SIDEPODS_WEAR: part_wear_[CAR_SIDEPODS_WEAR-wear_diff] = value; break;
            case CAR_COOLING_WEAR: part_wear_[CAR_COOLING_WEAR-wear_diff] = value; break;
            case CAR_GEARBOX_WEAR: part_wear_[CAR_GEARBOX_WEAR-wear_diff] = value; break;
            case CAR_BRAKES_WEAR: part_wear_[CAR_BRAKES_WEAR-wear_diff] = value; break;
            case CAR_SUSPENSION_WEAR: part_wear_[CAR_SUSPENSION_WEAR-wear_diff] = value; break;
            case CAR_ELECTRONICS_WEAR: part_wear_[CAR_ELECTRONICS_WEAR-wear_diff] = value; break;
        default:
            break;
        }
    }
};

#endif // CAR_H
