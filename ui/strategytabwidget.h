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
#include <QSignalMapper>

#include "utility/regressions.h"
#include "handlers/settingshandler.h"
#include "handlers/strategy.h"


class StrategyTabWidget : public QTabWidget
{
    Q_OBJECT

private:
    std::shared_ptr<Regressions> regressions_;
    std::shared_ptr<SettingsHandler> settingshandler_;
    std::shared_ptr<Strategy> strategyhandler_;
    std::shared_ptr<TrackHandler> trackhandler_;
    std::shared_ptr<DriverHandler> driverhandler_;
    std::shared_ptr<CarHandler> carhandler_;

    const QString range_settings_text_ = "practice/settings/range";
    const array<QString, 5> start_settings_text{ {"practice/settings/wingsetting", "practice/settings/enginesetting",
                                                 "practice/settings/brakessetting", "practice/settings/gearsetting",
                                                 "practice/settings/suspensionsetting"} };
    const QString comments_settings_text_ = "practice/settings/comments";
    const array<QString,5> comments_settings_slot_text_ {{"wing", "engine", "brakes", "gear", "suspension"}};

    QTableWidget* practice_table_item_;
    QTableWidget* add_practice_table_item_;
    QLabel* max_settings_text_item_;
    QLabel* settings_text_item_;
    QLabel* q1_settings_text_item_;
    QLabel* q2_settings_text_item_;
    QLabel* race_settings_text_item_;
    QLineEdit* space_range_item_;
    QPushButton* add_button_item_;
    QTableWidget* tyre_wear_table_item_;
    QLineEdit* risk_value_item_;

    QSignalMapper* practice_signal_mapper_;

    array<QComboBox*, 5> comments_items_;

    array<int,5> comments_;

public:
    StrategyTabWidget(QWidget* parent = 0);

    void init();

    void setHandlers(std::shared_ptr<Regressions> regressions,
                     std::shared_ptr<SettingsHandler> settingshandler,
                     std::shared_ptr<Strategy> strategyhandler,
                     std::shared_ptr<TrackHandler> trackhandler,
                     std::shared_ptr<DriverHandler> driverhandler,
                     std::shared_ptr<CarHandler> carhandler) {
        settingshandler_ = settingshandler;
        regressions_ = regressions;
        strategyhandler_ = strategyhandler;
        trackhandler_ = trackhandler;
        driverhandler_ = driverhandler;
        carhandler_ = carhandler;
    }
    void updateHandlers();
    void updateContents();

    void loadSettings(const QString& soft_name, const QString& company_name);
    void saveSettings(const QString& soft_name, const QString& company_name);

public slots:
    void addButtonClicked();
    void resetButtonClicked();
    void rangeChanged();
    void cellChanged(int column);

};

#endif // STRATEGYTABWIDGET_H
