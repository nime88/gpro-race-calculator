#include "ui/strategytabwidget.h"

#include <QLineEdit>

QString getSettingsText (const array<double,5>& settings) {
    QString settings_text = "Settings (" +
            QString::number(std::floor(settings.at(0))) + ", "  +
            QString::number(std::floor(settings.at(1))) + ", "  +
            QString::number(std::floor(settings.at(2))) + ", "  +
            QString::number(std::floor(settings.at(3))) + ", "  +
            QString::number(std::floor(settings.at(4))) +
            ")";

    return settings_text;
}

QString getMaxSettingsText(const array<double,5>& settings) {
    // generating settings and max settings texts
    QString max_settings_text = "Max (" +
            QString::number(std::floor(settings.at(0))) + ", "  +
            QString::number(std::floor(settings.at(1))) + ", "  +
            QString::number(std::floor(settings.at(2))) + ", "  +
            QString::number(std::floor(settings.at(3))) + ", "  +
            QString::number(std::floor(settings.at(4))) +
            ")";

    return max_settings_text;
}

QString getQ1SettingsText(const array<double,5>& settings) {
    QString settings_text = "Q1 Settings (" +
            QString::number(std::floor(settings.at(0))) + ", "  +
            QString::number(std::floor(settings.at(1))) + ", "  +
            QString::number(std::floor(settings.at(2))) + ", "  +
            QString::number(std::floor(settings.at(3))) + ", "  +
            QString::number(std::floor(settings.at(4))) +
            ")";

    return settings_text;
}

QString getQ2SettingsText(const array<double,5>& settings) {
    QString settings_text = "Q2 Settings (" +
            QString::number(std::floor(settings.at(0))) + ", "  +
            QString::number(std::floor(settings.at(1))) + ", "  +
            QString::number(std::floor(settings.at(2))) + ", "  +
            QString::number(std::floor(settings.at(3))) + ", "  +
            QString::number(std::floor(settings.at(4))) +
            ")";

    return settings_text;
}

QString getRaceSettingsText(const array<double,5>& settings) {
    QString settings_text = "Race Settings (" +
            QString::number(std::floor(settings.at(0))) + ", "  +
            QString::number(std::floor(settings.at(1))) + ", "  +
            QString::number(std::floor(settings.at(2))) + ", "  +
            QString::number(std::floor(settings.at(3))) + ", "  +
            QString::number(std::floor(settings.at(4))) +
            ")";

    return settings_text;
}

StrategyTabWidget::StrategyTabWidget(QWidget *parent):
    QTabWidget(parent),
    practice_table_item_(0), add_practice_table_item_(0),
    max_settings_text_item_(0), settings_text_item_(0), q1_settings_text_item_(0),
    q2_settings_text_item_(0), race_settings_text_item_(0), space_range_item_(0),
    add_button_item_(0), tyre_wear_table_item_(0)
{
    practice_signal_mapper_ = new QSignalMapper(this);
}

void StrategyTabWidget::init()
{
    practice_table_item_ = this->findChild<QTableWidget*>("practice_settings_table");
    add_practice_table_item_ = this->findChild<QTableWidget*>("add_practice_settings_table");
    max_settings_text_item_ = this->findChild<QLabel*>("max_settings_text");
    settings_text_item_ = this->findChild<QLabel*>("settings_text");
    q1_settings_text_item_ = this->findChild<QLabel*>("q1_settings_text");
    q2_settings_text_item_ = this->findChild<QLabel*>("q2_settings_text");
    race_settings_text_item_ = this->findChild<QLabel*>("race_settings_text");
    space_range_item_ = this->findChild<QLineEdit*>("space_value");
    add_button_item_ = this->findChild<QPushButton*>("add_setting_button");
    tyre_wear_table_item_ = this->findChild<QTableWidget*>("tyre_wear_table");
    risk_value_item_ = this->findChild<QLineEdit*>("risk_value");
    comments_items_.fill(0);
    comments_items_.at(0) = this->findChild<QComboBox*>("wing_setting_combo_box");
    comments_items_.at(1) = this->findChild<QComboBox*>("engine_setting_combo_box");
    comments_items_.at(2) = this->findChild<QComboBox*>("brakes_setting_combo_box");
    comments_items_.at(3) = this->findChild<QComboBox*>("gear_setting_combo_box");
    comments_items_.at(4) = this->findChild<QComboBox*>("suspension_setting_combo_box");

    // initializing fields

    for (int i = 0; i < add_practice_table_item_->columnCount(); ++i) {
        QLineEdit* temp_line_edit = new QLineEdit();
        connect(temp_line_edit, SIGNAL(textChanged(const QString&)), practice_signal_mapper_, SLOT(map()));
        practice_signal_mapper_->setMapping(temp_line_edit, i);

        temp_line_edit->setText("500");
        add_practice_table_item_->setCellWidget(0,i, temp_line_edit);
    }
    connect(practice_signal_mapper_, SIGNAL(mapped(int)), this, SLOT(cellChanged(int)));

    connect(space_range_item_, SIGNAL(textEdited(const QString&)), this, SLOT(rangeChanged()));

    space_range_item_->setText(QString::number(135));
    comments_.fill(0);

    int tyre_wear_rows = tyre_wear_table_item_->rowCount();
    int tyre_wear_columns = tyre_wear_table_item_->colorCount();

    for (int i = 0; i < tyre_wear_rows; ++i)
        for (int j = 0; j < tyre_wear_columns; ++j)
            tyre_wear_table_item_->setItem(i, j, new QTableWidgetItem);
}

