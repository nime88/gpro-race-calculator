#ifndef PRACTICE_H
#define PRACTICE_H

#include <QString>
#include <practicetype.h>
#include <memory>
#include <vector>
#include <array>
using std::array;

#include "core/track.h"
#include "core/car.h"
#include "core/driver.h"

enum PracticeSlots { PRACTICE_TRACK_NAME = 0, PRACTICE_NET_TIME, PRACTICE_FRONT_WING, PRACTICE_REAR_WING,
                      PRACTICE_ENGINE, PRACTICE_BRAKES, PRACTICE_GEAR, PRACTICE_SUSPENSION, PRACTICE_TYRE_TYPE,
                      PRACTICE_WEATHER, PRACTICE_TEMPERATURE, PRACTICE_HUMIITY
                    };

class Practice
{
private:
    const static array<QString,12> field_names_;

    // identifiers
    QString track_name_;

    double time_;
    // settings
    array<int,6> settings_;
    // conditions
    QString tyre_type_;
    QString weather_;
    int temperature_;
    int humidity_;

    std::shared_ptr<Track> track_;
    std::shared_ptr<Car> car_;
    std::shared_ptr<Driver> driver_;

    //disabling random copying
    Practice (const Practice&);
    Practice operator=(const Practice&);

public:
    Practice();

    // getters
    std::shared_ptr<PracticeType> getValues();

    // setters
    void setValue(PracticeSlots slot, const QVariant &value);
    inline void setTrack(std::shared_ptr<Track> track) { track_ = track; }
    inline void setCar(std::shared_ptr<Car> car) { car_ = car; }
    inline void setDriver(std::shared_ptr<Driver> driver) { driver_ = driver; }

    inline static const array<QString,12>& getColumnNames() { return field_names_; }
};

#endif // PRACTICE_H
