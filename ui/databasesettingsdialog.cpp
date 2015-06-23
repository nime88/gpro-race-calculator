#include "databasesettingsdialog.h"
#include "ui_databasesettingsdialog.h"

DatabaseSettingsDialog::DatabaseSettingsDialog(std::shared_ptr<DatabaseHandler> dbhandler, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseSettingsDialog),
    dbhandler_(dbhandler)
{
    ui->setupUi(this);
}

DatabaseSettingsDialog::~DatabaseSettingsDialog()
{
    delete ui;
}
