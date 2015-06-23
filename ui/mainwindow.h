#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QSettings>
#include <QLineEdit>

#include "handlers/driverhandler.h"
#include "databasehandler.h"
#include "handlers/settingshandler.h"
#include "utility/regressions.h"
#include "handlers/strategy.h"
#include "handlers/carhandler.h"
#include "handlers/trackhandler.h"
#include <ui/databasesettingsdialog.h>

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

    // reloads everything
    void updateDBDependentUI();
    void fullUpdate();

private slots:
    void on_actionQuit_2_triggered();

    void on_actionDatabase_triggered();

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
