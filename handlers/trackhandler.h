#ifndef TRACKHANDLER_H
#define TRACKHANDLER_H

#include <memory>
#include <array>
using std::array;
#include <algorithm>

#include <QLabel>
#include <QComboBox>

#include "core/track.h"
#include "ui/trackgroupbox.h"
#include "databasehandler.h"

class TrackGroupBox;

class TrackHandler
{
private:
    // all the possible tracks
    std::vector< std::shared_ptr<Track> > tracks_;

    // currently visible track (in ui)
    std::shared_ptr<Track> current_track_;

    // pointer to group box
    TrackGroupBox* track_group_box_;

    // disallowing copying
    TrackHandler (const TrackHandler&);
    TrackHandler& operator=(const TrackHandler&);
public:
    TrackHandler();

    void initFields(TrackGroupBox* parent, std::shared_ptr<DatabaseHandler> dbhandler);

    std::vector< std::shared_ptr<Track> >  getTracks() { return tracks_; }

    void setTracks (std::shared_ptr<DatabaseHandler> dbhandler);
};

#endif // TRACKHANDLER_H
