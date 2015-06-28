#include "utility/regressions.h"

#include <cmath>



Regressions::Regressions(): wing_setting_cofactors_(0), engine_setting_cofactors_(0),
    gear_setting_cofactors_(0), brake_setting_cofactors_(0), suspension_setting_cofactors_(0),
    tyre_wear_lm_cofactors_(0)
{
}

Regressions::~Regressions()
{
    gsl_vector_free(wing_setting_cofactors_);
    gsl_vector_free(engine_setting_cofactors_);
    gsl_vector_free(gear_setting_cofactors_);
    gsl_vector_free(brake_setting_cofactors_);
    gsl_vector_free(suspension_setting_cofactors_);
    gsl_vector_free(tyre_wear_lm_cofactors_);
}

gsl_vector *Regressions::calculateSetting(const std::vector<double>& observed_data ,
                                   const std::vector<std::vector<double> > &data)
{
    // practice data
    unsigned int N = data.size();
    if (N <= 0 || observed_data.size() != data.size()) return 0;

    // wing linear regression
    unsigned int P = data.at(0).size();
    if (P <= 0) return 0;

    gsl_vector *y;
    gsl_matrix *X;
    gsl_vector *c;
    gsl_matrix *cov;

    // allocating space for the datastructures
    X = gsl_matrix_alloc(N,P);
    y = gsl_vector_alloc(N);

    // outputs
    c = gsl_vector_alloc(P);
    cov = gsl_matrix_alloc(P, P);

    //putting the data into X matrix
    for (unsigned int i = 0; i < N; ++i) {
        for (unsigned int j = 0; j < P; ++j) {
            gsl_matrix_set(X, i, j,
                           data.at(i).at(j));
        }
    }

    // fill vector of observed data
    for (unsigned int i = 0; i < N; ++i) {
        double observation = observed_data.at(i);
        gsl_vector_set(y, i, observation) ;
    }

    double chisq;

    // allocate temporary work space for gsl
    gsl_multifit_linear_workspace *work;
    work = gsl_multifit_linear_alloc(N, P);

    // now do the fit
    gsl_multifit_linear (X, y, c, cov, &chisq, work);

    // freeing the memory (f this legacy c stuff)
    gsl_matrix_free(X);
    gsl_matrix_free(cov);
    gsl_vector_free(y);
    //gsl_vector_free(c);

    return c;
}

std::vector < std::vector<double> > Regressions::getWingSettingData() {
    std::vector< std::vector<double> > return_data;
    for (unsigned int i = 0; i < practice_data_.size();  ++i) {
        std::vector<double> temp_array(7,0);
        temp_array.at(0) = practice_data_.at(i)->getValues()->weather.asDouble();
        temp_array.at(1) = static_cast<double>(practice_data_.at(i)->getValues()->temperature);
        temp_array.at(2) = static_cast<double>(practice_data_.at(i)->getValues()->track_handling);
        temp_array.at(3) = static_cast<double>(practice_data_.at(i)->getValues()->corners);
        temp_array.at(4) = static_cast<double>(practice_data_.at(i)->getValues()->car_front_wing_lvl);
        temp_array.at(5) = static_cast<double>(practice_data_.at(i)->getValues()->car_underbody_lvl);
        temp_array.at(6) = static_cast<double>(practice_data_.at(i)->getValues()->driver_concentration);

        return_data.push_back(temp_array);
    }

    return return_data;
}

std::vector<double> Regressions::getEngineObservations()
{
    std::vector<double> return_values(practice_data_.size(), 0);
    // fill vector of observed data
    for (unsigned int i = 0; i < return_values.size(); ++i) {
        double engine = static_cast<double>(practice_data_.at(i)->getValues()->engine);
        return_values.at(i) = engine;
    }

    return return_values;
}

std::vector<std::vector<double> > Regressions::getEngineSettingData()
{
    std::vector< std::vector<double> > return_values;
    //putting the data into X matrix
    for (unsigned int i = 0; i < practice_data_.size(); ++i) {
        std::vector<double> row(6,0);
        row.at(0) = practice_data_.at(i)->getValues()->weather.asDouble();
        row.at(1) = static_cast<double>(practice_data_.at(i)->getValues()->temperature);
        row.at(2) = static_cast<double>(practice_data_.at(i)->getValues()->track_power);
        row.at(3) = static_cast<double>(practice_data_.at(i)->getValues()->corners);
        row.at(4) = static_cast<double>(practice_data_.at(i)->getValues()->car_engine_lvl);
        row.at(5) = static_cast<double>(practice_data_.at(i)->getValues()->car_cooling_lvl);
        return_values.push_back(row);
    }

    return return_values;
}

