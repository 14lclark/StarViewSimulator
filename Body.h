#pragma once
#define M_PI 3.14159265358979323846
#include <vector>
#include "Observer.h"
class Body {
public:
    Body(std::vector<double> _currentXYZLocation) : currentXYZLocation(_currentXYZLocation) {
        Observer* observer = new Observer();
    }
protected:
    std::vector<double> currentXYZLocation;
};




class RotatingOrbitingBody : public OrbitingBody, public RotatingBody {
    RotatingOrbitingBody(std::vector<double> currentXYZLocation, 
        std::vector<double> centerCoords, double orbitDistance,
        double currentLocationInOrbit, double orbitalPeriod,
        double rotationalPeriod, double rotationalAxisAngle)
        : OrbitingBody(currentXYZLocation, centerCoords, orbitDistance, currentLocationInOrbit, orbitalPeriod),
        RotatingBody(currentXYZLocation, rotationalPeriod, rotationalAxisAngle) {}

    void step(double hours) {
        OrbitingBody::step(hours);
        RotatingBody::step(hours);
    }
};