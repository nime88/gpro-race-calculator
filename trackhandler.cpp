#include "trackhandler.h"

TrackHandler::TrackHandler()
{
}

void TrackHandler::initFields2CurrentTrack(std::shared_ptr<QWidget> parent, std::shared_ptr<Track> current_track)
{
    current_track_ = current_track;

    // initializing fields if they're not been done so
    setField(TRACK_LAPS, parent->findChild<QLabel*>("laps_value"));
    setField(TRACK_DISTANCE, parent->findChild<QLabel*>("distance_value"));
    setField(TRACK_POWER, parent->findChild<QLabel*>("power_value"));
    setField(TRACK_HANDLING, parent->findChild<QLabel*>("handling_value"));
    setField(TRACK_ACCELERATION, parent->findChild<QLabel*>("acceleration_value"));
    setField(TRACK_DOWNFORCE, parent->findChild<QLabel*>("downforce_value"));
    setField(TRACK_OVERTAKING, parent->findChild<QLabel*>("overtaking_value"));
    setField(TRACK_SUSPENSION, parent->findChild<QLabel*>("suspension_value"));
    setField(TRACK_FUEL_CONSUMPTION, parent->findChild<QLabel*>("fuel_consumption_value"));
    setField(TRACK_TYRE_WEAR, parent->findChild<QLabel*>("tyre_wear_value"));
    setField(TRACK_AVG_SPEED, parent->findChild<QLabel*>("avg_speed_value"));
    setField(TRACK_LAP_LENGTH, parent->findChild<QLabel*>("lap_length_value"));
    setField(TRACK_CORNERS, parent->findChild<QLabel*>("corners_value"));
    setField(TRACK_GRIP, parent->findChild<QLabel*>("grip_value"));
    setField(TRACK_PIT_STOP, parent->findChild<QLabel*>("pit_stop_value"));

    // updating info to fields
    for(TrackSlots i = TRACK_LAPS; i < TRACK_LAPS + 15; ++i) {
        getField(i)->setText(getTrackQString(i));
    }
}
