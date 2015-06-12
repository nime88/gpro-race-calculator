#ifndef TRACKHANDLER_H
#define TRACKHANDLER_H

#include <memory>
#include <array>
using std::array;
#include <algorithm>

#include <QLabel>
#include <QComboBox>

#include "track.h"
#include "databasehandler.h"

class TrackHandler
{
private:
    // array of pointers to ui fields
    array<QLabel*,16> track_fields_;

    // all the possible tracks
    std::vector< std::shared_ptr<Track> > tracks_;

    // currently visible track (in ui)
    std::shared_ptr<Track> current_track_;

    QComboBox* track_combobox_;

    // disallowing copying
    TrackHandler (const TrackHandler&);
    TrackHandler& operator=(const TrackHandler&);
public:
    TrackHandler();

    void initFields2CurrentTrack (std::shared_ptr<QWidget> parent, std::shared_ptr<DatabaseHandler> dbhandler);

    inline QLabel* getField(TrackSlots slot) { return track_fields_.at(slot); }

    void setTracks (std::shared_ptr<DatabaseHandler> dbhandler);
    inline void setField(TrackSlots slot, QLabel* field) { track_fields_.at(slot) = field; }

    void updateCurrentTrack (const QString &name) {
        // if user has selected something we just find it from the list
        for (unsigned int i = 0; i < tracks_.size(); ++i) {
            if (name == tracks_.at(i)->getTrackQString(TrackSlots::TRACK_NAME) ) {
                current_track_ = tracks_.at(i);
                break;
            }
        }
    }
};

#endif // TRACKHANDLER_H
