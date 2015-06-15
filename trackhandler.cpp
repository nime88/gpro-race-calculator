#include "trackhandler.h"

TrackHandler::TrackHandler(): track_group_box_(0)
{

}

void TrackHandler::initFields(TrackGroupBox *parent, std::shared_ptr<DatabaseHandler> dbhandler)
{
    parent->setTracks(dbhandler->getTrackNames());
    track_group_box_ = parent;
}

void TrackHandler::setTracks(std::shared_ptr<DatabaseHandler> dbhandler)
{
    tracks_ = dbhandler->getTracks();
    track_group_box_->setTracks(getTracks());
}
