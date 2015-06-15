#include "trackgroupbox.h"

bool trackCompare (std::shared_ptr<Track> track_1, std::shared_ptr<Track> track_2) {
    if (track_1->getTrackQString() < track_2->getTrackQString()) return true;
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

TrackGroupBox::TrackGroupBox(QWidget *parent): track_combo_box_(0), weather_table_(0),
    strategy_handler_(0)
{    
    // after we've made sure we have something filled
    track_fields_.fill(0);
    //we try to assign fields
    track_fields_.at(0) = parent->findChild<QLabel*>("laps_value");
    track_fields_.at(1) = parent->findChild<QLabel*>("distance_value");
    track_fields_.at(2) = parent->findChild<QLabel*>("power_value");
    track_fields_.at(3) = parent->findChild<QLabel*>("handling_value");
    track_fields_.at(4) = parent->findChild<QLabel*>("acceleration_value");
    track_fields_.at(5) = parent->findChild<QLabel*>("downforce_value");
    track_fields_.at(6) = parent->findChild<QLabel*>("overtaking_value");
    track_fields_.at(7) = parent->findChild<QLabel*>("suspension_value");
    track_fields_.at(8) = parent->findChild<QLabel*>("fuel_consumption_value");
    track_fields_.at(9) = parent->findChild<QLabel*>("tyre_wear_value");
    track_fields_.at(10) = parent->findChild<QLabel*>("avg_speed_value");
    track_fields_.at(11) = parent->findChild<QLabel*>("lap_length_value");
    track_fields_.at(12) = parent->findChild<QLabel*>("corners_value");
    track_fields_.at(13) = parent->findChild<QLabel*>("grip_value");
    track_fields_.at(14) = parent->findChild<QLabel*>("pit_stop_value");

    //setting combobox
    track_combo_box_ = parent->findChild<QComboBox*>("track_list_combo_box");

    //setting weather table
    weather_table_ = parent->findChild<QComboBox*>("weather_table");
    weather_table_->setItem(0,0, new QTableWidgetItem());
    weather_table_->item(0,0)->setText("0");
    weather_table_->setItem(1,0, new QTableWidgetItem());
    weather_table_->item(1,0)->setText("0");
    weather_table_->setItem(2,0, new QTableWidgetItem());
    weather_table_->item(2,0)->setText("0");
    weather_table_->setItem(0,1, new QTableWidgetItem());
    weather_table_->item(0,1)->setText("0");
    weather_table_->setItem(1,1, new QTableWidgetItem());
    weather_table_->item(1,1)->setText("0");
    weather_table_->setItem(2,1, new QTableWidgetItem());
    weather_table_->item(2,1)->setText("0");
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

void TrackGroupBox::weatherChanged(QTableWidgetItem *item)
{
    // using c style initialization bacause item can be double or int
    // depending on the row
    bool is_temperature = item->column() == 1 ? false : true;
    bool is_valid_number = false;
    double value = item->text().toDouble(is_valid_number);

    // checking valid ranes and do actin...
    if (!is_valid_number) value = 0;
    else {
        if (is_temperature) {
            if (value < 0) value = 0;
            else if (value > 50) value = 50;
        } else {
            if (value < 0) value = 0;
            else if (value > 100) value = 50;
        }
    }

    if (is_temperature) race_temperatures_.at(item->row()) = value;
    else race_humidities_.at(item->row()) = value;

    item->setText(QString::number(value));

    // updating strategy handler
    if (strategy_handler_.get() != 0) {
        strategy_handler_->setTemperatures(race_temperatures_);
        strategy_handler_->setHumidities(race_humidities_);
    }
}
