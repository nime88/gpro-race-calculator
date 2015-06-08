#ifndef TRACK_H
#define TRACK_H

#include <memory>

#include <QWidget>
#include <QString>
#include <QLabel>

enum TrackSlots { TRACK_LAPS = 0, TRACK_DISTANCE, TRACK_POWER, TRACK_HANDLING,
                  TRACK_ACCELERATION, TRACK_DOWNFORCE, TRACK_OVERTAKING, TRACK_SUSPENSION,
                  TRACK_FUEL_CONSUMPTION, TRACK_TYRE_WEAR, TRACK_AVG_SPEED, TRACK_LAP_LENGTH,
                  TRACK_CORNERS, TRACK_GRIP, TRACK_PIT_STOP, TRACK_NAME };

class Track
{
private:
    const static char field_names_[] = {"\"Track\".Laps", "\"Track\".Distance", "\"Track\".Power", "\"Track\".Handling",
                                        "\"Track\".Acceleration", "\"Track\".Downforce", "\"Track\".OverTaking",
                                        "\"Track\".Suspension", "\"Track\".FuelConsumption", "\"Track\".TyreWear",
                                        "\"Track\".AvgSpeed", "\"Track\".LapLength", "\"Track\".Corners",
                                        "\"Track\".Grip", "\"Track\".PitStop", "\"Track\".Name", };
    static QLabel* track_fields_[16];
    static bool initialized_;

    int laps_;
    QString name_;
    int distance_;
    int power_;
    int handling_;
    int acceleration_;
    QString downforce_;
    QString overtaking_;
    QString suspension_;
    QString fuel_consumption_;
    QString tyre_wear_;
    double avg_speed_;
    double lap_length_;
    int corners_;
    QString grip_;
    double pit_stop_;

    Track(const Track&);
    Track operator=(const Track&);

public:
    Track();

    static void initFields2CurrentTrack (std::shared_ptr<QWidget> parent, std::shared_ptr<Track> current_track);

    // getters
    const QString& getTrackQString(TrackSlots slot) {
        switch(slot) {
            case TRACK_LAPS: return QString::number(laps_);
            case TRACK_NAME: return QString(name_);
            case TRACK_DISTANCE: return QString::number(distance_);
            case TRACK_POWER: return QString::number(power_);
            case TRACK_HANDLING: return QString::number(handling_);
            case TRACK_ACCELERATION: return QString::number(acceleration_);
            case TRACK_DOWNFORCE: return QString(downforce_);
            case TRACK_OVERTAKING: return QString(overtaking_);
            case TRACK_SUSPENSION: return QString(suspension_);
            case TRACK_FUEL_CONSUMPTION: return QString(fuel_consumption_);
            case TRACK_TYRE_WEAR: return QString(tyre_wear_);
            case TRACK_AVG_SPEED: return QString::number(avg_speed_);
            case TRACK_LAP_LENGTH: return QString::number(lap_length_);
            case TRACK_CORNERS: return QString::number(corners_);
            case TRACK_GRIP: return QString(grip_);
            case TRACK_PIT_STOP: return QString::number(pit_stop_);
        default: break;
        }

        return 0;
    }

    inline static const char* const getFieldNames() { return field_names_; }
    /*inline int getLaps() const { return laps_; }
    inline const QString& getName() const { return name_; }
    inline int getDistance() const { return distance_; }
    inline int getPower() const { return power_; }
    inline int getHandling() const { return handling_; }
    inline int getAcceleration() const { return acceleration_; }
    inline const QString& getDownforce() const { return downforce_; }
    inline const QString& getOvertaking() const { return overtaking_; }
    inline const QString& getSuspension() const { return suspension_; }
    inline const QString& getFuelConsumption() const { return fuel_consumption_; }
    inline const QString& getTyreWear() const { return tyre_wear_; }
    inline double getAvgSpeed() const { return avg_speed_; }
    inline double getLapLength() const { return lap_length_; }
    inline int getCorners() const { return corners_; }
    inline const QString& getGrip() const { return grip_; }
    inline double getPitStop() const { return pit_stop_; }*/

    inline static QLabel* getField(TrackSlots slot) { return track_fields_[slot]; }

    inline static bool isInitialized() { return initialized_; }
    inline static void setInitialized() { initialized_ = true; }


    // setters
    inline void setLaps(int laps) { laps_ = laps; }
    inline void setName(const QString& name) { name_ = name; }
    inline void setDistance(int distance) { distance_ = distance; }
    inline void setPower(int power) { power_ = power; }
    inline void setHandling(int handling) { handling_ = handling; }
    inline void setAcceleration(int acceleration) { acceleration_ = acceleration; }
    inline void setDownforce(const QString& downforce) { downforce_ = downforce; }
    inline void setOvertaking(const QString& overtaking) { overtaking_ = overtaking; }
    inline void setSuspension(const QString& suspension) { suspension_ = suspension; }
    inline void setFuelconsumption(const QString& fuel_consumption) { fuel_consumption_ = fuel_consumption; }
    inline void setTyreWear(const QString& tyre_wear) { tyre_wear_ = tyre_wear; }
    inline void setAvgSpeed(double avg_speed) { avg_speed_ = avg_speed; }
    inline void setLapLength(double lap_length) { lap_length_ = lap_length; }
    inline void setCorners(int corners) { corners_ = corners; }
    inline void setGrip(const QString& grip) { grip_ = grip; }
    inline void setPitStop(double pit_stop) { pit_stop_ = pit_stop; }

    inline static void setField(TrackSlots slot, QLabel* field) { track_fields_[slot] = field; }
};

#endif // TRACK_H
