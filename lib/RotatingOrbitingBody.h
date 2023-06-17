#pragma once
#include "RotatingBody.h"
#include "OrbitingBody.h"
class RotatingOrbitingBody : public OrbitingBody, public RotatingBody {
    RotatingOrbitingBody(std::vector<double> currentXYZLocation,
        std::vector<double> centerCoords, double orbitDistance,
        double currentAngleInOrbit, double orbitalPeriod,
        double rotationalPeriod, double rotationalAxisAngle); 

    void step(double hours);
};