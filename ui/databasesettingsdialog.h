#ifndef DATABASESETTINGSDIALOG_H
#define DATABASESETTINGSDIALOG_H

#include <memory>

#include <QDialog>
#include <QString>

#include <ui/mainwindow.h>
#include <databasehandler.h>

class MainWindow;

namespace Ui {
class DatabaseSettingsDialog;
}

class DatabaseSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseSettingsDialog(MainWindow *parent = 0);
    ~DatabaseSettingsDialog();

    void loadSettings();
    void saveSettings();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DatabaseSettingsDialog *ui;
    MainWindow* parent_;
};

#endif // DATABASESETTINGSDIALOG_H
