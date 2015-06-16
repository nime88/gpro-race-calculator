#ifndef REGRESSIONS_H
#define REGRESSIONS_H

#include <vector>
#include <memory>

#include "practice.h"
#include "databasehandler.h"

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_multifit.h>

class Regressions
{
   private:
    std::vector< std::shared_ptr<Practice> > practice_data_;

    // cofactors we have calculated
    gsl_vector *wing_setting_cofactors_;
    gsl_vector *engine_setting_cofactors_;
    gsl_vector *gear_setting_cofactors_;
    gsl_vector *brake_setting_cofactors_;
    gsl_vector *suspension_setting_cofactors_;

public:
    Regressions();

    ~Regressions();

    void calculateWingSetting();
    void calculateEngineSetting();
    void calculateGearSetting();
    void calculateBrakeSetting();
    void calculateSuspensionSetting();

    // this will calculate all cofactors that we'll need or are
    // able to calculate
    void calculateAllRegressionCofactors ();

    // setters
    inline void setPracticeData(const std::vector< std::shared_ptr<Practice> >& practice_data)
        { practice_data_ = practice_data; }

    int getWingSetting(const Weather& weather, const int& temperature, const int& track_handling,
                                const int& corners, const int& car_front_wing_lvl,
                                const int& car_underbody_lvl, const int& driver_concentration);
    int getEngineSetting(const Weather& weather, const int& temperature, const int& track_power,
                                  const int& corners, const int& car_engine_lvl,
                                  const int& car_cooling_lvl);
    int getGearSetting(const Weather& weather, const int& temperature, const int& car_gearbox_lvl,
                                const Downforce& track_downforce,
                                const Suspension& track_suspension, const Grip& grip);
    int getBrakeSetting(const Weather& weather, const int& temperature, const int& car_brakes_lvl,
                                 const Downforce& track_downforce,
                                 const Suspension& track_suspension, const Grip& grip);
    int getSuspensionSetting(const Weather& weather, const int& temperature, const Suspension& track_suspension,
                                      const int& car_suspension_lvl);
};

#endif // REGRESSIONS_H
