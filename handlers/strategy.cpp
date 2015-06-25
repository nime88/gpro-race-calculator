#include "handlers/strategy.h"

#include <QTableWidget>

Strategy::Strategy(TrackGroupBox *parent): track_group_box_(parent)
{
    race_humidities_.fill(0);
    race_temperatures_.fill(0);
}
