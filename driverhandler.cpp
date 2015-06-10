#include "driverhandler.h"

#include <iostream>

DriverHandler::DriverHandler() : driver_(Driver)
{
    std::fill(fields_, fields_[9], 0);
    std::cout << "Driver Field:.. " << fields_[0] << std::endl;
}

void DriverHandler::initFields(std::shared_ptr<QWidget> parent) {

    // iterating through the fields and initializing them appropriately
    for (DriverSlots i = DRIVER_OVERALL-2; i < DRIVER_WEIGHT - 1; ++i) {
        QString temp_field_name = "";
        switch(i + 2) {
            case DRIVER_OVERALL: temp_field_name = "overall_edit"; break;
            case DRIVER_CONCENTRATION: temp_field_name = "concentration_edit"; break;
            case DRIVER_TALENT: temp_field_name = "talent_edit"; break;
            case DRIVER_AGGRESSIVENESS: temp_field_name = "aggressiveness_edit"; break;
            case DRIVER_EXPERIENCE: temp_field_name = "experience_edit"; break;
            case DRIVER_TECHNICAL_INSIGHT: temp_field_name = "technical_insight_edit"; break;
            case DRIVER_STAMINA: temp_field_name = "stamina_edit"; break;
            case DRIVER_CHARISMA: temp_field_name = "charisma_edit"; break;
            case DRIVER_MOTIVATION: temp_field_name = "motivation_edit"; break;
            case DRIVER_WEIGHT: temp_field_name = "weight_edit"; break;
        default: break;
        }

        if (fields_[i] == 0)
            fields_[i] = parent->findChild<QPlainTextEdit*>(temp_field_name);

        QString temp_string(QString("%1").arg(getValueBySlot(i + 2)));
        fields_[i]->setPlainText(temp_string);
    }
}


