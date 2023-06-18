#pragma once
#include "Body.h"
#include <vector>
class RotatingBody : virtual public Body {
public:
    RotatingBody(std::vector<double> currentXYZLocation, double _rotationalPeriod, 
                 double _rotationalAxisAngle, double geocentricLatitude);
    void step(double hours);

protected:
    double rotationalPeriod;             // rotational period in Earth days    
    double currentRotation = 0;          // starting rotation amount
    std::vector<double> rotationalAxis;  // vector of the rotational axis (determined via the angle)

private:
    void setup(double axisAngle,         // set initial look direction for observer
               double geocentricLat);    // and the axis vector to rotate about
};
