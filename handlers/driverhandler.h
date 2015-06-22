#ifndef DRIVERHANDLER_H
#define DRIVERHANDLER_H

#include <memory>
#include <array>
using std::array;

#include <QWidget>
#include <QPlainTextEdit>

#include "ui/dcgroupbox.h"
#include "core/driver.h"

class DCGroupBox;

class DriverHandler
{

public:
    DriverHandler();

    // field initializations
    void initFields(DCGroupBox *parent);

    // set all the field values to driver
    void setFields(const array<int,9>& values);
    void setField(int index, int value);

private:
    // pointer to driver
    std::shared_ptr<Driver> driver_;

    // pointer to driver fields container (groupbox)
    DCGroupBox* dc_group_box_;

    // disallowing copying
    DriverHandler(const DriverHandler&);
    DriverHandler operator=(const DriverHandler&);
};

#endif // DRIVERHANDLER_H
