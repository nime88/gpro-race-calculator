#include "trackhandler.h"

bool trackCompare (std::shared_ptr<Track> track_1, std::shared_ptr<Track> track_2) {
    if (track_1->getTrackQString() < track_2->getTrackQString()) return true;
    return false;
}

TrackHandler::TrackHandler(): track_combobox_(0)
{
    track_fields_.fill(0);
}

void TrackHandler::initFields2CurrentTrack(std::shared_ptr<QWidget> parent, std::shared_ptr<DatabaseHandler> dbhandler)
{
    //initializing combobox if not present
    if (track_combobox_ == 0) {
        track_combobox_ = parent->findChild<QComboBox*>("track_list_combo_box");
        track_combobox_->addItems(dbhandler->getTrackNames());
    }

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

void TrackHandler::setTracks(std::shared_ptr<DatabaseHandler> dbhandler)
{
    tracks_ = dbhandler->getTracks();
    //sorting tracks
    std::sort(tracks_.begin(), tracks_.end(), trackCompare);
}
