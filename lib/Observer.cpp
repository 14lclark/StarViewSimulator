#include "Observer.h"
#include "vectortools.h"
#include <vector>

Observer::Observer(std::vector<double> currentXYZLocation) : myLocation(currentXYZLocation) {}

std::vector<double> Observer::getLookDirection() {
    return lookDirection;
}

void Observer::setLookDirection(std::vector<double> direction) {
    lookDirection = direction;
};

void Observer::setLocation(std::vector<double> newLocation) {
    myLocation = newLocation;
};

bool Observer::ICanSeeThis(double fov, std::vector<double> location) {
    double angle = angleBtwnVectors(lookDirection, subtract(location, myLocation));
    return (angle <= fov / 2.0);
};
