#ifndef CARHANDLER_H
#define CARHANDLER_H

#include <memory>
#include <QWidget>
#include <QTableWidgetItem>

#include "car.h"

enum CarHandlerSlots { CHASSIS_SLOT = 0, ENGINE_SLOT, FRONT_WING_SLOT, REAR_WING_SLOT,
                       UNDERBODY_SLOT, SIDEPODS_SLOT, COOLING_SLOT, GEARBOX_SLOT,
                       BRAKES_SLOT, SUSPENSION_SLOT, ELECTRONICS_SLOT };

class CarHandler
{
private:
   Car* car_;

   // ui items
   QTableWidgetItem* car_lvl_fields_[11];
   QTableWidgetItem* car_wear_fields_[11];
   QTableWidgetItem* power_item_;
   QTableWidgetItem* handling_item_;
   QTableWidgetItem* acceleration_item_;

   // disabling copying
   CarHandler (const CarHandler&);
   CarHandler operator=(const CarHandler&);

public:
    CarHandler();

    // getters
    inline int getCarLvl(CarHandlerSlots slot) { return car_->getValueBySlot(slot + car_->getLvlDiff()); }
    inline int getCarWear(CarHandlerSlots slot) { return car_->getValueBySlot(slot + car_->getWearDiff()); }

    // setters
    inline void setCarLvl(const CarHandlerSlots& part, int car_lvl) { car_->setField(car_lvl, part + car_->getLvlDiff()); }
    inline void setCarWear(const CarHandlerSlots& part, int car_wear) { car_->setField(car_wear, part + car_->getWearDiff()); }

    inline void setPower(int power) { car_->setField(power, CarSlots::CAR_POWER); }
    inline void setHandling(int handling) { car_->setField(handling, CarSlots::CAR_HANDLING); }
    inline void setAcceleration(int acceleration) { car_->setField(acceleration, CarSlots::CAR_ACCELERATION); }

    // field initializations
    void initFields(std::shared_ptr<QWidget> parent);
};

#endif // CARHANDLER_H
