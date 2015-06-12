#include "settingshandler.h"

#include<iostream>
#include<cmath>
#include "regressions.h"

SettingsHandler::SettingsHandler()
{
    settings_.fill(0);
    max_settings_.fill(0);
    min_settings_.fill(0);
    space_.fill(0);
}

void SettingsHandler::setComments(const array<int, 5> &comments) {
    // storing comments for use
    comments_.push_back(comments);
}

void SettingsHandler::setSpace(const double space) {
    org_space_ = space;
    resetSpace();
}

std::vector<double> SettingsHandler::getSettingsFromDiff(std::shared_ptr<Regressions> regressions,
                                                         double temperature_diff, double humidity_diff)
{
    // getting all the settings from the regressions class
    double settings_diff_wing = 0;
    settings_diff_wing = regressions->getWingSetting(Weather::WEATHER_DRY,
                                                     temperature_diff, humidity_diff,0,0,0,0,0);
    double settings_diff_engine = 0;
    settings_diff_engine = regressions->getEngineSetting(Weather::WEATHER_DRY,
                                                          temperature_diff,humidity_diff,0,0,0,0);
    double settings_diff_gear = 0;
    settings_diff_gear = regressions->getGearSetting(Weather::WEATHER_DRY,
                                                      temperature_diff,humidity_diff,0,
                                                      Downforce::DOWNFORCE_MEDIUM,
                                                      Suspension::SUSPENSION_MEDIUM,Grip::GRIP_MEDIUM);
    double settings_diff_brakes = 0;
    settings_diff_brakes = regressions->getBrakeSetting(Weather::WEATHER_DRY,
                                                         temperature_diff, humidity_diff,0,Downforce::DOWNFORCE_MEDIUM,
                                                         Suspension::SUSPENSION_MEDIUM,Grip::GRIP_MEDIUM);
    double settings_diff_suspension = 0;
    settings_diff_suspension = regressions->getSuspensionSetting(Weather::WEATHER_DRY,
                                                                 temperature_diff, humidity_diff,
                                                                 Suspension::SUSPENSION_MEDIUM,0);

    // then calculating difference to normal settings
    std::vector<double> temp_vector;
    temp_vector.push_back(settings_diff_wing + getSettings().at(0));
    temp_vector.push_back(settings_diff_engine + getSettings().at(1));
    temp_vector.push_back(settings_diff_brakes + getSettings().at(2));
    temp_vector.push_back(settings_diff_gear + getSettings().at(3));
    temp_vector.push_back(settings_diff_suspension + getSettings().at(4));

    return temp_vector;

}

void SettingsHandler::resetSpace() {
    space_.fill(org_space_);
}

void SettingsHandler::resetSettings(const array<double,5> &settings) {
    if (settings.size() != 5) return;

    for (unsigned int i = 0; i < 5; ++i) {
        settings_.at(i) = settings.at(i);
        max_settings_.at(i) = settings.at(i);
        min_settings_.at(i) = settings.at(i);
    }
}

std::vector<double> SettingsHandler::executeComments() {
    resetSettings(array<double,5>(500));

    for (unsigned int i = 0; i < comments_.size(); ++i) {
        for (unsigned int part = 0; part < 5; ++part) {
            max_settings_.at(part) = max_settings_.at(part) +
                    space_.at(part) / 2 + space_.at(part) * comments_.at(i).at(part);
            min_settings_.at(part) = max_settings_.at(part) - org_space_;
            space_.at(part) = std::abs(comments_.at(i).at(part)) < 3 ?
                        space_.at(part) / 2 : space_.at(part);

            settings_.at(part) = (max_settings_.at(part) + min_settings_.at(part)) / 2;
        }
    }

    return settings_;
}


