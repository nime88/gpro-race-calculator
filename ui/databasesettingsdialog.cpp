#include "databasesettingsdialog.h"
#include "ui_databasesettingsdialog.h"

DatabaseSettingsDialog::DatabaseSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseSettingsDialog)
{
    ui->setupUi(this);
}

DatabaseSettingsDialog::~DatabaseSettingsDialog()
{
    delete ui;
}
