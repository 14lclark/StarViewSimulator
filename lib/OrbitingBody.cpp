#include "OrbitingBody.h"

OrbitingBody::OrbitingBody(std::vector<double> currentXYZLocation,
    std::vector<double> _centerCoords, double _orbitDistance,
    double _currentAngleInOrbit, double _orbitalPeriod)
    : Body(currentXYZLocation),
    centerCoords(_centerCoords),
    orbitDistance(_orbitDistance),
    currentAngleLoc(_currentAngleInOrbit),
    orbitalPeriod(_orbitalPeriod) {}

void OrbitingBody::step(double hours) {
    double locationAngleChange = 
        (2 * M_PI / (orbitalPeriod * DAYS_PER_YEAR)) * (hours / HOURS_PER_DAY);
    currentAngleLoc += locationAngleChange;
}