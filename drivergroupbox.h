#ifndef DRIVERGROUPBOX_H
#define DRIVERGROUPBOX_H

#include <memory>

#include <QGroupBox>
#include <QTableWidget>

#include "driver.h"

class DriverGroupBox : QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<Driver> driver_;

public:
    DriverGroupBox(QWidget *parent);

    void setDriver(std::shared_ptr<Driver> driver) {
        driver_ = driver;
    }

public slots:
    void itemChanged(QTableWidgetItem *item);
};

#endif // DRIVERGROUPBOX_H
