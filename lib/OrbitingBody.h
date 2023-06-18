#pragma once
#include "Body.h"
#define DAYS_PER_YEAR 365.256363004 // sidereal year
class OrbitingBody : virtual public Body {
public:
    OrbitingBody(std::vector<double> currentXYZLocation,
        std::vector<double> _centerCoords, double _orbitDistance,
        double _currentAngleInOrbit, double _orbitalPeriod);

    void step(double hours);

protected:
    std::vector<double> orbitTangent; // tangent vector defining coord sys for satellites
    std::vector<double> centerCoords; // center of orbit
    
    double currentAngleLoc; // current location as an angle from centerCoords+(1,0,0)
    double orbitDistance;   // distance to Sun in AUs
    double orbitalPeriod;   // orbital period in Earth years
};
