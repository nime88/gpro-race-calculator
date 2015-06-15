#ifndef STRATEGY_H
#define STRATEGY_H

#include <memory>

#include <QWidget>
#include <QTableWidgetItem>

#include "trackgroupbox.h"

class Strategy
{
private:
    array<double,3> race_temperatures_;
    array<double,3> race_humidities_;

    TrackGroupBox* track_group_box_;

public:
    Strategy();

    void setTemperatures(const array<double,3>& temperatures) { race_temperatures_ = temperatures; }
    void setHumidities(const array<double,3>& humidities) { race_humidities_ = humidities; }

    // field initializations
    void initFields(TrackGroupBox* parent);

};

#endif // STRATEGY_H
