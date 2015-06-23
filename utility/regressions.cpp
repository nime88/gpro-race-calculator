#include "utility/regressions.h"

#include <cmath>

Regressions::Regressions(): wing_setting_cofactors_(0), engine_setting_cofactors_(0),
    gear_setting_cofactors_(0), brake_setting_cofactors_(0), suspension_setting_cofactors_(0)
{
}

Regressions::~Regressions()
{
    gsl_vector_free(wing_setting_cofactors_);
    gsl_vector_free(engine_setting_cofactors_);
    gsl_vector_free(gear_setting_cofactors_);
    gsl_vector_free(brake_setting_cofactors_);
    gsl_vector_free(suspension_setting_cofactors_);
}

void Regressions::calculateWingSetting()
{
    // practice data
    unsigned int N = practice_data_.size();
    if (N == 0) return;

    // wing linear regression
    int P = 7;

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
        gsl_matrix_set(X, i, 0,
                       practice_data_.at(i)->getValues()->weather.asDouble()); // weather
        gsl_matrix_set(X, i, 1,
                       static_cast<double>(practice_data_.at(i)->getValues()->temperature)); // temperature
        gsl_matrix_set(X, i, 2,
                       static_cast<double>(practice_data_.at(i)->getValues()->track_handling)); // track handling
        gsl_matrix_set(X, i, 3,
                       static_cast<double>(practice_data_.at(i)->getValues()->corners)); // track corners
        gsl_matrix_set(X, i, 4,
                       static_cast<double>(practice_data_.at(i)->getValues()->car_front_wing_lvl)); // front wing lvl
        gsl_matrix_set(X, i, 5,
                       static_cast<double>(practice_data_.at(i)->getValues()->car_underbody_lvl)); // underbody lvl
        gsl_matrix_set(X, i, 6,
                       static_cast<double>(practice_data_.at(i)->getValues()->driver_concentration)); // concentration
    }

    // fill vector of observed data
    for (unsigned int i = 0; i < N; ++i) {
        double fw = static_cast<double>(practice_data_.at(i)->getValues()->front_wing);
        double rw = static_cast<double>(practice_data_.at(i)->getValues()->rear_wing);
        gsl_vector_set(y, i, (fw+rw)/2) ;
    }

    double chisq;

    // allocate temporary work space for gsl
    gsl_multifit_linear_workspace *work;
    work = gsl_multifit_linear_alloc(N, P);

    // now do the fit
    gsl_multifit_linear (X, y, c, cov, &chisq, work);

    wing_setting_cofactors_ = c;

    // freeing the memory (f this legacy c stuff)
    gsl_matrix_free(X);
    gsl_matrix_free(cov);
    gsl_vector_free(y);
    //gsl_vector_free(c);

}

void Regressions::calculateEngineSetting()
{
    // practice data
    unsigned int N = practice_data_.size();
    if (N == 0) return;

    // wing linear regression
    int P = 6;

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
        gsl_matrix_set(X, i, 0,
                      practice_data_.at(i)->getValues()->weather.asDouble()); // weather
        gsl_matrix_set(X, i, 1,
                       static_cast<double>(practice_data_.at(i)->getValues()->temperature)); // temperature
        gsl_matrix_set(X, i, 2,
                       static_cast<double>(practice_data_.at(i)->getValues()->track_power)); // track power
        gsl_matrix_set(X, i, 3,
                       static_cast<double>(practice_data_.at(i)->getValues()->corners)); // corners
        gsl_matrix_set(X, i, 4,
                       static_cast<double>(practice_data_.at(i)->getValues()->car_engine_lvl)); // engine lvl
        gsl_matrix_set(X, i, 5,
                       static_cast<double>(practice_data_.at(i)->getValues()->car_cooling_lvl)); // cooling lvl
    }

    // fill vector of observed data
    for (unsigned int i = 0; i < N; ++i) {
        double engine = static_cast<double>(practice_data_.at(i)->getValues()->engine);
        gsl_vector_set(y, i, engine) ;
    }

    double chisq;

    // allocate temporary work space for gsl
    gsl_multifit_linear_workspace *work;
    work = gsl_multifit_linear_alloc(N, P);

    // now do the fit
    gsl_multifit_linear (X, y, c, cov, &chisq, work);

    engine_setting_cofactors_ = c;

    // freeing the memory (f this legacy c stuff)
    gsl_matrix_free(X);
    gsl_matrix_free(cov);
    gsl_vector_free(y);
    //gsl_vector_free(c);
}

void Regressions::calculateGearSetting()
{
    // practice data
    unsigned int N = practice_data_.size();
    if (N == 0) return;

    // wing linear regression
    int P = 6;

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
        gsl_matrix_set(X, i, 0,
                       practice_data_.at(i)->getValues()->weather.asDouble()); // weather
        gsl_matrix_set(X, i, 1,
                       static_cast<double>(practice_data_.at(i)->getValues()->temperature)); // temperature
        gsl_matrix_set(X, i, 2,
                       static_cast<double>(practice_data_.at(i)->getValues()->car_gearbox_lvl)); // car gearbox lvl
        gsl_matrix_set(X, i, 3,
                       practice_data_.at(i)->getValues()->track_downforce.asDouble()); // track downforce
        gsl_matrix_set(X, i, 4,
                       practice_data_.at(i)->getValues()->track_suspension.asDouble()); // track suspension
        gsl_matrix_set(X, i, 5,
                       practice_data_.at(i)->getValues()->grip.asDouble()); // grip
    }

    // fill vector of observed data
    for (unsigned int i = 0; i < N; ++i) {
        double gear = static_cast<double>(practice_data_.at(i)->getValues()->gear);
        gsl_vector_set(y, i, gear);
    }

    double chisq;

    // allocate temporary work space for gsl
    gsl_multifit_linear_workspace *work;
    work = gsl_multifit_linear_alloc(N, P);

    // now do the fit
    gsl_multifit_linear (X, y, c, cov, &chisq, work);

    gear_setting_cofactors_ = c;

    // freeing the memory (f this legacy c stuff)
    gsl_matrix_free(X);
    gsl_matrix_free(cov);
    gsl_vector_free(y);
    //gsl_vector_free(c);
}

