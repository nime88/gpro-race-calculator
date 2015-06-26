#ifndef REGRESSIONS_H
#define REGRESSIONS_H

#include <vector>
#include <memory>

#include "core/practice.h"
#include "databasehandler.h"

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_multifit.h>

class Regressions
{
   private:
    std::vector< std::shared_ptr<Practice> > practice_data_;

    std::vector< std::shared_ptr<Stint> > stint_data_;

    // cofactors we have calculated
    gsl_vector *wing_setting_cofactors_;
    gsl_vector *engine_setting_cofactors_;
    gsl_vector *gear_setting_cofactors_;
    gsl_vector *brake_setting_cofactors_;
    gsl_vector *suspension_setting_cofactors_;
    gsl_vector *time_lm_cofactors_;

public:
    Regressions();

    ~Regressions();

    gsl_vector* calculateSetting(const std::vector<double> &observed_data , const std::vector<std::vector<double> >& data);

    void calculateTimeLM();

    // this will calculate all cofactors that we'll need or are
    // able to calculate
    void calculateAllRegressionCofactors ();

    // setters
    inline void setPracticeData(const std::vector< std::shared_ptr<Practice> >& practice_data)
        { practice_data_ = practice_data; }

    inline void setStintData(const std::vector< std::shared_ptr<Stint> >& stint_data) { stint_data_ = stint_data; }

    std::vector<double> getWingObservations();
    std::vector < std::vector<double> > getWingSettingData();
    std::vector<double> getEngineObservations();
    std::vector< std::vector<double> > getEngineSettingData();
    std::vector<double> getBrakesObservations();
    std::vector< std::vector<double> > getBrakesSettingData();
    std::vector<double> getGearObservations();
    std::vector< std::vector<double> > getGearSettingData();
    std::vector<double> getSuspensionObservations();
    std::vector< std::vector<double> > getSuspensionSettingData();

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
