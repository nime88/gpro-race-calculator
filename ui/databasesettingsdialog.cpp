#include "databasesettingsdialog.h"
#include "ui_databasesettingsdialog.h"

#include <utility/constants.h>

DatabaseSettingsDialog::DatabaseSettingsDialog(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseSettingsDialog),
    parent_(parent)
{
    ui->setupUi(this);
}

DatabaseSettingsDialog::~DatabaseSettingsDialog()
{
    delete ui;
}

void DatabaseSettingsDialog::loadSettings()
{
    QSettings settings(General::ProgramName, General::CompanyName);

    QString type = settings.value(Settings::DatabaseTypeText, QVariant("QPSQL")).toString();
    ui->database_cb->setCurrentText(type);
    QString name = settings.value(Settings::DatabaseNameText, QVariant("")).toString();
    ui->database_name_le->setText(name);
    QString username = settings.value(Settings::DatabaseUserNameText, QVariant("")).toString();
    ui->database_user_name_le->setText(username);
    QString password = settings.value(Settings::DatabasePasswordText, QVariant("")).toString();
    ui->database_password_le->setText(password);
}

void DatabaseSettingsDialog::saveSettings()
{
    QSettings settings(General::ProgramName, General::CompanyName);

    settings.setValue(Settings::DatabaseTypeText, QVariant(ui->database_cb->currentText()));
    settings.setValue(Settings::DatabaseNameText, QVariant(ui->database_name_le->text()));
    settings.setValue(Settings::DatabaseUserNameText, QVariant(ui->database_user_name_le->text()));
    settings.setValue(Settings::DatabasePasswordText, QVariant(ui->database_password_le->text()));
}

void DatabaseSettingsDialog::on_buttonBox_accepted()
{
    saveSettings();
    parent_->fullUpdate();
    this->close();
}
