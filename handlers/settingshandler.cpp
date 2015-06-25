#include "handlers/settingshandler.h"

#include<iostream>
#include<cmath>

#include "utility/regressions.h"

SettingsHandler::SettingsHandler(): old_settings_()
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

array<double,5> SettingsHandler::getSettingsFromDiff(std::shared_ptr<Regressions> regressions,
                                                      double temperature_1, double temperature_2)
{
    // getting all the settings from the regressions class
    double settings_diff_wing = 0;
    settings_diff_wing = regressions->getWingSetting(Weather(""),
                                                     temperature_2,0,0,0,0,0);
    settings_diff_wing -= regressions->getWingSetting(Weather(""),
                                                      temperature_1,0,0,0,0,0);
    double settings_diff_engine = 0;
    settings_diff_engine = regressions->getEngineSetting(Weather(""),
                                                          temperature_2,0,0,0,0);
    settings_diff_engine -= regressions->getEngineSetting(Weather(""),
                                                          temperature_1,0,0,0,0);
    double settings_diff_gear = 0;
    settings_diff_gear = regressions->getGearSetting(Weather(""),
                                                      temperature_2,0,
                                                      Downforce(""), Suspension(""),
                                                     Grip(""));
    settings_diff_gear -= regressions->getGearSetting(Weather(""),
                                                      temperature_1,0,
                                                      Downforce(""), Suspension(""),
                                                     Grip(""));
    double settings_diff_brakes = 0;
    settings_diff_brakes = regressions->getBrakeSetting(Weather(""),
                                                         temperature_2,0,Downforce(""),
                                                         Suspension(""),Grip(""));
    settings_diff_brakes -= regressions->getBrakeSetting(Weather(""),
                                                         temperature_1,0,Downforce(""),
                                                         Suspension(""),Grip(""));
    double settings_diff_suspension = 0;
    settings_diff_suspension = regressions->getSuspensionSetting(Weather(""),
                                                                 temperature_2, Suspension(""), 0);
    settings_diff_suspension -= regressions->getSuspensionSetting(Weather(""),
                                                                 temperature_1, Suspension(""), 0);

    // then calculating difference to normal settings
    array<double,5> temp_array;
    temp_array.at(0) = settings_diff_wing + getSettings().at(0);
    temp_array.at(1) = settings_diff_engine + getSettings().at(1);
    temp_array.at(2) = settings_diff_brakes + getSettings().at(2);
    temp_array.at(3) = settings_diff_gear + getSettings().at(3);
    temp_array.at(4) = settings_diff_suspension + getSettings().at(4);

    return temp_array;

}

void SettingsHandler::resetSpace() {
    space_.fill(org_space_);
}

void SettingsHandler::resetSettings(const array<double,5> &settings) {
    if (settings.size() != 5) return;

    original_settings = settings;
    settings_ = settings;
    max_settings_ = settings;
    min_settings_ = settings;
    old_settings_.clear();
}

const array<double, 5> &SettingsHandler::executeComments() {
    array<double,5> temp_settings;
    temp_settings.fill(500);
    resetSettings(temp_settings);

    for (unsigned int i = 0; i < comments_.size(); ++i) {
        old_settings_.push_back(max_settings_);
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


