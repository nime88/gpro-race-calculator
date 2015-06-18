#ifndef CARHANDLER_H
#define CARHANDLER_H

#include <memory>
#include <array>
using std::array;

#include <QWidget>
#include <QTableWidgetItem>

#include "ui/cargroupbox.h"
#include "car.h"

class CarGroupBox;

enum CarHandlerSlots { CHASSIS_SLOT = 0, ENGINE_SLOT, FRONT_WING_SLOT, REAR_WING_SLOT,
                       UNDERBODY_SLOT, SIDEPODS_SLOT, COOLING_SLOT, GEARBOX_SLOT,
                       BRAKES_SLOT, SUSPENSION_SLOT, ELECTRONICS_SLOT };

class CarHandler
{
private:
   std::shared_ptr<Car> car_;

   array<int,11> car_lvl_;
   array<int,11> car_wear_;
   array<int,3> car_power_;

   CarGroupBox* car_group_box_;

   // disabling copying
   CarHandler (const CarHandler&);
   CarHandler operator=(const CarHandler&);

public:
    CarHandler();

    // field initializations
    void initFields(CarGroupBox *parent);
};

#endif // CARHANDLER_H
