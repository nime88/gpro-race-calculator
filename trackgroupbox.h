#ifndef TRACKGROUPBOX_H
#define TRACKGROUPBOX_H

#include <memory>
#include <array>
using std::array;

#include <QGroupBox>
#include <QComboBox>
#include <QLabel>

#include "track.h"

class TrackGroupBox : QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<Track> current_track_;
    std::vector< std::shared_ptr<Track> > tracks_;

    // array of pointers to ui fields
    array<QLabel*,15> track_fields_;

    QComboBox* track_combo_box_;

    QStringList track_names_;

    void setTrackNames(const std::vector< std::shared_ptr<Track> >& tracks);
    const QStringList& getTrackNames() { return track_names_; }

public:
    TrackGroupBox(QWidget *parent);

    void setTracks(const std::vector< std::shared_ptr<Track> >& tracks);

public slots:
    void trackChanged(QString track);
};

#endif // TRACKGROUPBOX_H
