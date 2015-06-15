#include "driverhandler.h"

void DriverHandler::updateDriver()
{
    driver_->setValue(driver_group_box_->getIntValue(DriverSlots::DRIVER_CONCENTRATION),DriverSlots::DRIVER_CONCENTRATION);
}

DriverHandler::DriverHandler() : driver_(Driver), driver_group_box_(0)
{

}

void DriverHandler::initFields(DriverGroupBox* parent) {
    parent->setDriver(driver_);
}

