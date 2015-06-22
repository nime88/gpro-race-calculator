#include "ui/trackgroupbox.h"

bool trackCompare (std::shared_ptr<Track> track_1, std::shared_ptr<Track> track_2) {
    if (track_1->getTrackQString(TRACK_NAME) < track_2->getTrackQString(TRACK_NAME)) return true;
    return false;
}

void TrackGroupBox::setTrackNames(const std::vector<std::shared_ptr<Track> > &tracks)
{
    QStringList temp_list;
    for (unsigned int i = 0; i < tracks.size(); ++i) {
        temp_list.append(tracks.at(i)->getName());
    }

    track_names_ = temp_list;
}

TrackGroupBox::TrackGroupBox(QWidget *parent):
    QGroupBox(parent),
    track_combo_box_(0),
    strategy_handler_(0)
{    

}

void TrackGroupBox::init()
{
    // after we've made sure we have something filled
    track_fields_.fill(0);
    //we try to assign fields
    track_fields_.at(0) = this->findChild<QLabel*>("laps_value");
    track_fields_.at(1) = this->findChild<QLabel*>("distance_value");
    track_fields_.at(2) = this->findChild<QLabel*>("power_value");
    track_fields_.at(3) = this->findChild<QLabel*>("handling_value");
    track_fields_.at(4) = this->findChild<QLabel*>("acceleration_value");
    track_fields_.at(5) = this->findChild<QLabel*>("downforce_value");
    track_fields_.at(6) = this->findChild<QLabel*>("overtaking_value");
    track_fields_.at(7) = this->findChild<QLabel*>("suspension_value");
    track_fields_.at(8) = this->findChild<QLabel*>("fuel_consumption_value");
    track_fields_.at(9) = this->findChild<QLabel*>("tyre_wear_value");
    track_fields_.at(10) = this->findChild<QLabel*>("avg_speed_value");
    track_fields_.at(11) = this->findChild<QLabel*>("lap_length_value");
    track_fields_.at(12) = this->findChild<QLabel*>("corners_value");
    track_fields_.at(13) = this->findChild<QLabel*>("grip_value");
    track_fields_.at(14) = this->findChild<QLabel*>("pit_stop_value");

    //setting combobox
    track_combo_box_ = this->findChild<QComboBox*>("track_list_combo_box");
}

void TrackGroupBox::setTracks(const std::vector<std::shared_ptr<Track> > &tracks)
{
    tracks_ = tracks;

    if (tracks_.size() > 0) {
        std::sort(tracks_.begin(), tracks_.end(), trackCompare);
        setTrackNames(tracks_);
        track_combo_box_->addItems(getTrackNames());
        trackChanged(getTrackNames().at(0));
    }
}


void TrackGroupBox::trackChanged(QString track)
{
    for (unsigned int i = 0; i < tracks_.size(); ++i) {
        if (track == tracks_.at(i)->getName()) {
            current_track_ = tracks_.at(i);
            break;
        }
    }

    // then changing field values
    track_fields_.at(0)->setText(current_track_->getTrackQString(TRACK_LAPS));
    track_fields_.at(1)->setText(current_track_->getTrackQString(TRACK_DISTANCE));
    track_fields_.at(2)->setText(current_track_->getTrackQString(TRACK_POWER));
    track_fields_.at(3)->setText(current_track_->getTrackQString(TRACK_HANDLING));
    track_fields_.at(4)->setText(current_track_->getTrackQString(TRACK_ACCELERATION));
    track_fields_.at(5)->setText(current_track_->getTrackQString(TRACK_DOWNFORCE));
    track_fields_.at(6)->setText(current_track_->getTrackQString(TRACK_OVERTAKING));
    track_fields_.at(7)->setText(current_track_->getTrackQString(TRACK_SUSPENSION));
    track_fields_.at(8)->setText(current_track_->getTrackQString(TRACK_FUEL_CONSUMPTION));
    track_fields_.at(9)->setText(current_track_->getTrackQString(TRACK_TYRE_WEAR));
    track_fields_.at(10)->setText(current_track_->getTrackQString(TRACK_AVG_SPEED));
    track_fields_.at(11)->setText(current_track_->getTrackQString(TRACK_LAP_LENGTH));
    track_fields_.at(12)->setText(current_track_->getTrackQString(TRACK_CORNERS));
    track_fields_.at(13)->setText(current_track_->getTrackQString(TRACK_GRIP));
    track_fields_.at(14)->setText(current_track_->getTrackQString(TRACK_PIT_STOP));
}
