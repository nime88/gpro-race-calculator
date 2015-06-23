#ifndef DATABASESETTINGSDIALOG_H
#define DATABASESETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class DatabaseSettingsDialog;
}

class DatabaseSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseSettingsDialog(QWidget *parent = 0);
    ~DatabaseSettingsDialog();

private:
    Ui::DatabaseSettingsDialog *ui;
};

#endif // DATABASESETTINGSDIALOG_H
