#include "driver.h"

Driver::Driver(): track_(""), season_(0)
{
    std::fill(stats_, stats_[9],0);
}
