#include "ui/mainwindow.h"
#include "ui_mainwindow.h"
#include "filemenu.h"

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory>

#include "core/track.h"
#include <utility/constants.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
     driverhandler_(new DriverHandler),
     carhandler_(new CarHandler),
     dbhandler_(new DatabaseHandler),
     settingshandler_(new SettingsHandler),
     regressionhandler_(new Regressions),
     strategyhandler_(new Strategy),
     trackhandler_(new TrackHandler)
{
    ui_->setupUi(this);
    fullUpdate();
}

MainWindow::~MainWindow() {}

void MainWindow::updateDBDependentUI()
{
    // initializes driver fields (however at the time of writing should not directly to anything)
    trackhandler_->initFields(ui_->track_group_box, dbhandler_);

    // setting tracks
    trackhandler_->setTracks(dbhandler_);

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

    // initializes driver fields (however at the time of writing should not directly to anything)
    driverhandler_->initFields(ui_->dc_group_box);
    carhandler_->initFields(ui_->dc_group_box);
    trackhandler_->initFields(ui_->track_group_box, dbhandler_);

    // setting tracks
    trackhandler_->setTracks(dbhandler_);

    regressionhandler_->setPracticeData(dbhandler_->getPracticeData());
    regressionhandler_->calculateAllRegressionCofactors();

    //loading settings
    ui_->dc_group_box->loadSettings(General::ProgramName, General::CompanyName);
    ui_->strategy_tab_widget->loadSettings(General::ProgramName, General::CompanyName);
    ui_->track_group_box->loadSettings(General::ProgramName, General::CompanyName);
}

void MainWindow::on_actionQuit_2_triggered()
{
    ui_->dc_group_box->saveSettings(General::ProgramName, General::CompanyName);
    ui_->strategy_tab_widget->saveSettings(General::ProgramName, General::CompanyName);
    ui_->track_group_box->saveSettings(General::ProgramName, General::CompanyName);
    this->close();
}

void MainWindow::on_actionDatabase_triggered()
{
    DatabaseSettingsDialog* dsd = new DatabaseSettingsDialog(this);
    dsd->loadSettings();
    dsd->show();
}
