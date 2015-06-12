#ifndef DRIVERHANDLER_H
#define DRIVERHANDLER_H

#include <memory>
#include <array>
using std::array;

#include <QWidget>
#include <QPlainTextEdit>

#include "driver.h"

class DriverHandler
{
public:
    DriverHandler();

    // field initializations
    void initFields(std::shared_ptr<QWidget> parent);

    // getters
    inline int getValueBySlot(DriverSlots slot) { return driver_->getValue(slot); }

    inline const QPlainTextEdit* getField(DriverSlots slot) { return fields_.at(slot-2); }

    // setters
    inline void setValueBySlot(const int& value, DriverSlots slot) { driver_->setValue(value, slot); }

private:
    // pointer to driver
    std::shared_ptr<Driver> driver_;

    // array of pointers to fields
    array<QPlainTextEdit*,10> fields_;

    // disallowing copying
    DriverHandler(const DriverHandler&);
    DriverHandler operator=(const DriverHandler&);
};

#endif // DRIVERHANDLER_H
