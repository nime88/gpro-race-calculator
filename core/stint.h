#ifndef STINT_H
#define STINT_H

#include <memory>

#include <QString>

#include <types/tyre.h>
#include <types/weather.h>
#include <core/track.h>
#include <core/car.h>
#include <core/driver.h>

class Stint
{
private:
    const static array<QString,10> field_names_;

    // identifiers
    QString track_name;

    int laps_;
    double fuel_;
    double consumption_;
    int final_percentage_;
    int humidity_;
    int temperature_;
    Tyre tyre_type_;
    Weather weather_;
    double km_;

    std::shared_ptr<Track> track_;
    std::shared_ptr<Car> car_;
    std::shared_ptr<Driver> driver_;

public:
    Stint();

    inline static const array<QString,10>& getColumnNames() { return field_names_; }
};

#endif // STINT_H
