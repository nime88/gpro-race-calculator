#include "car.h"

const array<QString, 16> Car::car_lvl_names_ = {"Car.\"Name (Track)\"", "Car.Season", "Car.Power", "Car.Handling",
                                        "Car.Acceleration", "Car.Chassis", "Car.Engine", "Car.\"Front Wing\"",
                                        "Car.\"Rear Wing\"", "Car.Underbody", "Car.Sidepods", "Car.Cooling",
                                        "Car.Gearbox", "Car.Brakes", "Car.Suspension", "Car.Electronics"};

const array<QString,13> Car::car_wear_names_ = {"CarWear.\"Name (Track)\"", "CarWear.Season", "CarWear.\"Front Wing Wear\"",
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
