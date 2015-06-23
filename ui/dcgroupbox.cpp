#include "ui/dcgroupbox.h"

#include <QLineEdit>
#include <QCheckBox>
#include <QDebug>

DCGroupBox::DCGroupBox(QWidget *parent):
    QGroupBox(parent),
    driver_handler_(0),
    car_handler_(0),
    track_handler_(0),
    strategy_handler_(0),
    driver_table_(0),
    car_lvl_table_(0),
    car_stats_table_(0)
{
    driver_signal_map_ = new QSignalMapper(this);
    car_lvl_signal_map_ = new QSignalMapper(this);
    car_stats_signal_map_ = new QSignalMapper(this);
    weather_signal_map_ = new QSignalMapper(this);
}

void DCGroupBox::init()
{
    driver_table_ = findChild<QTableWidget*>("driver_table");
    car_lvl_table_ = findChild<QTableWidget*>("car_lvl_table");
    car_stats_table_ = findChild<QTableWidget*>("car_power_table");
    weather_table_ = findChild<QTableWidget*>("weather_table");

    // connecting driver table items
    for(int i = 0; i < driver_table_->rowCount(); ++i) {
        QLineEdit* temp_line_edit = new QLineEdit;
        connect(temp_line_edit, SIGNAL(textChanged(const QString&)), driver_signal_map_, SLOT(map()));

        driver_signal_map_->setMapping(temp_line_edit, i);
        driver_table_->setCellWidget(i,0, temp_line_edit);
    }

    connect(driver_signal_map_, SIGNAL(mapped(int)), this, SLOT(driverCellChanged(int)));

    // connecting car lvl items
    for (int i = 0; i < car_lvl_table_->rowCount(); ++i) {
        QLineEdit* temp_line_edit = new QLineEdit;
        QLineEdit* temp_line_edit2 = new QLineEdit;

        connect(temp_line_edit, SIGNAL(textChanged(const QString&)), car_lvl_signal_map_, SLOT(map()));
        connect(temp_line_edit2, SIGNAL(textChanged(const QString&)), car_lvl_signal_map_, SLOT(map()));

        car_lvl_signal_map_->setMapping(temp_line_edit, i+100);
        car_lvl_signal_map_->setMapping(temp_line_edit2, i+200);

        car_lvl_table_->setCellWidget(i,0,temp_line_edit);
        car_lvl_table_->setCellWidget(i,1,temp_line_edit2);
    }

    connect(car_lvl_signal_map_, SIGNAL(mapped(int)), this, SLOT(carCellChanged(int)));

    // connecting car stats items
    for(int i = 0; i < car_stats_table_->rowCount(); ++i) {
        QLineEdit* temp_line_edit = new QLineEdit;
        connect(temp_line_edit, SIGNAL(textChanged(const QString&)), car_stats_signal_map_, SLOT(map()));

        car_stats_signal_map_->setMapping(temp_line_edit, i+300);
        car_stats_table_->setCellWidget(i,0, temp_line_edit);
    }

    connect(car_stats_signal_map_, SIGNAL(mapped(int)), this, SLOT(carStatsCellChanged(int)));

    // connecting weather table items
    for (int i = 0; i < weather_table_->rowCount(); ++i) {
        QLineEdit* temp_line_edit = new QLineEdit();
        QLineEdit* temp_line_edit2 = new QLineEdit();
        QCheckBox* temp_check_box = new QCheckBox();
        temp_check_box->setStyleSheet(
                    QString("QCheckBox { background-color: rgba(200, 100, 100, 50);} ") +
                    QString("QCheckBox:hover{ color: rgb(35, 35, 75);border: 2px solid rgb(75, 75, 150);") +
                    QString("background-color: rgba(25, 150, 25, 101);}"));

        connect(temp_line_edit, SIGNAL(textChanged(const QString&)), weather_signal_map_, SLOT(map()));
        connect(temp_line_edit2, SIGNAL(textChanged(const QString&)), weather_signal_map_, SLOT(map()));
        connect(temp_check_box, SIGNAL(toggled(bool)), weather_signal_map_, SLOT(map()));

        weather_signal_map_->setMapping(temp_line_edit,i+400);
        weather_signal_map_->setMapping(temp_line_edit2,i+500);
        weather_signal_map_->setMapping(temp_check_box, i+600);

        weather_table_->setCellWidget(i,0,temp_line_edit);
        weather_table_->setCellWidget(i,1,temp_line_edit2);
        weather_table_->setCellWidget(i,2,temp_check_box);
    }

    connect(weather_signal_map_, SIGNAL(mapped(int)), this, SLOT(weatherCellChanged(int)));
}

