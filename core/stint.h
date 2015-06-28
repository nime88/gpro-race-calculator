#ifndef STINT_H
#define STINT_H

#include <memory>

#include <QString>

#include <types/tyre.h>
#include <types/weather.h>
#include <types/stinttype.h>
#include <core/track.h>
#include <core/car.h>
#include <core/driver.h>

enum StintSlots{ STINT_TRACK_NAME = 0, STINT_LAPS, STINT_FUEL, STINT_CONSUMPTION, STINT_FINAL_PERCENTAGE,
               STINT_HUMIDITY, STINT_TEMPERATURE, STINT_TYRE_TYPE, STINT_WEATHER, STINT_KM,
               RISK_CLEAR, RISK_WET, RISK_DEFEND, RISK_MALFUNCTION, RISK_OVERTAKE};

class Stint
{
private:
    const static array<QString,15> field_names_;

    // identifiers
    QString track_name;

    int laps_;
    double fuel_;
    double consumption_;
    int final_percentage_;
    double humidity_;
    double temperature_;
    Tyre tyre_type_;
    Weather weather_;
    double km_;

    //risk fields (this i'm just guessing here if I should do own risk class or not
    int risk_clear_;
    int risk_wet_;
    int risk_defend_;
    int risk_malfunction_;
    int risk_overtake_;

    std::shared_ptr<Track> track_;
    std::shared_ptr<Car> car_;
    std::shared_ptr<Driver> driver_;

    // disallowing copying (if at some realm we need
    // to copy this shit we just enable)
    Stint (const Stint&) = delete;
    void operator=(const Stint&) = delete;

public:
    explicit Stint();

    inline static const array<QString,15>& getColumnNames() { return field_names_; }

    // getters
    std::shared_ptr<StintType> getValues();

    void setTrack(std::shared_ptr<Track> track) { track_ = track; }
    void setCar(std::shared_ptr<Car> car) { car_ = car; }
    void setDriver(std::shared_ptr<Driver> driver) { driver_ = driver; }

    void setValue(StintSlots slot, const QVariant &value);
};

#endif // STINT_H
