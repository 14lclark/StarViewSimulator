#pragma once
#include <vector>
#include "vectortools.h"
#define IMAGE_SIZE 1024 // length and width bc image will be symmetric, power of 2

class Observer {
public:
    Observer(std::vector<double> myLocation);
    std::vector<double> getLookDirection();
    void setLookDirection(std::vector<double> direction);
    void setLocation(std::vector<double> newLocation);
    bool ICanSeeThis(double fov, std::vector<double> location);
    int currentView[IMAGE_SIZE] = {};
private:
    double geocentricLatitude = 0; // geocentric latitude of the observer on the planet
    std::vector<double> lookDirection = { 0, 0, 0 };
    std::vector<double> myLocation;
    
};