#ifndef TYRE_H
#define TYRE_H

#include <array>
using std::array;

#include <QString>

class Tyre
{
private:
    const array<QString,5> types{ {"Extra Soft", "Soft", "Medium", "Hard", "Rain"} };

    int type_;

public:
    Tyre(const QString& tyre_type);

    inline int getType() const { return type_; }
    inline void setType(int type) {
        if (type < 0) type_ = 0;
        else if (type > 4) type_ = 4;
        else type_ = type;
    }

    inline double asDouble() const {
        if (type_ > 4) return 4;
        else if (type_ > 3) return 3;
        else if (type_ > 2) return 2;
        else if (type_ > 1) return 1;
        else return 0;
    }

    Tyre (Tyre& tyre) { Tyre df("");  df.setType(tyre.getType()); }
    void operator=(const Tyre& tyre) { type_ = tyre.getType(); }
};

#endif // TYRE_H
