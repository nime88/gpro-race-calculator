#ifndef DRIVERHANDLER_H
#define DRIVERHANDLER_H

#include <memory>
#include <array>
using std::array;

#include <QWidget>
#include <QPlainTextEdit>

#include "drivergroupbox.h"
#include "driver.h"

class DriverHandler
{

public:
    DriverHandler();

    // field initializations
    void initFields(DriverGroupBox *parent);

private:
    // pointer to driver
    std::shared_ptr<Driver> driver_;

    // pointer to driver fields container (groupbox)
    DriverGroupBox* driver_group_box_;

    // disallowing copying
    DriverHandler(const DriverHandler&);
    DriverHandler operator=(const DriverHandler&);
};

#endif // DRIVERHANDLER_H
