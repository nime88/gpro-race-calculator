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
    // currently visible track (in ui)
    std::shared_ptr<Track> current_track_;

    // pointer to group box
    TrackGroupBox* track_group_box_;

    // disallowing copying
    TrackHandler (const TrackHandler&) = delete;
    void operator=(const TrackHandler&) = delete;
public:
    TrackHandler(TrackGroupBox *parent);
};

#endif // TRACKHANDLER_H
