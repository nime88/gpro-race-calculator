#include "drivergroupbox.h"

DriverGroupBox::DriverGroupBox(QWidget *parent)
{
}

void DriverGroupBox::itemChanged(QTableWidgetItem * item) {
    if (item->text().size() == 0) return;
    //checking if int conversion can be done
    bool int_conv = false;
    int result_int = item->text().toInt(&int_conv);

    // slightly modify result if it is not in correct range
    if (int_conv) {
        if (result_int < 0) result_int = 0;
        else if (result_int > 250) result_int = 250;
    } else {
        QString temp_text = item->text();
        temp_text.chop(temp_text.size()-1);
        item->setText(temp_text);
        result_int = 0;
    }

    // then finally updating driver
    driver_->setStatValue(static_cast<DriverStatSlots>(item->row()+1), result_int);
}