void Regressions::calculateBrakeSetting()
{
    // practice data
    unsigned int N = practice_data_.size();
    if (N == 0) return;

    // wing linear regression
    int P = 6;

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
        gsl_matrix_set(X, i, 0,
                       practice_data_.at(i)->getValues()->weather.asDouble()); // weather
        gsl_matrix_set(X, i, 1,
                       static_cast<double>(practice_data_.at(i)->getValues()->temperature)); // temperature
        gsl_matrix_set(X, i, 2,
                       static_cast<double>(practice_data_.at(i)->getValues()->car_brakes_lvl)); // car brakes lvl
        gsl_matrix_set(X, i, 3,
                       practice_data_.at(i)->getValues()->track_downforce.asDouble()); // track downforce
        gsl_matrix_set(X, i, 4,
                       practice_data_.at(i)->getValues()->track_suspension.asDouble()); // track suspension
        gsl_matrix_set(X, i, 5,
                       practice_data_.at(i)->getValues()->grip.asDouble()); // grip
    }

    // fill vector of observed data
    for (unsigned int i = 0; i < N; ++i) {
        double brakes = static_cast<double>(practice_data_.at(i)->getValues()->brakes);
        gsl_vector_set(y, i, brakes);
    }

    double chisq;

    // allocate temporary work space for gsl
    gsl_multifit_linear_workspace *work;
    work = gsl_multifit_linear_alloc(N, P);

    // now do the fit
    gsl_multifit_linear (X, y, c, cov, &chisq, work);

    brake_setting_cofactors_ = c;

    // freeing the memory (f this legacy c stuff)
    gsl_matrix_free(X);
    gsl_matrix_free(cov);
    gsl_vector_free(y);
    //gsl_vector_free(c);
}

void Regressions::calculateSuspensionSetting()
{
    // practice data
    unsigned int N = practice_data_.size();
    if (N == 0) return;

    // wing linear regression
    int P = 4;

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
        gsl_matrix_set(X, i, 0,
                       practice_data_.at(i)->getValues()->weather.asDouble()); // weather
        gsl_matrix_set(X, i, 1,
                       static_cast<double>(practice_data_.at(i)->getValues()->temperature)); // temperature
        gsl_matrix_set(X, i, 2,
                       practice_data_.at(i)->getValues()->track_suspension.asDouble()); // track suspension
        gsl_matrix_set(X, i, 3,
                       static_cast<double>(practice_data_.at(i)->getValues()->car_suspension_lvl)); // car suspension
    }

    // fill vector of observed data
    for (unsigned int i = 0; i < N; ++i) {
        double suspension = static_cast<double>(practice_data_.at(i)->getValues()->suspension);
        gsl_vector_set(y, i, suspension);
    }

    double chisq;

    // allocate temporary work space for gsl
    gsl_multifit_linear_workspace *work;
    work = gsl_multifit_linear_alloc(N, P);

    // now do the fit
    gsl_multifit_linear (X, y, c, cov, &chisq, work);

    suspension_setting_cofactors_ = c;

    // freeing the memory (f this legacy c stuff)
    gsl_matrix_free(X);
    gsl_matrix_free(cov);
    gsl_vector_free(y);
    //gsl_vector_free(c);
}

void Regressions::calculateAllRegressionCofactors()
{
    calculateWingSetting();
    calculateEngineSetting();
    calculateGearSetting();
    calculateBrakeSetting();
    calculateSuspensionSetting();
}

int Regressions::getWingSetting(const Weather &weather, const int &temperature,
                                const int &track_handling, const int &corners, const int &car_front_wing_lvl,
                                         const int &car_underbody_lvl, const int &driver_concentration)
{
    if (wing_setting_cofactors_ == 0) calculateWingSetting();
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
    if (engine_setting_cofactors_ == 0) calculateEngineSetting();
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
    if (gear_setting_cofactors_ == 0) calculateGearSetting();
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
    if (brake_setting_cofactors_ == 0) calculateGearSetting();
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
    if (suspension_setting_cofactors_ == 0) calculateGearSetting();
    if (suspension_setting_cofactors_ == 0) return 0;

    double result = 0.0;
    result += gsl_vector_get(suspension_setting_cofactors_, 0) * weather.asDouble();
    result += gsl_vector_get(suspension_setting_cofactors_, 1) * static_cast<double>(temperature);
    result += gsl_vector_get(suspension_setting_cofactors_, 2) * track_suspension.asDouble();
    result += gsl_vector_get(suspension_setting_cofactors_, 3) * static_cast<double>(car_suspension_lvl);

    int final_result = std::round(result);

    return final_result;
}
