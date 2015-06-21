#include "strategytabwidget.h"

#include <QLineEdit>

StrategyTabWidget::StrategyTabWidget(QWidget *parent):
    QTabWidget(parent),
    practice_table_item_(0), add_practice_table_item_(0),
    max_settings_text_item_(0), settings_text_item_(0), space_range_item_(0),
    add_button_item_(0)
{
}

void StrategyTabWidget::init()
{
    practice_table_item_ = this->findChild<QTableWidget*>("practice_settings_table");
    add_practice_table_item_ = this->findChild<QTableWidget*>("add_practice_settings_table");
    max_settings_text_item_ = this->findChild<QLabel*>("max_settings_text");
    settings_text_item_ = this->findChild<QLabel*>("settings_text");
    space_range_item_ = this->findChild<QLineEdit*>("space_value");
    add_button_item_ = this->findChild<QPushButton*>("add_setting_button");
    comments_items_.fill(0);
    comments_items_.at(0) = this->findChild<QComboBox*>("wing_setting_combo_box");
    comments_items_.at(1) = this->findChild<QComboBox*>("engine_setting_combo_box");
    comments_items_.at(2) = this->findChild<QComboBox*>("brakes_setting_combo_box");
    comments_items_.at(3) = this->findChild<QComboBox*>("gear_setting_combo_box");
    comments_items_.at(4) = this->findChild<QComboBox*>("suspension_setting_combo_box");

    // initializing fields

    for (int i = 0; i < add_practice_table_item_->columnCount(); ++i) {
        add_practice_table_item_->setCellWidget(0,i, new QLineEdit());
        static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,i))->setText("500");
    }
    space_range_item_->setText(QString::number(135));
    comments_.fill(0);
}

void StrategyTabWidget::loadSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    // first loading non moving stuff
    QVariant range = settings.value("practice/settings/range", QVariant(135));
    settingshandler_->setSpace(range.toDouble());
    space_range_item_->setText(range.toString());

    array<double,5> start_settings;
    start_settings.at(0) = settings.value("practice/settings/wingsetting", QVariant(500)).toDouble();
    start_settings.at(1) = settings.value("practice/settings/enginesetting", QVariant(500)).toDouble();
    start_settings.at(2) = settings.value("practice/settings/brakessetting", QVariant(500)).toDouble();
    start_settings.at(3) = settings.value("practice/settings/gearsetting", QVariant(500)).toDouble();
    start_settings.at(4) = settings.value("practice/settings/suspensionsetting", QVariant(500)).toDouble();
    settingshandler_->resetSettings(start_settings);

    // then loading comments
    std::vector< array<int,5> > comments;
    int size = settings.beginReadArray("practice/settings/comments");
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        array<int,5> tmp_com;
        tmp_com.at(0) = settings.value("wing").toInt();
        tmp_com.at(1) = settings.value("engine").toInt();
        tmp_com.at(2) = settings.value("brakes").toInt();
        tmp_com.at(3) = settings.value("gear").toInt();
        tmp_com.at(4) = settings.value("suspension").toInt();
        comments.push_back(tmp_com);
    }

    settings.endArray();

    // setting and executing comments
    for ( unsigned int i = 0; i < comments.size(); ++i) {
        settingshandler_->setComments(comments.at(i));
    }

    settingshandler_->executeComments();

    // generating settings and max settings texts
    QString max_settings_text = "Max (" +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(0))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(1))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(2))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(3))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(4))) +
            ")";
    QString settings_text = "Settings (" +
            QString::number(std::floor(settingshandler_->getSettings().at(0))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(1))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(2))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(3))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(4))) +
            ")";

    // assigning texts
    max_settings_text_item_->setText(max_settings_text);
    settings_text_item_->setText(settings_text);

    // updating add item field
    static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,0))->setText(QString::number(std::floor(settingshandler_->getMaxSettings().at(0))));
    for (unsigned int i = 0; i < settingshandler_->getMaxSettings().size(); ++i) {
        static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,i+1))->setText(QString::number(std::floor(settingshandler_->getMaxSettings().at(i))));
    }

}