void DCGroupBox::updateHandlers()
{
    if (driver_handler_ != 0) {
        driver_handler_->setFields(driver_stats);
    }

    if (car_handler_ != 0) {
        car_handler_->setLvls(car_lvl_);
        car_handler_->setWears(car_wear_);
        car_handler_->setStats(car_power_);
    }

    if (strategy_handler_ != 0) {
        strategy_handler_->setTemperatures(race_temperatures_);
        strategy_handler_->setHumidities(race_humidities_);
    }
}

void DCGroupBox::loadSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    // loading driver settings
    array<QVariant,9> driver_settings;
    for (unsigned int i = 0; i < driver_settings.size(); ++i) {
        driver_settings.at(i) = settings.value(driver_settings_text_.at(i), QVariant(0));
    }

    for (int i = 0; i < driver_table_->rowCount(); ++i) {
        static_cast<QLineEdit*>(driver_table_->cellWidget(i,0))->setText(driver_settings.at(i).toString());
        driver_stats.at(i) = driver_settings.at(i).toInt();
    }

    // loading car lvl settings
    array<QVariant, 11> car_lvl_settings;
    for (unsigned int i = 0;i < car_lvl_settings.size(); ++i) {
        car_lvl_settings.at(i) = settings.value(car_lvl_text_.at(i), QVariant(0));
    }

    for (int i = 0; i < car_lvl_table_->rowCount(); ++i) {
        static_cast<QLineEdit*>(car_lvl_table_->cellWidget(i,0))->setText(car_lvl_settings.at(i).toString());
        car_lvl_.at(i) =  car_lvl_settings.at(i).toInt();
    }

    // loading car wear settings
    array<QVariant, 11> car_wear_settings;
    for (unsigned int i = 0; i < car_wear_settings.size(); ++i) {
        car_wear_settings.at(i) = settings.value(car_wear_text_.at(i), QVariant(0));
    }

    for (int i = 0; i < car_lvl_table_->rowCount(); ++i) {
        static_cast<QLineEdit*>(car_lvl_table_->cellWidget(i,1))->setText(car_wear_settings.at(i).toString());
        car_wear_.at(i) = car_wear_settings.at(i).toInt();
    }

    // loading car stats settings
    array<QVariant, 3> car_stats_settings;
    for(unsigned int i = 0; i < car_stats_settings.size(); ++i) {
        car_stats_settings.at(i) = settings.value(car_stats_text_.at(i), QVariant(0));
    }

    for (int i = 0; i < car_stats_table_->rowCount(); ++i) {
        static_cast<QLineEdit*>(car_stats_table_->cellWidget(i,0))->setText(car_stats_settings.at(i).toString());
        car_power_.at(i) = car_stats_settings.at(i).toInt();
    }

    // loading weather settings
    array<QVariant, 6> weather_settings;
    for(unsigned int i = 0; i < weather_settings.size(); ++i) {
        weather_settings.at(i) = settings.value(weather_text_.at(i), QVariant(0));
    }

    for (int i = 0; i < weather_table_->rowCount(); ++i) {
        static_cast<QLineEdit*>(weather_table_->cellWidget(i,0))->setText(weather_settings.at(i).toString());
        race_temperatures_.at(i) = weather_settings.at(i).toDouble();
        static_cast<QLineEdit*>(weather_table_->cellWidget(i,1))->setText(weather_settings.at(i+3).toString());
        race_humidities_.at(i) = weather_settings.at(i+3).toDouble();
    }

    // finally updating handlers because we actually changed everything
    this->updateHandlers();
}

