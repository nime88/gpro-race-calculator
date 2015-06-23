#ifndef OVERTAKING_H
#define OVERTAKING_H

#include <array>
using std::array;

#include <QString>

class Overtaking
{
private:
    const array<QString, 5> types_{ { "Very easy", "Easy", "Normal", "Hard", "Very hard"} };

    int type_;

public:
    Overtaking(const QString& overtaking);

    inline int getType() const { return type_; }
    inline void setType(int type) {
        if (type < 0) type_ = 0;
        else if (type > 4) type_ = 4;
        else type_ = type;
    }

    inline QString asString() { return types_.at(type_); }

    Overtaking (Overtaking& overtaking) { setType(overtaking.getType()); }

    void operator=(const Overtaking& overtaking) { type_ = overtaking.getType(); }
};

#endif // OVERTAKING_H
