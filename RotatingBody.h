#pragma once
#include "Body.h"
#include <vector>
class RotatingBody : virtual public Body {
public:
    RotatingBody(std::vector<double> currentXYZLocation, double _rotationalPeriod, double _rotationalAxisAngle);

    void step(double hours);

    double getRotationAxis();
protected:
    double rotationalPeriod;    // rotational period in Earth days    
    double rotationalAxisAngle; // axial tilt wrt +z axis
    double currentRotation = 0; // starting rotation amount
};