void DCGroupBox::saveSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    // saving driver settings
    for (unsigned int i = 0; i < driver_settings_text_.size(); ++i) {
        settings.setValue(driver_settings_text_.at(i), static_cast<QLineEdit*>(driver_table_->cellWidget(i,0))->text());
    }

    // saving car lvls to settings
    for (unsigned int i = 0; i < car_lvl_text_.size(); ++i) {
        settings.setValue(car_lvl_text_.at(i), static_cast<QLineEdit*>(car_lvl_table_->cellWidget(i,0))->text());
    }

    // saving car wears to settings
    for (unsigned int i = 0; i < car_wear_text_.size(); ++i) {
        settings.setValue(car_wear_text_.at(i), static_cast<QLineEdit*>(car_lvl_table_->cellWidget(i,1))->text());
    }

    // saving car stats
    for (unsigned int i = 0; i < car_stats_text_.size(); ++i) {
        settings.setValue(car_stats_text_.at(i), static_cast<QLineEdit*>(car_stats_table_->cellWidget(i,0))->text());
    }

    // saving weather
    for (unsigned int i = 0; i < weather_text_.size() / 2; ++i) {
        settings.setValue(weather_text_.at(i), static_cast<QLineEdit*>(weather_table_->cellWidget(i,0))->text());
    }
    for (unsigned int i = 0; i < weather_text_.size() / 2; ++i) {
        settings.setValue(weather_text_.at(i + 3), static_cast<QLineEdit*>(weather_table_->cellWidget(i,1))->text());
    }
}

void DCGroupBox::driverCellChanged(int row)
{
    QString temp_string = static_cast<QLineEdit*>(driver_table_->cellWidget(row,0))->text();

    // checking conversion
    bool can_conv = false;
    int value = 0;

    while (!can_conv) {
        if (temp_string.size() <= 0) temp_string = "0";
        value = temp_string.toInt(&can_conv);
        if (!can_conv)
            temp_string.chop(1);
    }

    // slightly modify result if it is not in correct range
    if (value < 0) value = 0;
    else if (value > 250) value = 250;

    static_cast<QLineEdit*>(driver_table_->cellWidget(row,0))->setText(QString::number(value));
}

void DCGroupBox::carCellChanged(int index)
{
    int column = index < 200 ? 0 : 1;
    int row = index % 100;

    QString temp_string = static_cast<QLineEdit*>(car_lvl_table_->cellWidget(row,column))->text();

    // checking conversion
    bool can_conv = false;
    int value = 0;

    while (!can_conv) {
        if (temp_string.size() <= 0) temp_string = "0";
        value = temp_string.toInt(&can_conv);
        if (!can_conv)
            temp_string.chop(1);
    }

    if (column == 0) {
        if (value < 0) value = 0;
        else if (value > 9) value = 9;
    } else {
        if (value < 0) value = 0;
        else if (value > 99) value = 99;
    }

    static_cast<QLineEdit*>(car_lvl_table_->cellWidget(row,column))->setText(QString::number(value));
}

void DCGroupBox::carStatsCellChanged(int row)
{
    int temp_row = row % 100;

    QString temp_string = static_cast<QLineEdit*>(car_stats_table_->cellWidget(temp_row,0))->text();

    // checking conversion
    bool can_conv = false;
    int value = 0;

    while (!can_conv) {
        if (temp_string.size() <= 0) temp_string = "0";
        value = temp_string.toInt(&can_conv);
        if (!can_conv)
            temp_string.chop(1);
    }

    if (value < 0) value = 0;
    else if (value > 250) value = 250;

    static_cast<QLineEdit*>(car_stats_table_->cellWidget(temp_row,0))->setText(QString::number(value));
}

void DCGroupBox::weatherCellChanged(int index)
{
    int column = index < 500 ? 0 : 1;
    column = index < 600 ? column : 2;
    int row = index % 100;

    if (column > 1) {
        race_weather_.at(row) = static_cast<QCheckBox*>(weather_table_->cellWidget(row,column))->isChecked();
        return;
    }

    QString temp_string = static_cast<QLineEdit*>(weather_table_->cellWidget(row,column))->text();

    // checking conversion
    bool can_conv = false;
    int value = 0;

    while (column < 2 && !can_conv) {
        if (temp_string.size() <= 0) temp_string = "0";
        value = temp_string.toInt(&can_conv);
        if (!can_conv)
            temp_string.chop(1);
    }

    if (column == 0) {
        if (value < 0) value = 0;
        else if (value > 50) value = 50;
    } else if (column == 1) {
        if (value < 0) value = 0;
        else if (value > 99) value = 99;
    }

    static_cast<QLineEdit*>(weather_table_->cellWidget(row,column))->setText(QString::number(value));

}
