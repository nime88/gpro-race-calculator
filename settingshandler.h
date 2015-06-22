#ifndef SETTINGSHANDLER_H
#define SETTINGSHANDLER_H

#include <memory>
#include <array>
using std::array;

#include "databasehandler.h"
#include "regressions.h"

// normal usage order of the class is setting space first (important)
// then setting comments and finally executing the comments
enum SettingsSlots { SETTINGS_WING_SLOT = 0, SETTINGS_ENGINE_SLOT, SETTINGS_BRAKES_SLOT,
                     SETTINGS_GEAR_SLOT, SETTINGS_SUSPENSION_SLOT };

class SettingsHandler
{
private:
    // all settings should be immutable 5 slot arrays
    array<double,5> original_settings;
    array<double,5> settings_;
    array<double,5> max_settings_;
    array<double,5> min_settings_;

    // comments should be arbitary number of 5 slot arrays (hooray for c++11/14)
    std::vector< array<int,5> > comments_;

    // space determines how fast algorithm will converge ceiling(lg(org_space_)) steps
    double org_space_;
    array<double,5> space_;

    // disallowing copying
    SettingsHandler(const SettingsHandler&);
    SettingsHandler& operator=(const SettingsHandler&);

public:
    SettingsHandler();

    // iterate one round of comments
    void setComments(const array<int,5>& comments);
    // setting space
    void setSpace(const double space);

    inline const array<double,5>& getSpace() { return space_; }
    inline const array<double,5>& getSettings() { return settings_; }
    inline const array<double,5>& getMaxSettings() { return max_settings_; }
    inline const array<double,5>& getOriginalSettings() { return original_settings; }

    // TODO test inlining this when correct functionality has been reached
    array<double, 5> getSettingsFromDiff(std::shared_ptr<Regressions> regressions,
                                            double temperature_1, double temperature_2);
    const std::vector< array<int,5> >& getComments() { return comments_; }

    void resetSpace();
    void resetSettings(const array<double,5> &settings);
    void resetComments() { comments_.clear(); }
    const array<double, 5>& executeComments();
};

#endif // SETTINGSHANDLER_H
