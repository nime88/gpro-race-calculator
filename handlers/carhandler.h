#ifndef CARHANDLER_H
#define CARHANDLER_H

#include <memory>
#include <array>
using std::array;

#include <QWidget>
#include <QTableWidgetItem>

#include "ui/dcgroupbox.h"
#include "core/car.h"

class DCGroupBox;

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

   DCGroupBox* dc_group_box_;

   // disabling copying
   CarHandler (const CarHandler&);
   CarHandler operator=(const CarHandler&);

public:
    CarHandler();

    // field initializations
    void initFields(DCGroupBox *parent);

    void setLvls(const array<int,11>& lvls);
    void setWears(const array<int,11>& wears);
    void setStats(const array<int,3>& stats);
};

#endif // CARHANDLER_H
