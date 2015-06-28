#include "stinttype.h"

StintType::StintType(): track_name(""), laps(0), fuel(0), consumption(0), final_percentage(0),
    humidity(0), temperature(0), tyre_type(""), weather(""), km(0),
    risk_clear(0), risk_wet(0), risk_defend(0), risk_malfunction(0), risk_overtake(0),
    track_power(0), track_handling(0), track_acceleration(0), track_downforce(""), track_suspension(""),
    track_tyre_wear(""),
    lap_length(0), corners(0), grip(""),
    car_power(0), car_handling(0), car_acceleration(0), car_chassis_lvl(0), car_engine_lvl(0),
    car_front_wing_lvl(0), car_rear_wing_lvl(0), car_underbody_lvl(0), car_sidepods_lvl(0), car_cooling_lvl(0),
    car_gearbox_lvl(0), car_brakes_lvl(0), car_suspension_lvl(0), car_electronics_lvl(0),
    car_chassis_wear(0), car_engine_wear(0), car_front_wing_wear(0), car_rear_wing_wear(0), car_underbody_wear(0),
    car_sidepods_wear(0), car_cooling_wear(0), car_gearbox_wear(0), car_brakes_wear(0), car_suspension_wear(0),
    car_electronics_wear(0),
    driver_concentration(0), driver_talent(0), driver_aggressiveness(0), driver_experience(0), driver_technical_insight(0),
    driver_stamina(0), driver_charisma(0), driver_motivation(0), driver_weight(0)
{
}
