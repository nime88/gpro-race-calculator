#include "ui/trackgroupbox.h"

#include <utility/resourcemanager.h>

bool trackCompare (std::shared_ptr<Track> track_1, std::shared_ptr<Track> track_2) {
    if (track_1->getTrackQString(TRACK_NAME) < track_2->getTrackQString(TRACK_NAME)) return true;
    return false;
}

TrackGroupBox::TrackGroupBox(QWidget *parent):
    QGroupBox(parent),
    current_track_(0),
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

void TrackGroupBox::loadSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    QString current_track = settings.value(track_chosen_text, QVariant("")).toString();
    if (current_track.size() > 0) setCurrentTrack(current_track);
}

void TrackGroupBox::saveSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    settings.setValue(track_chosen_text, QVariant(track_combo_box_->currentText()));
}

void TrackGroupBox::updateContent()
{
    // sorting tracks (if it hansn't been done yet
    ResourceManager::getInstance().getTrackQStringList()->sort(Qt::CaseInsensitive);
    track_combo_box_->clear();
    // adding items to combo box
    track_combo_box_->addItems(*ResourceManager::getInstance().getTrackQStringList());

    // if we have nothing to show we just leave
    if(track_combo_box_->count() == 0) return;

    // if we actually have current track we update fields for it
    if (current_track_ != 0) {
        track_combo_box_->setCurrentText(current_track_->getName());
        for (unsigned int i = 0; i < track_fields_.size(); ++i) {
            track_fields_.at(i)->setText(current_track_->getTrackQString(static_cast<TrackSlots>(i)));
        }
    }
}

void TrackGroupBox::setCurrentTrack(const QString &current_track)
{
    track_combo_box_->setCurrentText(current_track);
    trackChanged(current_track);
}

void TrackGroupBox::trackChanged(QString track)
{
    if (ResourceManager::getInstance().getTrack(track) == 0) return;

    current_track_ = ResourceManager::getInstance().getTrack(track);

    // then changing field values
    for (unsigned int i = 0; i < track_fields_.size(); ++i) {
        track_fields_.at(i)->setText(current_track_->getTrackQString(static_cast<TrackSlots>(i)));
    }
}
