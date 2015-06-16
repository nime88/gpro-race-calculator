#ifndef PRACTICETYPE_H
#define PRACTICETYPE_H

#include <QString>

enum Weather { WEATHER_DRY = 0, WEATHER_WET = 1 };
enum Downforce { DOWNFORCE_LOW = -1, DOWNFORCE_MEDIUM = 0, DOWNFORCE_HIGH = 1 };
enum Grip { GRIP_VERY_LOW = -2, GRIP_LOW = -1, GRIP_MEDIUM = 0, GRIP_HIGH = 1, GRIP_VERY_HIGH = 2 };
enum Suspension { SUSPENSION_SOFT = -1, SUSPENSION_MEDIUM = 0, SUSPENSION_HARD = 1 };

typedef struct
{
    QString track_name; // name of the track
    double time; // practice time TODO change to double
    // settings
    int front_wing;
    int rear_wing;
    int engine;
    int brakes;
    int gear;
    int suspension;
    // practice conditions
    QString tyre_type; // TODO change to enum
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
}PracticeType;

#endif // PRACTICETYPE_H