void StrategyTabWidget::saveSettings(const QString &soft_name, const QString &company_name)
{
    QSettings settings(soft_name, company_name);

    // saving range
    QVariant range = space_range_item_->text();
    settings.setValue("practice/settings/range", range);

    // saving original settings
    settings.setValue("practice/settings/wingsetting", QVariant(settingshandler_->getOriginalSettings().at(0)));
    settings.setValue("practice/settings/enginesetting", QVariant(settingshandler_->getOriginalSettings().at(1)));
    settings.setValue("practice/settings/brakessetting", QVariant(settingshandler_->getOriginalSettings().at(2)));
    settings.setValue("practice/settings/gearsetting", QVariant(settingshandler_->getOriginalSettings().at(3)));
    settings.setValue("practice/settings/suspensionsetting", QVariant(settingshandler_->getOriginalSettings().at(4)));

    // saving current comments list
    settings.remove("practice/settings/comments");
    settings.beginWriteArray("practice/settings/comments");
    for(unsigned int i = 0; i < settingshandler_->getComments().size(); ++i) {
        settings.setValue("wing", QVariant(settingshandler_->getComments().at(i).at(0)));
        settings.setValue("engine", QVariant(settingshandler_->getComments().at(i).at(1)));
        settings.setValue("brakes", QVariant(settingshandler_->getComments().at(i).at(2)));
        settings.setValue("gear", QVariant(settingshandler_->getComments().at(i).at(3)));
        settings.setValue("suspension", QVariant(settingshandler_->getComments().at(i).at(4)));
    }
    settings.endArray();
}

void StrategyTabWidget::addButtonClicked()
{
    // adding row into the previous settings table
    int row = practice_table_item_->rowCount();
    practice_table_item_->insertRow(row);
    // then adjusting size of the table
    QSize size;
    size.setWidth(practice_table_item_->width());
    size.setHeight(practice_table_item_->height()+30);
    practice_table_item_->resize(size);

    // adding add_practice_table values to settings table
    for (int i = 0; i < practice_table_item_->columnCount(); ++i) {
        //QTableWidgetItem temp_item = *temp_table_from->item(0,i);
        practice_table_item_->setCellWidget(row,i, new QLabel(static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,i))->text()));
    }

    // setting space value range
    bool is_valid_space = false;
    double space = space_range_item_->text().toDouble(&is_valid_space);
    if (is_valid_space) {
        if (space < 0) space = 0;
        else if (space > 135) space = 135;
    } else space = 135;

    settingshandler_->setSpace(space);
    space_range_item_->setText(QString::number(space));

    // getting and transforming comments
    for (unsigned int i = 0; i < comments_items_.size(); ++i) {
        comments_.at(i) = -comments_items_.at(i)->currentIndex() + 3;
    }

    // updating settings handler
    settingshandler_->setComments(comments_);
    // instantly executing comments
    settingshandler_->executeComments();

    // generating settings and max settings texts
    QString max_settings_text = "Max (" +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(0))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(1))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(2))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(3))) + ", "  +
            QString::number(std::floor(settingshandler_->getMaxSettings().at(4))) +
            ")";
    QString settings_text = "Settings (" +
            QString::number(std::floor(settingshandler_->getSettings().at(0))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(1))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(2))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(3))) + ", "  +
            QString::number(std::floor(settingshandler_->getSettings().at(4))) +
            ")";

    // assigning texts
    max_settings_text_item_->setText(max_settings_text);
    settings_text_item_->setText(settings_text);

    // updating fields for easier next usage
    static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,0))->setText(QString::number(std::floor(settingshandler_->getMaxSettings().at(0))));
    for (unsigned int i = 0; i < settingshandler_->getMaxSettings().size(); ++i) {
        static_cast<QLineEdit*>(add_practice_table_item_->cellWidget(0,i+1))->setText(QString::number(std::floor(settingshandler_->getMaxSettings().at(i))));
    }
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
}

void StrategyTabWidget::settingChanged(QTableWidgetItem *item)
{
    bool is_int = false;
    int value = item->text().toInt(&is_int);

    if (is_int) {
        if (value < 0) value = 0;
        else if (value > 999) value = 999;
    } else {
        value = 0;
    }

    item->setText(QString::number(value));
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
}