std::vector<double> Regressions::getBrakesObservations()
{
    std::vector<double> return_values(practice_data_.size(),0);

    // fill vector of observed data
    for (unsigned int i = 0; i < return_values.size(); ++i) {
        double brakes = static_cast<double>(practice_data_.at(i)->getValues()->brakes);
        return_values.at(i) = brakes;
    }

    return return_values;
}

std::vector<std::vector<double> > Regressions::getBrakesSettingData()
{
    std::vector<std::vector<double> > return_values;

    //putting the data into X matrix
    for (unsigned int i = 0; i < practice_data_.size(); ++i) {
        std::vector<double> row(6,0);
        row.at(0) = practice_data_.at(i)->getValues()->weather.asDouble();
        row.at(1) = static_cast<double>(practice_data_.at(i)->getValues()->temperature);
        row.at(2) = static_cast<double>(practice_data_.at(i)->getValues()->car_brakes_lvl);
        row.at(3) = practice_data_.at(i)->getValues()->track_downforce.asDouble();
        row.at(4) = practice_data_.at(i)->getValues()->track_suspension.asDouble();
        row.at(5) = practice_data_.at(i)->getValues()->grip.asDouble();
        return_values.push_back(row);
    }

    return return_values;
}

std::vector<double> Regressions::getGearObservations()
{
    std::vector<double> return_values(practice_data_.size(), 0);
    // fill vector of observed data
    for (unsigned int i = 0; i < return_values.size(); ++i) {
        double gear = static_cast<double>(practice_data_.at(i)->getValues()->gear);
        return_values.at(i) = gear;
    }

    return return_values;
}

std::vector<std::vector<double> > Regressions::getGearSettingData()
{
    std::vector<std::vector<double> > return_values;
    //putting the data into X matrix
    for (unsigned int i = 0; i < practice_data_.size(); ++i) {
        std::vector<double> row(6,0);
        row.at(0) = practice_data_.at(i)->getValues()->weather.asDouble();
        row.at(1) = static_cast<double>(practice_data_.at(i)->getValues()->temperature);
        row.at(2) = static_cast<double>(practice_data_.at(i)->getValues()->car_gearbox_lvl);
        row.at(3) = practice_data_.at(i)->getValues()->track_downforce.asDouble();
        row.at(4) = practice_data_.at(i)->getValues()->track_suspension.asDouble();
        row.at(5) = practice_data_.at(i)->getValues()->grip.asDouble();
        return_values.push_back(row);
    }

    return return_values;
}

std::vector<double> Regressions::getSuspensionObservations()
{
    std::vector<double> return_values(practice_data_.size(),0);
    // fill vector of observed data
    for (unsigned int i = 0; i < return_values.size(); ++i) {
        double suspension = static_cast<double>(practice_data_.at(i)->getValues()->suspension);
        return_values.at(i) = suspension;
    }

    return return_values;
}

std::vector<std::vector<double> > Regressions::getSuspensionSettingData()
{
    std::vector<std::vector<double> > return_values;
    //putting the data into X matrix
    for (unsigned int i = 0; i < practice_data_.size(); ++i) {
        std::vector<double> row(4,0);
        row.at(0) = practice_data_.at(i)->getValues()->weather.asDouble();
        row.at(1) = static_cast<double>(practice_data_.at(i)->getValues()->temperature);
        row.at(2) = practice_data_.at(i)->getValues()->track_suspension.asDouble();
        row.at(3) = static_cast<double>(practice_data_.at(i)->getValues()->car_suspension_lvl);

        return_values.push_back(row);
    }

    return return_values;
}

std::vector<double> Regressions::getTyreWearObservations()
{
    std::vector<double> return_values(stint_data_.size(),0);
    //fill vector of observed data
    for (unsigned int i = 0; i < return_values.size(); ++i) {
        // first slightly modifying the observations to human readable form
        int final_percentage = stint_data_.at(i)->getValues()->final_percentage;
        final_percentage = 100 - final_percentage;
        double tyre_wear = static_cast<double>(final_percentage) / static_cast<double>(stint_data_.at(i)->getValues()->km);
        return_values.at(i) = tyre_wear;
    }

    return return_values;
}

