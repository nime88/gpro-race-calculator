#ifndef TYREWEAR_H
#define TYREWEAR_H

#include <array>
using std::array;

#include <QString>

class TyreWear
{
private:
    const array<QString,5> types_{ {"Very low", "Low", "Medium", "High", "Very high"} };

    int type_;
public:
    TyreWear(const QString& tyre_wear);

    inline int getType() const { return type_; }
    inline void setType(int type) {
        if (type < 0) type_ = 0;
        else if (type > 4) type_ = 4;
        else type_ = type;
    }

    inline QString asString() { return types_.at(type_); }

    TyreWear (TyreWear& tyre_wear) { setType(tyre_wear.getType()); }
    void operator=(const TyreWear& tyre_wear) { type_ = tyre_wear.getType(); }
};

#endif // TYREWEAR_H
