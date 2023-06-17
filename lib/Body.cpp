#include "Body.h"

Body::Body(std::vector<double> _currentXYZLocation) : currentXYZLocation(_currentXYZLocation) {
    Observer* observer = new Observer(_currentXYZLocation);
}