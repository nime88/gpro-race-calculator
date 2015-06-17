#ifndef TRACKGROUPBOX_H
#define TRACKGROUPBOX_H

#include <memory>
#include <array>
using std::array;

#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QTableWidgetItem>
#include "mainwindow.h"

#include "track.h"
#include "strategy.h"

class Strategy;

class TrackGroupBox : public QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<Track> current_track_;
    std::vector< std::shared_ptr<Track> > tracks_;

    array<double,3> race_temperatures_;
    array<double,3> race_humidities_;

    // array of pointers to ui fields
    array<QLabel*,15> track_fields_;

    QComboBox* track_combo_box_;
    QTableWidget* weather_table_;

    QStringList track_names_;

    std::shared_ptr<Strategy> strategy_handler_;

    void setTrackNames(const std::vector< std::shared_ptr<Track> >& tracks);
    const QStringList& getTrackNames() { return track_names_; }

public:
    TrackGroupBox(QWidget *parent = 0);

    void init();

    const array<double,3>& getTemperatures() { return race_temperatures_; }
    const array<double,3>& getHumidities() { return race_humidities_; }

    void setTracks(const std::vector< std::shared_ptr<Track> >& tracks);
    void setHandlers(std::shared_ptr<Strategy> strategy_handler) { strategy_handler_ = strategy_handler; }

public slots:
    void trackChanged(QString track);
    void weatherChanged(QTableWidgetItem* item);
};

#endif // TRACKGROUPBOX_H
