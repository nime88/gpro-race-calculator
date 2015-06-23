#ifndef GRIP_H
#define GRIP_H

#include <array>
using std::array;

#include <QString>


class Grip
{
private:
    const array<QString, 5> types_{ { "Very Low", "Low", "Medium", "High", "Very High"} };

    int type_;
public:
    Grip(const QString& grip);

    inline int getType() const { return type_; }
    inline void setType(int type) {
        if (type < 0) type_ = 0;
        else if (type > 4) type_ = 4;
        else type_ = type;
    }

    inline double asDouble() const {
        if (type_ > 3) return 4;
        else if (type_ > 2) return 3;
        else if (type_ > 1) return 2;
        else if (type_ > 0) return 1;
        else return 0;
    }

    inline QString asString() { return types_.at(type_); }

    Grip (Grip& grip) { setType(grip.getType()); }

    void operator=(const Grip& grip) { type_ = grip.getType(); }
};

#endif // GRIP_H
