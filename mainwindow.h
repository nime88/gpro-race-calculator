#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QSettings>
#include <QLineEdit>

#include "driverhandler.h"
#include "databasehandler.h"
#include "settingshandler.h"
#include "regressions.h"
#include "strategy.h"
#include "carhandler.h"
#include "trackhandler.h"

class Strategy;
class TrackHandler;
class DriverHandler;
class CarHandler;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_actionQuit_2_triggered();

private:
    // pointer to ui
    Ui::MainWindow* ui_;
    // pointer to driver
    std::shared_ptr<DriverHandler> driverhandler_;
    // pointer to car
    std::shared_ptr<CarHandler> carhandler_;
    // pointer to db handler
    std::shared_ptr<DatabaseHandler> dbhandler_;
    // pointer to car settings handler
    std::shared_ptr<SettingsHandler> settingshandler_;
    // pointer to regressions calculations
    std::shared_ptr<Regressions> regressionhandler_;
    // pointer to strategy calculaton handler
    std::shared_ptr<Strategy> strategyhandler_;
    // pointer to tracks handler
    std::shared_ptr<TrackHandler> trackhandler_;

    // disallowing copies
    MainWindow(const MainWindow&);
    MainWindow operator=(const MainWindow&);

};

#endif // MAINWINDOW_H
