#ifndef DOWNFORCE_H
#define DOWNFORCE_H

#include <array>
using std::array;

#include <QString>

class Downforce
{
private:
    const array<QString,3> types_{ {"Low", "Medium", "High"} };

    int type_;
public:
    Downforce(const QString& downforce);

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

    Downforce (Downforce& downforce) { setType(downforce.getType()); }
    void operator=(const Downforce &downforce) { type_ = downforce.getType(); }
};

#endif // DOWNFORCE_H
