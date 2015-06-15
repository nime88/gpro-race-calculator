#include "driverhandler.h"

DriverHandler::DriverHandler() : driver_(Driver), driver_group_box_(0)
{

}

void DriverHandler::initFields(DriverGroupBox* parent) {
    parent->setDriver(driver_);
    driver_group_box_ = parent;
}

