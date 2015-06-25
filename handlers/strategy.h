#ifndef STRATEGY_H
#define STRATEGY_H

#include <memory>

#include <QWidget>
#include <QTableWidgetItem>

#include "ui/trackgroupbox.h"

class TrackGroupBox;

class Strategy
{
private:
    array<double,3> race_temperatures_;
    array<double,3> race_humidities_;

    TrackGroupBox* track_group_box_;

    // disabling copying
    Strategy (const Strategy&) = delete;
    void operator=(const Strategy&) = delete;

public:
    Strategy(TrackGroupBox* parent);

    void setTemperatures(const array<double,3>& temperatures) { race_temperatures_ = temperatures; }
    void setHumidities(const array<double,3>& humidities) { race_humidities_ = humidities; }

    double getQ1Temperature() { return race_temperatures_.at(0); }
    double getQ2Temperature() { return race_temperatures_.at(1); }
    double getRaceTemperature() { return race_temperatures_.at(2); }

};

#endif // STRATEGY_H