void StrategyTabWidget::updateContents()
{
    // practice table item update
    for (unsigned int i = 0; i < settingshandler_->getOldSettings().size(); ++i) {
        int row = practice_table_item_->rowCount();
        practice_table_item_->insertRow(row);
        practice_table_item_->setCellWidget(i,0,
                                            new QLabel(QString::number(std::floor(settingshandler_->getOldSettings().at(i).at(0)))));
        for (unsigned int part = 0; part < 5; ++part) {
            practice_table_item_->setCellWidget(i,part + 1,
                                                new QLabel(QString::number(std::floor(settingshandler_->getOldSettings().at(i).at(part)))));
        }
    }

    // add practice table item update
    array<double,5> temp_max_settings_array = settingshandler_->getMaxSettings();
    for (unsigned int i = 0; i < temp_max_settings_array.size(); ++i) {
        if (i == 0) {
            QLineEdit* temp_edit_wut =  static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,i));
            temp_edit_wut->setText(QString::number(std::floor(temp_max_settings_array.at(i))));
        }

        QLineEdit* temp_edit =  static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,i+1));

        temp_edit->setText(QString::number(std::floor(temp_max_settings_array.at(i))));
    }

    // max settings text item
    max_settings_text_item_->setText(getMaxSettingsText(settingshandler_->getMaxSettings()));

    // settings text item
    settings_text_item_->setText(getSettingsText(settingshandler_->getSettings()));

    // q1 settings text item
    q1_settings_text_item_->setText(getQ1SettingsText(settingshandler_->getSettings()));

    // q2 settings text item
    array<double,5> q2_settings_array = settingshandler_->getSettingsFromDiff(regressions_,
                                                                              strategyhandler_->getQ1Temperature(),
                                                                              strategyhandler_->getQ2Temperature());
    q2_settings_text_item_->setText(getQ2SettingsText(q2_settings_array));

    // race settings text item
    array<double,5> race_settings_array = settingshandler_->getSettingsFromDiff(regressions_,
                                                                                strategyhandler_->getQ1Temperature(),
                                                                                strategyhandler_->getRaceTemperature());
    race_settings_text_item_->setText(getRaceSettingsText(race_settings_array));

    // space range item
    space_range_item_->setText(QString::number(std::ceil(settingshandler_->getOriginalSpace())));

    qDebug() << "Before tyre wear text";

    // tyre wear table
    for (int i = 0; i < tyre_wear_table_item_->columnCount(); ++i) {
        qDebug() << " Loopy loop: " << i;
        double temperature = strategyhandler_->getRaceTemperature();
        qDebug() << " humidity: " << i;
        double humidity = strategyhandler_->getRaceHumidity();
        qDebug() << " tyre type: " << i;
        Tyre tyre_type("Extra Soft");
        tyre_type.setType(i);
        qDebug() << " tyre wear: " << i;
        TyreWear tyre_wear(trackhandler_->getTrackTyreWear().asString());
        qDebug() << " risk: " << i;
        int risk = risk_value_item_->text().toInt();
        qDebug() << " exp: " << i;
        int experience = driverhandler_->getExperience();
        qDebug() << " agg: " << i;
        int aggressiveness = driverhandler_->getAggressiveness();
        qDebug() << " weight: " << i;
        int weight = driverhandler_->getWeight();
        qDebug() << " susp: " << i;
        int car_suspension = carhandler_->getLvl(CAR_SUSPENSION);
        qDebug() << " susp w: " << i;
        int car_suspension_wear = carhandler_->getWear(CAR_SUSPENSION);
        qDebug() << " weather: " << i;
        Weather weather("Dry");
        qDebug() << " power: " << i;
        int power = trackhandler_->getPower();
        qDebug() << " handling: " << i;
        int handling = trackhandler_->getHandling();
        qDebug() << " acceleration: " << i;
        int acceleration = trackhandler_->getAcceleration();
        qDebug() << " Going into tyre wear regression: " << i;
        double dry_tyre_wear = regressions_->getTyreWear(temperature, humidity, tyre_type, tyre_wear, risk,
                                                         experience, aggressiveness, weight, car_suspension,
                                                         car_suspension_wear, weather, power, handling, acceleration);
        qDebug() << "Dry tyre wear: " << dry_tyre_wear;

        tyre_wear_table_item_->item(0,i)->setText(QString::number(dry_tyre_wear));
    }

    qDebug() << "This is the end";
}

