#include "handlers/driverhandler.h"

DriverHandler::DriverHandler() : driver_(new Driver), dc_group_box_(0)
{

}

void DriverHandler::initFields(DCGroupBox *parent) {
    dc_group_box_ = parent;
}

void DriverHandler::setFields(const array<int, 9> &values)
{
    driver_->setStatValue(DRIVER_CONCENTRATION, values.at(0));
    driver_->setStatValue(DRIVER_TALENT, values.at(1));
    driver_->setStatValue(DRIVER_AGGRESSIVENESS, values.at(2));
    driver_->setStatValue(DRIVER_EXPERIENCE, values.at(3));
    driver_->setStatValue(DRIVER_TECHNICAL_INSIGHT, values.at(4));
    driver_->setStatValue(DRIVER_STAMINA, values.at(5));
    driver_->setStatValue(DRIVER_CHARISMA, values.at(6));
    driver_->setStatValue(DRIVER_MOTIVATION, values.at(7));
    driver_->setStatValue(DRIVER_WEIGHT, values.at(8));
}

void DriverHandler::setField(int index, int value)
{
    switch(index) {
        case 0:  driver_->setStatValue(DRIVER_CONCENTRATION, value); break;
        case 1:  driver_->setStatValue(DRIVER_TALENT, value); break;
        case 2:  driver_->setStatValue(DRIVER_AGGRESSIVENESS, value); break;
        case 3:  driver_->setStatValue(DRIVER_EXPERIENCE, value); break;
        case 4:  driver_->setStatValue(DRIVER_TECHNICAL_INSIGHT, value); break;
        case 5:  driver_->setStatValue(DRIVER_STAMINA, value); break;
        case 6:  driver_->setStatValue(DRIVER_CHARISMA, value); break;
        case 7:  driver_->setStatValue(DRIVER_MOTIVATION, value); break;
        case 8:  driver_->setStatValue(DRIVER_WEIGHT, value); break;
    default: break;
    }
}

