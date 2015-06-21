#ifndef STRATEGYTABWIDGET_H
#define STRATEGYTABWIDGET_H

#include <memory>
#include <array>
using std::array;

#include <QTabWidget>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
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
    QLineEdit* space_range_item_;
    QPushButton* add_button_item_;

    array<QComboBox*, 5> comments_items_;

    array<int,5> comments_;

public:
    StrategyTabWidget(QWidget* parent = 0);

    void init();

    void setHandlers(std::shared_ptr<SettingsHandler> settingshandler) { settingshandler_ = settingshandler; }
    void updateHandlers();

    void loadSettings(const QString& soft_name, const QString& company_name);
    void saveSettings(const QString& soft_name, const QString& company_name);

public slots:
    void addButtonClicked();
    void resetButtonClicked();
    void settingChanged(QTableWidgetItem* item);
    void rangeChanged();

};

#endif // STRATEGYTABWIDGET_H
