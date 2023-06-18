#include "RotatingBody.h"
#include "vectortools.h"

RotatingBody::RotatingBody(std::vector<double> currentXYZLocation,
                           double _rotationalPeriod,
                           double rotationalAxisAngle,
                           double geocentricLatitude)
                       : Body(currentXYZLocation), 
                         rotationalPeriod(_rotationalPeriod)
                         {
    setup(rotationalAxisAngle, geocentricLatitude);
}

void RotatingBody::setup(double axisAngle, double lat) {
    rotationalAxis = { sin(axisAngle), 0, cos(axisAngle) };
    std::vector<double> equatorZenith = { -cos(axisAngle), 0, sin(axisAngle) };

    observer->setLookDirection(
        rotateAroundAxis(equatorZenith, cross(equatorZenith, rotationalAxis), lat)
    );
}

void RotatingBody::step(double hours) {
    double delta_rot = (2 * M_PI / rotationalPeriod) * (hours / HOURS_PER_DAY);
    currentRotation += delta_rot;
    
    std::vector<double> olddir = observer->getLookDirection();
    std::vector<double> newdir = rotateAroundAxis(olddir, rotationalAxis, delta_rot);
    observer->setLookDirection(newdir);
}
