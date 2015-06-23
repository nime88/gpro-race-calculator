#ifndef DCGROUPBOX_H
#define DCGROUPBOX_H

#include <memory>

#include <QGroupBox>
#include <QTableWidget>
#include <QSignalMapper>
#include <QSettings>

#include "handlers/driverhandler.h"
#include "handlers/carhandler.h"
#include "handlers/trackhandler.h"
#include "handlers/strategy.h"

class DriverHandler;
class CarHandler;
class TrackHandler;
class Strategy;

class DCGroupBox : public QGroupBox
{
    Q_OBJECT

private:
    std::shared_ptr<DriverHandler> driver_handler_;
    std::shared_ptr<CarHandler> car_handler_;
    std::shared_ptr<TrackHandler> track_handler_;
    std::shared_ptr<Strategy> strategy_handler_;

    const array<QString,9> driver_settings_text_{ {"settings/driver/concentration", "settings/driver/talent",
                                                  "settings/driver/aggressiveness", "settings/driver/experience",
                                                  "settings/driver/technical_insight", "settings/driver/stamina",
                                                  "settings/driver/charisma", "settings/driver/motivation",
                                                  "settings/driver/weight"} };

    const array<QString, 11> car_lvl_text_{ {"settings/car/lvl/chassis", "settings/car/lvl/engine", "settings/car/lvl/frontwing",
                                            "settings/car/lvl/rearwing", "settings/car/lvl/underbody", "settings/car/lvl/sidepods",
                                            "settings/car/lvl/cooling", "settings/car/lvl/gearbox", "settings/car/lvl/brakes",
                                            "settings/car/lvl/suspension", "settings/car/lvl/electronics"} };

    const array<QString, 11> car_wear_text_{ {"settings/car/wear/chassis", "settings/car/wear/engine", "settings/car/wear/frontwing",
                                            "settings/car/wear/rearwing", "settings/car/wear/underbody", "settings/car/wear/sidepods",
                                            "settings/car/wear/cooling", "settings/car/wear/gearbox", "settings/car/wear/brakes",
                                            "settings/car/wear/suspension", "settings/car/wear/electronics"} };

    const array<QString, 3> car_stats_text_{ {"settings/car/stats/power", "settings/car/stats/handling", "settings/car/stats/acceleration"} };

    const array<QString, 6> weather_text_{ {"settings/weather/temperature/q1", "settings/weather/temperature/q2", "settings/weather/temperature/race",
                                           "settings/weather/humidity/q1", "settings/weather/humidity/q2", "settings/weather/humidity/race"} };

    array<int, 9> driver_stats;
    array<int,11> car_lvl_;
    array<int,11> car_wear_;
    array<int,3> car_power_;
    array<double,3> race_temperatures_;
    array<double,3> race_humidities_;
    array<bool,3> race_weather_;

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
                     std::shared_ptr<TrackHandler> track_handler,
                     std::shared_ptr<Strategy> strategy_handler) {
        driver_handler_ = driver_handler;
        car_handler_ = car_handler;
        track_handler_ = track_handler;
        strategy_handler_ = strategy_handler;
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
