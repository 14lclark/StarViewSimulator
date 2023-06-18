#include "Body.h"

Body::Body(std::vector<double> _currentXYZLocation) : currentXYZLocation(_currentXYZLocation) {
    observer = new Observer(_currentXYZLocation);
}