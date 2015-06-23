#ifndef DATABASESETTINGSDIALOG_H
#define DATABASESETTINGSDIALOG_H

#include <memory>

#include <QDialog>
#include <QString>

#include <databasehandler.h>

namespace Ui {
class DatabaseSettingsDialog;
}

class DatabaseSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseSettingsDialog(std::shared_ptr<DatabaseHandler> dbhandler, QWidget *parent = 0);
    ~DatabaseSettingsDialog();

    void loadSettings(const QString &soft_name, const QString &company_name);
    void saveSettings(const QString &soft_name, const QString &company_name);

private:
    Ui::DatabaseSettingsDialog *ui;

    std::shared_ptr<DatabaseHandler> dbhandler_;
};

#endif // DATABASESETTINGSDIALOG_H