std::vector<std::vector<double> > Regressions::getTyreWearLMSettingData()
{
    std::vector<std::vector<double> > return_values;
    //putting the data into X matrix
    for (unsigned int i = 0; i < stint_data_.size(); ++i) {
        std::vector<double> row(13,0);
        std::shared_ptr<StintType> values = stint_data_.at(i)->getValues();
        row.at(0) = values->temperature;
        row.at(1) = values->humidity;
        row.at(2) = values->tyre_type.asDouble();
        row.at(3) = values->track_tyre_wear.asDouble();
        row.at(4) = static_cast<double>(values->weather.getType() == 0 ? values->risk_clear : values->risk_wet);
        row.at(5) = static_cast<double>(values->driver_experience);
        row.at(6) = static_cast<double>(values->driver_aggressiveness);
        row.at(7) = static_cast<double>(values->driver_weight);
        row.at(8) = static_cast<double>(values->car_suspension_lvl) - static_cast<double>(values->car_suspension_wear) / 3;
        row.at(9) = values->weather.asDouble();
        row.at(10) = static_cast<double>(values->track_power);
        row.at(11) = static_cast<double>(values->track_handling);
        row.at(12) = static_cast<double>(values->track_acceleration);

        return_values.push_back(row);
    }

    return return_values;
}

void Regressions::calculateAllRegressionCofactors()
{
    // calculating settings related shit
    wing_setting_cofactors_ = calculateSetting(getWingObservations(), getWingSettingData());
    engine_setting_cofactors_ = calculateSetting(getEngineObservations(), getEngineSettingData());
    brake_setting_cofactors_ = calculateSetting(getBrakesObservations(), getBrakesSettingData());
    gear_setting_cofactors_ = calculateSetting(getGearObservations(), getGearSettingData());
    suspension_setting_cofactors_ = calculateSetting(getSuspensionObservations(), getSuspensionSettingData());

    // calculating race related shit
    tyre_wear_lm_cofactors_ = calculateSetting(getTyreWearObservations(), getTyreWearLMSettingData());
    //calculateTimeLM();
}

std::vector<double> Regressions::getWingObservations()
{
    std::vector<double> return_values(practice_data_.size(),0);

    for(unsigned int i = 0; i < return_values.size(); ++i){
        double fw = static_cast<double>(practice_data_.at(i)->getValues()->front_wing);
        double rw = static_cast<double>(practice_data_.at(i)->getValues()->rear_wing);

        return_values.at(i) = (fw + rw) / 2;
    }

    return return_values;
}

int Regressions::getWingSetting(const Weather &weather, const int &temperature,
                                const int &track_handling, const int &corners, const int &car_front_wing_lvl,
                                         const int &car_underbody_lvl, const int &driver_concentration)
{
    if (wing_setting_cofactors_ == 0)  wing_setting_cofactors_ = calculateSetting(getWingObservations(), getWingSettingData());
    if (wing_setting_cofactors_ == 0) return 0;


    double result = 0.0;
    result += gsl_vector_get(wing_setting_cofactors_, 0) * weather.asDouble();
    result += gsl_vector_get(wing_setting_cofactors_, 1) * static_cast<double>(temperature);
    result += gsl_vector_get(wing_setting_cofactors_, 2) * static_cast<double>(track_handling);
    result += gsl_vector_get(wing_setting_cofactors_, 3) * static_cast<double>(corners);
    result += gsl_vector_get(wing_setting_cofactors_, 4) * static_cast<double>(car_front_wing_lvl);
    result += gsl_vector_get(wing_setting_cofactors_, 5) * static_cast<double>(car_underbody_lvl);
    result += gsl_vector_get(wing_setting_cofactors_, 6) * static_cast<double>(driver_concentration);

    int final_result = std::round(result);

    return final_result;
}

int Regressions::getEngineSetting(const Weather &weather, const int &temperature, const int &track_power,
                                  const int &corners, const int &car_engine_lvl, const int &car_cooling_lvl)
{
    if (engine_setting_cofactors_ == 0) engine_setting_cofactors_ = calculateSetting(getEngineObservations(), getEngineSettingData());
    if (engine_setting_cofactors_ == 0) return 0;

    double result = 0.0;
    result += gsl_vector_get(engine_setting_cofactors_, 0) * weather.asDouble();
    result += gsl_vector_get(engine_setting_cofactors_, 1) * static_cast<double>(temperature);
    result += gsl_vector_get(engine_setting_cofactors_, 2) * static_cast<double>(track_power);
    result += gsl_vector_get(engine_setting_cofactors_, 3) * static_cast<double>(corners);
    result += gsl_vector_get(engine_setting_cofactors_, 4) * static_cast<double>(car_engine_lvl);
    result += gsl_vector_get(engine_setting_cofactors_, 5) * static_cast<double>(car_cooling_lvl);

    int final_result = std::round(result);

    return final_result;
}

