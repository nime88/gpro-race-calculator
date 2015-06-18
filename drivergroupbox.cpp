#include "drivergroupbox.h"

#include <QLineEdit>
#include <QDebug>
#include <QApplication>

DriverGroupBox::DriverGroupBox(QWidget *parent):
    QGroupBox(parent),
    driver_(new Driver),
    driver_table_(0)
{
    signal_map_ = new QSignalMapper(this);
}

void DriverGroupBox::init()
{
    driver_table_ = findChild<QTableWidget*>("driver_table");

    for(int i = 0; i < driver_table_->rowCount(); ++i) {
        QLineEdit* temp_line_edit = new QLineEdit;
        connect(temp_line_edit, SIGNAL(textChanged(const QString&)), signal_map_, SLOT(map()));
        signal_map_->setMapping(temp_line_edit, i);
        driver_table_->setCellWidget(i,0, temp_line_edit);
    }

    connect(signal_map_, SIGNAL(mapped(int)), this, SLOT(cellChanged(int)));
}

void DriverGroupBox::cellChanged(int row)
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
