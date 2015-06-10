#ifndef DRIVER_H
#define DRIVER_H

#include <QString>

enum DriverSlots {DRIVER_TRACK_NAME = 0, DRIVER_SEASON, DRIVER_OVERALL, DRIVER_CONCENTRATION,
                 DRIVER_TALENT, DRIVER_AGGRESSIVENESS, DRIVER_EXPERIENCE, DRIVER_TECHNICAL_INSIGHT,
                 DRIVER_STAMINA, DRIVER_CHARISMA, DRIVER_MOTIVATION, DRIVER_WEIGHT};

class Driver
{
private:
    static const char driver_field_names_ = {
        "Driver.\"Name (Track)\"", "Driver.Season", "Driver.Overall", "Driver.Concentration",
        "Driver.Talent", "Driver.Aggresiveness", "Driver.Experience", "Driver.\"Tech. Insight\"",
        "Driver.Stamina", "Driver.Charisma", "Driver.Motivation", "Driver.Weight" };

    //identity values
    QString track_;
    int season_;

    int stats_[10];

    // we don't want bad copies floating around
    Driver (const Driver&);
    Driver& operator=(const Driver&);
public:
    Driver();

    // getters
    inline int getValue(DriverSlots slot) { return stats_[slot - 2]; }
    inline const QString& getTrack() { return track_; }
    inline int getSeason() { return season_; }

    // setters
    template <typename T>
    inline void setValue(const T& value, DriverSlots slot) { stats_[slot] = value; }
};

#endif // DRIVER_H
