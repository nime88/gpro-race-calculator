#ifndef CAR_H
#define CAR_H

#include <array>
using std::array;

#include <QString>

enum CarMiscSlots { CAR_TRACK_NAME = 0, CAR_SEASON };
enum CarSlots { CAR_CHASSIS = 0, CAR_ENGINE, CAR_FRONT_WING, CAR_REAR_WING,
                   CAR_UNDERBODY, CAR_SIDEPODS, CAR_COOLING, CAR_GEARBOX,
                   CAR_BRAKES, CAR_SUSPENSION, CAR_ELECTRONICS };
enum CarStatsSlots { CAR_POWER = 0, CAR_HANDLING, CAR_ACCELERATION };

class Car
{
    private:
    // names for database headers (yes the database was created before this program existed)
    const static array<QString, 16> car_lvl_names_;
    const static array<QString,13> car_wear_names_;

    QString track_name_;
    int season_;
    array<int,3> car_stats_;
    array<int,11> part_lvl_;
    array<int,11> part_wear_;

    // lets just make sure we don't accidentially copy car
    Car (const Car&);
    Car& operator=(const Car&);

public:
    Car();

    static const array<QString,16>& getStatNames() { return car_lvl_names_; }
    static const array<QString,13>& getWearNames() { return car_wear_names_; }

    // getters
    QString getLvlQString(CarSlots slot) { return QString::number(part_lvl_.at(slot)); }
    QString getWearQString(CarSlots slot) { return QString::number(part_wear_.at(slot)); }
    int getLvl(CarSlots slot) { return part_lvl_.at(slot); }
    int getWear(CarSlots slot) { return part_lvl_.at(slot); }
    int getStat(CarStatsSlots slot) { return car_stats_.at(slot); }

    // setters
    void setTrack(QString name) { track_name_ = name; }
    void setSeason(int season) { season_ = season; }
    void setLvl(CarSlots slot, int lvl) { part_lvl_.at(slot) = lvl; }
    void setWear(CarSlots slot, int wear) { part_wear_.at(slot) = wear; }
    void setStat(CarStatsSlots slot, int stat) { car_stats_.at(slot) = stat; }
};

#endif // CAR_H
