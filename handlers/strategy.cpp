#include "handlers/strategy.h"

#include <QTableWidget>

Strategy::Strategy(): track_group_box_(0)
{
    race_humidities_.fill(0);
    race_temperatures_.fill(0);
}

void Strategy::initFields(TrackGroupBox* parent)
{
    track_group_box_ = parent;
}
