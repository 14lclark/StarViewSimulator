#pragma once
#include <vector>
#include "Observer.h"
#define M_PI 3.14159265358979323846
#define HOURS_PER_DAY 23.9344694444 // sidereal day

class Body {
public:
    Body(std::vector<double> _currentXYZLocation);
protected:
    std::vector<double> currentXYZLocation;
    Observer* observer;
};