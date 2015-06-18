#ifndef DRIVERGROUPBOX_H
#define DRIVERGROUPBOX_H

#include <memory>

#include <QGroupBox>
#include <QTableWidget>
#include <QSignalMapper>

#include "driver.h"

class DriverGroupBox : public QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<Driver> driver_;

    QTableWidget* driver_table_;

    QSignalMapper* signal_map_;

public:
    DriverGroupBox(QWidget *parent);

    void init();

    void setDriver(std::shared_ptr<Driver> driver) {
        driver_ = driver;
    }

public slots:
    void cellChanged(int row);
};

#endif // DRIVERGROUPBOX_H
