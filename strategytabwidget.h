#ifndef STRATEGYTABWIDGET_H
#define STRATEGYTABWIDGET_H

#include <memory>
#include <array>
using std::array;

#include <QTabWidget>
#include <QTableWidget>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QComboBox>

#include "settingshandler.h"

class StrategyTabWidget : public QTabWidget
{
    Q_OBJECT

private:
    std::shared_ptr<SettingsHandler> settingshandler_;

    QTableWidget* practice_table_item_;
    QTableWidget* add_practice_table_item_;
    QLabel* max_settings_text_item_;
    QLabel* settings_text_item_;
    QPlainTextEdit* space_range_item_;
    QPushButton* add_button_item_;

    array<QComboBox*, 6> comments_items_;

    array<int,5> comments_;

public:
    StrategyTabWidget(QWidget* parent);

    void setHandlers(std::shared_ptr<SettingsHandler> settingshandler) { settingshandler_ = settingshandler; }

public slots:
    void addButtonClicked();
    void settingChanged(QTableWidgetItem* item);
    void rangeChanged();

};

#endif // STRATEGYTABWIDGET_H
