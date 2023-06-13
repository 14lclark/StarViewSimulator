#include "Observer.h"
#include "vectortools.h"
#include <vector>

void Observer::setLookDirection(std::vector<double> direction) {
    lookDirection = direction;
};

void Observer::setLocation(std::vector<double> newLocation) {
    myLocation = newLocation;
}

bool Observer::ICanSeeThis(double fov, std::vector<double> myLoc, std::vector<double> distantLoc) {
    double angle = angleBtwnVectors(lookDirection, subtract(distantLoc, myLoc));
    return (angle <= fov / 2.0);
};