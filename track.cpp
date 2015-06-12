#include "track.h"

const array<char,16> Track::field_names_ = {"\"Track\".Laps", "\"Track\".Distance", "\"Track\".Power", "\"Track\".Handling",
                                            "\"Track\".Acceleration", "\"Track\".Downforce", "\"Track\".OverTaking",
                                            "\"Track\".Suspension", "\"Track\".FuelConsumption", "\"Track\".TyreWear",
                                            "\"Track\".AvgSpeed", "\"Track\".LapLength", "\"Track\".Corners",
                                            "\"Track\".Grip", "\"Track\".PitStop", "\"Track\".Name" };

Track::Track()
{    
}
