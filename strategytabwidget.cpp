#include "strategytabwidget.h"

StrategyTabWidget::StrategyTabWidget(QWidget *parent):
    practice_table_item_(0), add_practice_table_item_(0),
    max_settings_text_item_(0), settings_text_item_(0), space_range_item_(0),
    add_button_item_(0)
{
    practice_table_item_ = parent->findChild<QTableWidget*>("practice_settings_table");
    add_practice_table_item_ = parent->findChild<QTableWidget*>("add_practice_settings_table");
    max_settings_text_item_ = parent->findChild<QLabel*>("max_settings_text");
    settings_text_item_ = parent->findChild<QLabel*>("settings_text");
    space_range_item_ = parent->findChild<QPlainTextEdit*>("space_value");
    add_button_item_ = parent->findChild<QPushButton*>("add_setting_button");
    comments_items_.fill(0);
    comments_items_.at(0) = parent->findChild<QComboBox*>("wing_setting_combo_box");
    comments_items_.at(1) = parent->findChild<QComboBox*>("engine_setting_combo_box");
    comments_items_.at(2) = parent->findChild<QComboBox*>("brakes_setting_combo_box");
    comments_items_.at(3) = parent->findChild<QComboBox*>("gear_setting_combo_box");
    comments_items_.at(4) = parent->findChild<QComboBox*>("suspension_setting_combo_box");

    // initializing fields
    for (int i = 0; i < add_practice_table_item_->columnCount(); ++i) {
        add_practice_table_item_->setItem(0,i, new QTableWidgetItem());
        add_practice_table_item_->item(0,i)->setText("500");
    }
    space_range_item_->setPlainText(QString::number(135));
    comments_.fill(0);

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
        practice_table_item_->setItem(row,i,new QTableWidgetItem(*add_practice_table_item_->item(0,i)));
    }

    // setting space value range
    bool is_valid_space = false;
    double space = space_range_item_->toPlainText().toDouble(is_valid_space);
    if (is_valid_space) {
        if (space < 0) space = 0;
        else if (space > 135) space = 135;
    } else space = 135;

    settingshandler_->setSpace(space);
    space_range_item_->setPlainText(QString::number(space));

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
    add_practice_table_item_->item(0,0)->setText(QString::number(std::floor(settingshandler_->getMaxSettings().at(0))));
    for (unsigned int i = 0; i < settingshandler_->getMaxSettings().size(); ++i) {
        add_practice_table_item_->item(0,i+1)->setText(QString::number(std::floor(settingshandler_->getMaxSettings().at(i))));
    }
}

void StrategyTabWidget::settingChanged(QTableWidgetItem *item)
{
    bool is_int = false;
    int value = item->text().toInt(is_int);

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
    double value = space_range_item_->toPlainText().toDouble(is_double);

    if (is_int) {
        if (value < 0) value = 0;
        else if (value > 135) value = 135;
    } else {
        value = 0;
    }

    space_range_item_->setPlainText(QString::number(value));
}
