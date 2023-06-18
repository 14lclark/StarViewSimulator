#include "RotatingOrbitingBody.h"

RotatingOrbitingBody::RotatingOrbitingBody(std::vector<double> currentXYZLocation,
    std::vector<double> centerCoords, double orbitDistance,
    double currentAngleInOrbit, double orbitalPeriod,
    double rotationalPeriod, double rotationalAxisAngle, double geocentricLat)
    : OrbitingBody(currentXYZLocation, centerCoords, orbitDistance, currentAngleInOrbit, orbitalPeriod),
    RotatingBody(currentXYZLocation, rotationalPeriod, rotationalAxisAngle, geocentricLat),
    Body(currentXYZLocation){};

void RotatingOrbitingBody::step(double hours) {
    OrbitingBody::step(hours); // orbit first to update position before using observer
    RotatingBody::step(hours);
}