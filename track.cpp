#include "track.h"

const array<QString,16> Track::field_names_ = {"Laps", "Distance", "Power", "Handling",
                                            "Acceleration", "Downforce", "OverTaking",
                                            "Suspension", "FuelConsumption", "TyreWear",
                                            "AvgSpeed", "LapLength", "Corners",
                                            "Grip", "PitStop", "Name" };

Track::Track()
{    
}

void Track::setValue(TrackSlots slot, const QVariant& value)
{
    // TODO maybe check if we can do the transformations ^^

    // assigning correct value
    switch (slot) {
    case TRACK_ACCELERATION: {
        acceleration_ = value.toInt();
        break;
    }
    case TRACK_AVG_SPEED: {
        avg_speed_ = value.toDouble();
        break;
    }
    case TRACK_CORNERS: {
        corners_ = value.toInt();
        break;
    }
    case TRACK_DISTANCE: {
        distance_ = value.toInt();
        break;
    }
    case TRACK_DOWNFORCE: {
        downforce_ = value.toString();
        break;
    }
    case TRACK_FUEL_CONSUMPTION: {
        fuel_consumption_ = value.toString();
        break;
    }
    case TRACK_GRIP: {
        grip_ = value.toString();
        break;
    }
    case TRACK_HANDLING: {
        handling_ = value.toInt();
        break;
    }
    case TRACK_LAPS: {
        laps_ = value.toInt();
        break;
    }
    case TRACK_LAP_LENGTH: {
        lap_length_ = value.toDouble();
        break;
    }
    case TRACK_NAME: {
        name_ = value.toString();
        break;
    }
    case TRACK_OVERTAKING: {
        overtaking_ = value.toString();
        break;
    }
    case TRACK_PIT_STOP: {
        pit_stop_ = value.toDouble();
        break;
    }
    case TRACK_POWER: {
        power_ = value.toInt();
        break;
    }
    case TRACK_SUSPENSION: {
        suspension_ = value.toString();
        break;
    }
    case TRACK_TYRE_WEAR: {
        tyre_wear_ = value.toString();
        break;
    }
    default:
        break;
    }
}
