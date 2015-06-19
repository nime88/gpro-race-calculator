#ifndef DCGROUPBOX_H
#define DCGROUPBOX_H

#include <memory>

#include <QGroupBox>
#include <QTableWidget>
#include <QSignalMapper>
#include <QSettings>

#include "driverhandler.h"
#include "carhandler.h"
#include "trackhandler.h"

class DriverHandler;
class CarHandler;
class TrackHandler;

class DCGroupBox : public QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<DriverHandler> driver_handler_;
    std::shared_ptr<CarHandler> car_handler_;
    std::shared_ptr<TrackHandler> track_handler_;

    array<int, 9> driver_stats;
    array<int,11> car_lvl_;
    array<int,11> car_wear_;
    array<int,3> car_power_;
    array<double,3> race_temperatures_;
    array<double,3> race_humidities_;

    QTableWidget* driver_table_;
    QTableWidget* car_lvl_table_;
    QTableWidget* car_stats_table_;
    QTableWidget* weather_table_;

    QSignalMapper* driver_signal_map_;
    QSignalMapper* car_lvl_signal_map_;
    QSignalMapper* car_stats_signal_map_;
    QSignalMapper* weather_signal_map_;

public:
    DCGroupBox(QWidget *parent);

    void init();

    void setHandlers(std::shared_ptr<DriverHandler> driver_handler,
                     std::shared_ptr<CarHandler> car_handler,
                     std::shared_ptr<TrackHandler> track_handler) {
        driver_handler_ = driver_handler;
        car_handler_ = car_handler;
        track_handler_ = track_handler;
    }

    // FULLY updates the handlers to be up to date
    void updateHandlers();

    void loadSettings(const QString& soft_name, const QString& company_name);
    void saveSettings(const QString& soft_name, const QString& company_name);

public slots:
    void driverCellChanged(int row);
    void carCellChanged(int index);
    void carStatsCellChanged(int row);
    void weatherCellChanged(int index);
};

#endif // DCGROUPBOX_H
