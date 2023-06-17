#pragma once
#include <vector>
#include "Observer.h"
#define M_PI 3.14159265358979323846

class Body {
public:
    Body(std::vector<double> _currentXYZLocation);
protected:
    std::vector<double> currentXYZLocation;
};