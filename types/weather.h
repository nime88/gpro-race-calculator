#ifndef WEATHER_H
#define WEATHER_H

#include <array>
using std::array;

#include <QString>

class Weather
{
private:
    const array<QString,2> types{ {"Wet", "Dry"} };

    int type_;

public:
    Weather(const QString& weather);

    inline int getType() const { return type_; }
    inline void setType(int type) {
        if (type < 0) type_ = 0;
        else if (type > 2) type_ = 2;
        else type_ = type;
    }

    inline double asDouble() const { return type_ < 1 ? 0 : 1; }

    Weather (Weather& weather) { Weather df("");  df.setType(weather.getType()); }

    void operator=(const Weather& weather) { type_ = weather.getType(); }
};

#endif // WEATHER_H
