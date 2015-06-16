#include "track.h"

const array<QString,16> Track::field_names_ = {"\"Track\".Laps", "\"Track\".Distance", "\"Track\".Power", "\"Track\".Handling",
                                            "\"Track\".Acceleration", "\"Track\".Downforce", "\"Track\".OverTaking",
                                            "\"Track\".Suspension", "\"Track\".FuelConsumption", "\"Track\".TyreWear",
                                            "\"Track\".AvgSpeed", "\"Track\".LapLength", "\"Track\".Corners",
                                            "\"Track\".Grip", "\"Track\".PitStop", "\"Track\".Name" };

Track::Track()
{    
}

void Track::setValue(TrackSlots slot, const QVariant& value)
{
    //int int_value = 0;
    //double double_value = 0;
    //QString string_value = 0;

    //if  (value.)
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
