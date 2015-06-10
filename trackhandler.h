#ifndef TRACKHANDLER_H
#define TRACKHANDLER_H

#include <memory>

#include <QLabel>

#include "track.h"

class TrackHandler
{
private:
    // array of pointers to ui fields
    QLabel* track_fields_[16];

    // all the possible tracks
    std::vector< std::shared_ptr<Track> > tracks_;

    // currently visible track (in ui)
    std::shared_ptr<Track> current_track_;

    // disallowing copying
    TrackHandler (const TrackHandler&);
    TrackHandler& operator=(const TrackHandler&);
public:
    TrackHandler();

    void initFields2CurrentTrack (std::shared_ptr<QWidget> parent, std::shared_ptr<Track> current_track);

    inline QLabel* getField(TrackSlots slot) { return track_fields_[slot]; }

    inline void setField(TrackSlots slot, QLabel* field) { track_fields_[slot] = field; }
};

#endif // TRACKHANDLER_H
