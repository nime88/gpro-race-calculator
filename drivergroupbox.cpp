#include "drivergroupbox.h"

#include <QLineEdit>
#include <QDebug>

DriverGroupBox::DriverGroupBox(QWidget *parent):
    QGroupBox(parent),
    driver_(new Driver),
    driver_table_(0)
{
}

void DriverGroupBox::init()
{
    driver_table_ = findChild<QTableWidget*>("driver_table");

    for(unsigned int i = 0; i < driver_table_->rowCount(); ++i) {
        driver_table_->setItem(i,0, new QTableWidgetItem("line edit"));
    }
}



void DriverGroupBox::itemChanged(QTableWidgetItem * item) {
    if (item == 0 || item->text().size() == 0) return;

    qDebug() << "Allright lets do THISSSS! \n";

    //checking if int conversion can be done
    bool int_conv = false;
    int result_int = item->text().toInt(&int_conv);

    if (!int_conv) {
        qDebug() << item->text() << "\n";
        QLineEdit * line_edit = new QLineEdit;
        line_edit->setText(item->text());
        qDebug() << line_edit->text() << "\n";
        line_edit->backspace();
        qDebug() << line_edit->text() << "\n";
        item->setText(line_edit->text());
        qDebug() << item->text() << "\n";
        return;
    }

    // slightly modify result if it is not in correct range
    if (result_int < 0) result_int = 0;
    else if (result_int > 250) result_int = 250;

    item->setText(QString::number(result_int));
    // then finally updating driver
    driver_->setStatValue(static_cast<DriverStatSlots>(item->row()+1), result_int);
}
