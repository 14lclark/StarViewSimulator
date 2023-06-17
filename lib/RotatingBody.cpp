#include "RotatingBody.h"

RotatingBody::RotatingBody(std::vector<double> currentXYZLocation,
                          double _rotationalPeriod,
                          double _rotationalAxisAngle) 
                       : Body(currentXYZLocation), 
                        rotationalPeriod(_rotationalPeriod),
                        rotationalAxisAngle(_rotationalAxisAngle) {}

void RotatingBody::step(double hours) {
    double rotationChange = (2 * M_PI / rotationalPeriod) * (hours / 24);
    currentRotation += rotationChange;
}

double RotatingBody::getRotationAxis() {
    return rotationalAxisAngle;
}