#ifndef FUELCONSUMPTION_H
#define FUELCONSUMPTION_H

#include <array>
using std::array;

#include <QString>

class FuelConsumption
{
private:
    const array<QString,5> types_{ {"Very low", "Low", "Medium", "High", "Very high"} };

    int type_;
public:
    FuelConsumption(const QString &fuel_consumption);

    inline int getType() const { return type_; }
    inline void setType(int type) {
        if (type < 0) type_ = 0;
        else if (type > 4) type_ = 4;
        else type_ = type;
    }

    inline QString asString() { return types_.at(type_); }

    FuelConsumption (FuelConsumption& fuel_consumption) { setType(fuel_consumption.getType()); }
    void operator=(const FuelConsumption& fuel_consumption) { type_ = fuel_consumption.getType();}
};

#endif // FUELCONSUMPTION_H
