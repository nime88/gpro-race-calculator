#ifndef PRACTICEHANDLER_H
#define PRACTICEHANDLER_H

#include <memory>

#include "core/practice.h"

class PracticeHandler
{
private:
    std::shared_ptr<Practice> practice_data_;

public:
    PracticeHandler();
};

#endif // PRACTICEHANDLER_H
