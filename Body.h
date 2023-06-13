#pragma once
#include <vector>
#include "Observer.h"
class Body {
public:
    Body(std::vector<double> _currentXYZLocation);
protected:
    std::vector<double> currentXYZLocation;
};