int Regressions::getGearSetting(const Weather &weather, const int &temperature, const int &car_gearbox_lvl,
                                         const Downforce &track_downforce, const Suspension &track_suspension,
                                         const Grip &grip)
{
    if (gear_setting_cofactors_ == 0) gear_setting_cofactors_ = calculateSetting(getGearObservations(), getGearSettingData());
    if (gear_setting_cofactors_ == 0) return 0;

    double result = 0.0;
    result += gsl_vector_get(gear_setting_cofactors_, 0) * weather.asDouble();
    result += gsl_vector_get(gear_setting_cofactors_, 1) * static_cast<double>(temperature);
    result += gsl_vector_get(gear_setting_cofactors_, 2) * static_cast<double>(car_gearbox_lvl);
    result += gsl_vector_get(gear_setting_cofactors_, 3) * track_downforce.asDouble();
    result += gsl_vector_get(gear_setting_cofactors_, 4) * track_suspension.asDouble();
    result += gsl_vector_get(gear_setting_cofactors_, 5) * grip.asDouble();

    int final_result = std::round(result);

    return final_result;
}

int Regressions::getBrakeSetting(const Weather &weather, const int &temperature,const int &car_brakes_lvl,
                                 const Downforce &track_downforce, const Suspension &track_suspension,
                                 const Grip &grip)
{
    if (brake_setting_cofactors_ == 0)  brake_setting_cofactors_ = calculateSetting(getBrakesObservations(), getBrakesSettingData());
    if (brake_setting_cofactors_ == 0) return 0;

    double result = 0.0;
    result += gsl_vector_get(brake_setting_cofactors_, 0) * weather.asDouble();
    result += gsl_vector_get(brake_setting_cofactors_, 1) * static_cast<double>(temperature);
    result += gsl_vector_get(brake_setting_cofactors_, 2) * static_cast<double>(car_brakes_lvl);
    result += gsl_vector_get(brake_setting_cofactors_, 3) * track_downforce.asDouble();
    result += gsl_vector_get(brake_setting_cofactors_, 4) * track_suspension.asDouble();
    result += gsl_vector_get(brake_setting_cofactors_, 5) * grip.asDouble();

    int final_result = std::round(result);

    return final_result;
}

int Regressions::getSuspensionSetting(const Weather &weather, const int &temperature,
                                      const Suspension &track_suspension, const int &car_suspension_lvl)
{
    if (suspension_setting_cofactors_ == 0) suspension_setting_cofactors_ = calculateSetting(getSuspensionObservations(), getSuspensionSettingData());
    if (suspension_setting_cofactors_ == 0) return 0;

    double result = 0.0;
    result += gsl_vector_get(suspension_setting_cofactors_, 0) * weather.asDouble();
    result += gsl_vector_get(suspension_setting_cofactors_, 1) * static_cast<double>(temperature);
    result += gsl_vector_get(suspension_setting_cofactors_, 2) * track_suspension.asDouble();
    result += gsl_vector_get(suspension_setting_cofactors_, 3) * static_cast<double>(car_suspension_lvl);

    int final_result = std::round(result);

    return final_result;
}

double Regressions::getTyreWear(double temperature, double humidity, const Tyre &tyre_type,
                                const TyreWear &tyre_wear, int risk, int experience, int aggressiveness,
                                int weight, int car_suspension_lvl, int car_suspension_wear,
                                const Weather &weather, int tpower, int thandling, int tacceleration)
{
    if (tyre_wear_lm_cofactors_ == 0) tyre_wear_lm_cofactors_ = calculateSetting(getTyreWearObservations(), getTyreWearLMSettingData());
    if (tyre_wear_lm_cofactors_ == 0) return 0;

    double result = 0.0;
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 0) * temperature;
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 1) * humidity;
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 2) * tyre_type.asDouble();
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 3) * tyre_wear.asDouble();
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 4) * static_cast<double>(risk);
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 5) * static_cast<double>(experience);
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 6) * static_cast<double>(aggressiveness);
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 7) * static_cast<double>(weight);
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 8) * static_cast<double>(car_suspension_lvl) - static_cast<double>(car_suspension_wear) / 3;
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 9) * weather.asDouble();
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 10) * static_cast<double>(tpower);
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 11) * static_cast<double>(thandling);
    result += gsl_vector_get(tyre_wear_lm_cofactors_, 12) * static_cast<double>(tacceleration);

    return result;
}
