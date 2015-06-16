#ifndef DRIVERGROUPBOX_H
#define DRIVERGROUPBOX_H

#include <memory>

#include <QGroupBox>
#include <QTableWidget>

#include "driver.h"

class DriverGroupBox : public QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<Driver> driver_;

public:
    DriverGroupBox(QWidget *parent);

    void setDriver(std::shared_ptr<Driver> driver) {
        driver_ = driver;
    }

    // fixed ui declarations (wtf is this SHIT)
    //void setObjectName(const QString& name) { QGroupBox::setObjectName(name); }
    //void setGeometry(int x, int y, int w, int h) { QWidget::setGeometry(x,y,w,h); }


public slots:
    void itemChanged(QTableWidgetItem *item);
};

#endif // DRIVERGROUPBOX_H
