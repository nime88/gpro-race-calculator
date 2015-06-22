#include "car.h"

const array<QString, 16> Car::car_lvl_names_ = {"Name (Track)", "CPower", "CHandling",
                                        "CAcceleration", "CChassis", "CEngine", "CFrontWing",
                                        "CRearWing", "CUnderbody", "CSidepods", "CCooling",
                                        "CGearbox", "CBrakes", "CSuspension", "CElectronics"};

const array<QString,13> Car::car_wear_names_ = {"Name (Track)", "CWChassis", "CWEngine",
                                                "CWFrontWing", "CWRearWing", "CWUnderbody", "CWSidepods",
                                                "CWCooling", "CWGearbox", "CWBrakes", "CWSuspension",
                                                "CWElectronics"};


Car::Car():
    track_name_("")
{
    //TODO make sure these fully fill the table
    car_stats_.fill(0);
    part_lvl_.fill(0);
    part_wear_.fill(0);
}
