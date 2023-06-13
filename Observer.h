#pragma once
#include <vector>
#include "vectortools.h"

#define M_PI 3.14159265358979323846

class Observer {
public:
    Observer() {}
    //Observer(double geocentricLatitude, RotatingOrbitingBody *_body) {
    //    auto body = _body
    //    lookDirection = { cos(geocentricLatitude), 0, sin(geocentricLatitude) };
    //    const std::vector<double> negativeY = { 0, -1, 0 };
    //    lookDirection = rotateAroundAxis(lookDirection, negativeY, body->getRotationAxis());
    //   
    //}
    //Observer(double geocentricLatitude, OrbitingBody *_body) {
    //    auto body = _body
    //    lookDirection = { cos(geocentricLatitude), 0, sin(geocentricLatitude) };
    //}
    //Observer(double geocentricLatitude, RotatingBody *_body) {
    //    auto body = _body
    //    lookDirection = { cos(geocentricLatitude), 0, sin(geocentricLatitude) };
    //    const std::vector<double> negativeY = { 0, -1, 0 };
    //    lookDirection = rotateAroundAxis(lookDirection, negativeY, body->getRotationAxis());

    //}
    //
    void setLookDirection(std::vector<double> direction) {
        lookDirection = direction;
    }
    
private:
    double geocentricLatitude = 0; // geocentric latitude of the observer on the planet
    std::vector<double> lookDirection; // = { sin(rotationalAxisAngle), 0, -cos(rotationalAxisAngle) };

};