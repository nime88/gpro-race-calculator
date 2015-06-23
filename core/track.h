#ifndef TRACK_H
#define TRACK_H

#include <memory>
#include <array>
using std::array;

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QVariant>

#include <types/downforce.h>
#include <types/suspension.h>
#include <types/grip.h>
#include <types/overtaking.h>
#include <types/fuelconsumption.h>
#include <types/tyrewear.h>

enum TrackSlots { TRACK_LAPS = 0, TRACK_DISTANCE, TRACK_POWER, TRACK_HANDLING,
                  TRACK_ACCELERATION, TRACK_DOWNFORCE, TRACK_OVERTAKING, TRACK_SUSPENSION,
                  TRACK_FUEL_CONSUMPTION, TRACK_TYRE_WEAR, TRACK_AVG_SPEED, TRACK_LAP_LENGTH,
                  TRACK_CORNERS, TRACK_GRIP, TRACK_PIT_STOP, TRACK_NAME };

class Track
{
private:
    const static array<QString,16> field_names_;

    int laps_;
    QString name_;
    int distance_;
    int power_;
    int handling_;
    int acceleration_;
    Downforce downforce_;
    Overtaking overtaking_;
    Suspension suspension_;
    FuelConsumption fuel_consumption_;
    TyreWear tyre_wear_;
    double avg_speed_;
    double lap_length_;
    int corners_;
    Grip grip_;
    double pit_stop_;

    Track(const Track&);
    Track operator=(const Track&);

public:
    Track();

    // getters
    QString getTrackQString(TrackSlots slot) {
        switch(slot) {
            case TRACK_LAPS: return QString::number(laps_);
            case TRACK_NAME: return QString(name_);
            case TRACK_DISTANCE: return QString::number(distance_);
            case TRACK_POWER: return QString::number(power_);
            case TRACK_HANDLING: return QString::number(handling_);
            case TRACK_ACCELERATION: return QString::number(acceleration_);
            case TRACK_DOWNFORCE: return downforce_.asString();
            case TRACK_OVERTAKING: return overtaking_.asString();
            case TRACK_SUSPENSION: return suspension_.asString();
            case TRACK_FUEL_CONSUMPTION: return fuel_consumption_.asString();
            case TRACK_TYRE_WEAR: return tyre_wear_.asString();
            case TRACK_AVG_SPEED: return QString::number(avg_speed_);
            case TRACK_LAP_LENGTH: return QString::number(lap_length_);
            case TRACK_CORNERS: return QString::number(corners_);
            case TRACK_GRIP: return grip_.asString();
            case TRACK_PIT_STOP: return QString::number(pit_stop_);
        default: break;
        }

        return 0;
    }

    const QString& getName() { return name_; }

    inline static const array<QString,16> getFieldNames() { return field_names_; }

    // setters
    void setValue(TrackSlots slot, const QVariant &value);
};

#endif // TRACK_H
