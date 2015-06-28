#ifndef STINTTYPE_H
#define STINTTYPE_H

#include <QString>

#include <types/tyre.h>
#include <types/weather.h>
#include <types/downforce.h>
#include <types/suspension.h>
#include <types/grip.h>
#include <types/tyrewear.h>

class StintType
{
public:
    StintType();
    QString track_name;
    // stint values
    int laps;
    double fuel;
    double consumption;
    int final_percentage;
    double humidity;
    double temperature;
    Tyre tyre_type;
    Weather weather;
    double km;
    //risk
    int risk_clear;
    int risk_wet;
    int risk_defend;
    int risk_malfunction;
    int risk_overtake;
    // track
    int track_power;
    int track_handling;
    int track_acceleration;
    Downforce track_downforce;
    Suspension track_suspension;
    TyreWear track_tyre_wear;
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

#endif // STINTTYPE_H
