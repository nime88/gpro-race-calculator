#ifndef SUSPENSION_H
#define SUSPENSION_H

#include <array>
using std::array;

#include <QString>

class Suspension
{
private:
    const array<QString,3> types_{ { "Soft", "Medium", "Hard" } };

    int type_;
public:
    Suspension(const QString& suspension);

    inline int getType() const { return type_; }
    inline void setType(int type) {
        if (type < 0) type_ = 0;
        else if (type > 2) type_ = 2;
        else type_ = type;
    }

    inline double asDouble() const {
        if (type_ > 1) return 2;
        else if (type_ > 0) return 1;
        else return 0;
    }

    inline QString asString() { return types_.at(type_); }

    Suspension (Suspension& suspension) { setType(suspension.getType()); }

    void operator=(const Suspension& suspension) { type_ = suspension.getType(); }
};

#endif // SUSPENSION_H
