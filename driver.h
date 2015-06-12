#ifndef DRIVER_H
#define DRIVER_H

#include <array>
using std::array;
#include <string>
using std::string;

#include <QString>

enum DriverSlots {DRIVER_TRACK_NAME = 0, DRIVER_SEASON, DRIVER_OVERALL, DRIVER_CONCENTRATION,
                 DRIVER_TALENT, DRIVER_AGGRESSIVENESS, DRIVER_EXPERIENCE, DRIVER_TECHNICAL_INSIGHT,
                 DRIVER_STAMINA, DRIVER_CHARISMA, DRIVER_MOTIVATION, DRIVER_WEIGHT};

class Driver
{
private:
    const static array<string,12> driver_field_names_;

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
    inline int getValue(DriverSlots slot) { return stats_.at(slot - 2); }
    inline const QString& getTrack() { return track_; }
    inline int getSeason() { return season_; }

    // setters
    inline void setTrackName(const QString& name) { track_ = name; }
    inline void setSeason(const int season) { season_ = season; }
    inline void setValue(const int& value, DriverSlots slot) { stats_.at(slot - 2) = value; }

};

#endif // DRIVER_H
