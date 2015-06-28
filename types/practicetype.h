#ifndef PRACTICETYPE_H
#define PRACTICETYPE_H

#include <QString>

#include <types/tyre.h>
#include <types/weather.h>
#include <types/downforce.h>
#include <types/suspension.h>
#include <types/grip.h>

class PracticeType
{
public:
    PracticeType();
    QString track_name; // name of the track
    double time;
    // settings
    int front_wing;
    int rear_wing;
    int engine;
    int brakes;
    int gear;
    int suspension;
    // practice conditions
    Tyre tyre_type;
    Weather weather;
    int temperature;
    int humidity;
    // track
    int track_power;
    int track_handling;
    int track_acceleration;
    Downforce track_downforce;
    Suspension track_suspension;
    double lap_length;
    int corners;
    Grip grip;
    // car
    int car_power;
    int car_handling;
    int car_acceleration;
    int car_chassis_lvl;
    int car_engine_lvl;
    int car_front_wing_lvl;
    int car_rear_wing_lvl;
    int car_underbody_lvl;
    int car_sidepods_lvl;
    int car_cooling_lvl;
    int car_gearbox_lvl;
    int car_brakes_lvl;
    int car_suspension_lvl;
    int car_electronics_lvl;
    int car_chassis_wear;
    int car_engine_wear;
    int car_front_wing_wear;
    int car_rear_wing_wear;
    int car_underbody_wear;
    int car_sidepods_wear;
    int car_cooling_wear;
    int car_gearbox_wear;
    int car_brakes_wear;
    int car_suspension_wear;
    int car_electronics_wear;
    // driver
    int driver_concentration;
    int driver_talent;
    int driver_aggressiveness;
    int driver_experience;
    int driver_technical_insight;
    int driver_stamina;
    int driver_charisma;
    int driver_motivation;
    int driver_weight;
};

#endif // PRACTICETYPE_H
