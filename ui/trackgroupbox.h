#ifndef TRACKGROUPBOX_H
#define TRACKGROUPBOX_H

#include <memory>
#include <array>
using std::array;

#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QTableWidgetItem>
#include "mainwindow.h"

#include <core/track.h>
#include <handlers/trackhandler.h>

class TrackHandler;

class TrackGroupBox : public QGroupBox
{
    Q_OBJECT

private:
    const QString track_chosen_text = "track/currenttrack";

    // array of pointers to ui fields
    array<QLabel*,15> track_fields_;

    QComboBox* track_combo_box_;

    std::shared_ptr<TrackHandler> track_handler_;

public:
    TrackGroupBox(QWidget *parent = 0);

    void init();

    void loadSettings(const QString& soft_name, const QString& company_name);
    void saveSettings(const QString& soft_name, const QString& company_name);

    void updateContents();

    void setHandlers(std::shared_ptr<TrackHandler> track_handler) { track_handler_ = track_handler; }

public slots:
    void trackChanged(QString track);
};

#endif // TRACKGROUPBOX_H
