#ifndef DRIVER_H
#define DRIVER_H

#include <array>
using std::array;

#include <QVariant>
#include <QString>

enum DriverMiscSlots { DRIVER_TRACK_NAME = 0, DRIVER_SEASON };
enum DriverStatSlots { DRIVER_OVERALL = 0, DRIVER_CONCENTRATION,
                 DRIVER_TALENT, DRIVER_AGGRESSIVENESS, DRIVER_EXPERIENCE, DRIVER_TECHNICAL_INSIGHT,
                 DRIVER_STAMINA, DRIVER_CHARISMA, DRIVER_MOTIVATION, DRIVER_WEIGHT};

class Driver
{
private:
    const static array<QString,12> driver_field_names_;

    //identity values
    QString track_;
    int season_;

    array<int,10> stats_;

    // we don't want bad copies floating around
    Driver (const Driver&);
    Driver& operator=(const Driver&);
public:
    Driver();

    // getters
    inline int getValue(DriverStatSlots slot) { return stats_.at(slot); }
    inline const QString& getTrack() { return track_; }
    inline int getSeason() { return season_; }

    inline static const array<QString,12>& getNames() { return driver_field_names_; }

    // setters
    void setMiscValue(DriverMiscSlots slot, const QVariant &value);
    void setStatValue(DriverStatSlots slot, const QVariant &value);

};

#endif // DRIVER_H
