#include "RotatingOrbitingBody.h"
RotatingOrbitingBody::RotatingOrbitingBody(std::vector<double> currentXYZLocation,
    std::vector<double> centerCoords, double orbitDistance,
    double currentAngleInOrbit, double orbitalPeriod,
    double rotationalPeriod, double rotationalAxisAngle)
    : OrbitingBody(currentXYZLocation, centerCoords, orbitDistance, currentAngleInOrbit, orbitalPeriod),
    RotatingBody(currentXYZLocation, rotationalPeriod, rotationalAxisAngle), Body(currentXYZLocation){};

void RotatingOrbitingBody::step(double hours) {
    OrbitingBody::step(hours);
    RotatingBody::step(hours);
}