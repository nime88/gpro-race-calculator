#ifndef TRACKHANDLER_H
#define TRACKHANDLER_H

#include <memory>
#include <array>
using std::array;
#include <algorithm>

#include <QLabel>
#include <QComboBox>

#include <core/track.h>
#include <ui/trackgroupbox.h>
#include <databasehandler.h>
#include <types/tyrewear.h>

class TrackGroupBox;

class TrackHandler
{
private:
    // currently visible track (in ui)
    std::shared_ptr<Track> current_track_;

    // pointer to group box
    TrackGroupBox* track_group_box_;

    // disallowing copying
    TrackHandler (const TrackHandler&) = delete;
    void operator=(const TrackHandler&) = delete;
public:
    TrackHandler(TrackGroupBox *parent);

    void setCurrentTrack(std::shared_ptr<Track> current_track) { current_track_ = current_track; }
    std::shared_ptr<Track> getCurrentTrack() { return current_track_; }

    TyreWear getTrackTyreWear() const {
        TyreWear tw("");
        if (current_track_ == 0) tw = TyreWear("");
        else tw = TyreWear(current_track_->getTrackQString(TRACK_TYRE_WEAR));

        return tw;
    }
    int getPower() const {
        int power;
        if (current_track_ == 0) power = 0;
        else power = current_track_->getTrackQString(TRACK_POWER).toInt();

        return power;
    }
    int getHandling() const {
        int handling;
        if (current_track_ == 0) handling = 0;
        else handling = current_track_->getTrackQString(TRACK_HANDLING).toInt();

        return handling;
    }
    int getAcceleration() const {
        int acceleration;
        if (current_track_ == 0) acceleration = 0;
        else acceleration = current_track_->getTrackQString(TRACK_ACCELERATION).toInt();

        return acceleration;
    }
};

#endif // TRACKHANDLER_H
