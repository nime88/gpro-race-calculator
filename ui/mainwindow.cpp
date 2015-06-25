#include "ui/mainwindow.h"
#include "ui_mainwindow.h"
#include "filemenu.h"

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory>

#include "core/track.h"
#include <utility/constants.h>
#include <utility/resourcemanager.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
     driverhandler_(new DriverHandler(ui_->dc_group_box)),
     carhandler_(new CarHandler(ui_->dc_group_box)),
     dbhandler_(new DatabaseHandler),
     settingshandler_(new SettingsHandler),
     regressionhandler_(new Regressions),
     strategyhandler_(new Strategy(ui_->track_group_box)),
     trackhandler_(new TrackHandler(ui_->track_group_box))
{
    ui_->setupUi(this);
    fullUpdate();
}

MainWindow::~MainWindow() {}

void MainWindow::updateDBDependentUI()
{
    regressionhandler_->setPracticeData(dbhandler_->getPracticeData());
    regressionhandler_->calculateAllRegressionCofactors();
}

void MainWindow::fullUpdate()
{
    ui_->dc_group_box->init();
    ui_->dc_group_box->setHandlers(driverhandler_, carhandler_, trackhandler_, strategyhandler_);
    ui_->dc_group_box->updateHandlers();
    ui_->track_group_box->init();
    ui_->track_group_box->setHandlers(strategyhandler_);
    ui_->strategy_tab_widget->init();
    ui_->strategy_tab_widget->setHandlers(regressionhandler_, settingshandler_, strategyhandler_);

    regressionhandler_->setPracticeData(dbhandler_->getPracticeData());
    regressionhandler_->calculateAllRegressionCofactors();

    //loading settings
    ui_->dc_group_box->loadSettings(General::ProgramName, General::CompanyName);
    ui_->strategy_tab_widget->loadSettings(General::ProgramName, General::CompanyName);
    ui_->track_group_box->loadSettings(General::ProgramName, General::CompanyName);

    // updating contents
    ui_->strategy_tab_widget->updateContents();
    ui_->track_group_box->updateContents();
}

void MainWindow::on_actionQuit_2_triggered()
{
    ui_->dc_group_box->saveSettings(General::ProgramName, General::CompanyName);
    ui_->strategy_tab_widget->saveSettings(General::ProgramName, General::CompanyName);
    ui_->track_group_box->saveSettings(General::ProgramName, General::CompanyName);
    ResourceManager::getInstance().clear();
    this->close();
}

void MainWindow::on_actionDatabase_triggered()
{
    DatabaseSettingsDialog* dsd = new DatabaseSettingsDialog(this);
    dsd->loadSettings();
    dsd->show();
}