void StrategyTabWidget::loadSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    // first loading non moving stuff
    QVariant range = settings.value(range_settings_text_, QVariant(135));
    settingshandler_->setSpace(range.toDouble());

    array<double,5> start_settings;
    for (unsigned int i = 0; i < start_settings.size(); ++i) {
        start_settings.at(i) = settings.value(start_settings_text.at(i), QVariant(500)).toDouble();
    }

    settingshandler_->resetSettings(start_settings);

    // then loading comments
    std::vector< array<int,5> > comments;
    int size = settings.beginReadArray(comments_settings_text_);
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        array<int,5> tmp_com;
        for (unsigned int j = 0; j < tmp_com.size(); ++j) {
            tmp_com.at(j) = settings.value(comments_settings_slot_text_.at(j)).toInt();
        }
        comments.push_back(tmp_com);
    }

    settings.endArray();

    // setting and executing comments
    for ( unsigned int i = 0; i < comments.size(); ++i) {
        settingshandler_->setComments(comments.at(i));
    }

    settingshandler_->executeComments();

    updateContents();
}

void StrategyTabWidget::saveSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    // saving range
    QVariant range = space_range_item_->text();
    settings.setValue(range_settings_text_, range);

    // saving original settings
    for (unsigned int i = 0; i < start_settings_text.size(); ++i) {
        settings.setValue(start_settings_text.at(i),  QVariant(settingshandler_->getOriginalSettings().at(i)));
    }

    // saving current comments list
    settings.remove(comments_settings_text_);
    settings.beginWriteArray(comments_settings_text_);
    for(unsigned int i = 0; i < settingshandler_->getComments().size(); ++i) {
        settings.setArrayIndex(i);
        for (unsigned int j = 0; j < settingshandler_->getComments().at(i).size(); ++j) {
            settings.setValue(comments_settings_slot_text_.at(j), QVariant(settingshandler_->getComments().at(i).at(j)));
        }
    }
    settings.endArray();
}

void StrategyTabWidget::addButtonClicked()
{
    // setting space value range
    bool is_valid_space = false;
    double space = space_range_item_->text().toDouble(&is_valid_space);
    if (is_valid_space) {
        if (space < 0) space = 0;
        else if (space > 135) space = 135;
    } else space = 135;

    settingshandler_->setSpace(space);

    // getting and transforming comments
    for (unsigned int i = 0; i < comments_items_.size(); ++i) {
        comments_.at(i) = -comments_items_.at(i)->currentIndex() + 3;
    }

    // updating settings handler
    settingshandler_->setComments(comments_);
    // instantly executing comments
    settingshandler_->executeComments();

    updateContents();
}

void StrategyTabWidget::resetButtonClicked()
{
    // first resetting settings handler
    settingshandler_->resetSpace();
    array<double,5> reset = {500,500,500,500,500};
    settingshandler_->resetSettings(reset);
    settingshandler_->resetComments();

    // then emptying gui
    practice_table_item_->reset();
    while(practice_table_item_->rowCount() > 0)
        practice_table_item_->removeRow(0);

    updateContents();
}

void StrategyTabWidget::rangeChanged()
{
    bool is_double = false;
    double value = space_range_item_->text().toDouble(&is_double);

    if (is_double) {
        if (value < 0) value = 0;
        else if (value > 135) value = 135;
    } else {
        value = 0;
    }

    space_range_item_->setText(QString::number(value));

    settingshandler_->setSpace(value);

    updateContents();
}

void StrategyTabWidget::cellChanged(int column)
{
    bool is_int = false;
    QLineEdit* temp_line_edit = static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,column));
    int value = temp_line_edit->text().toInt(&is_int);

    if (is_int) {
        if (value < 0) value = 0;
        else if (value > 999) value = 999;
    } else {
        value = 0;
    }

    temp_line_edit->setText(QString::number(value));
}
