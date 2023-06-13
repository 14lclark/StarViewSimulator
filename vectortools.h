#pragma once
#include <vector>

double dot(std::vector<double> x, std::vector<double> y);
double angleBtwnVectors(std::vector<double> x, std::vector<double> y);
std::vector<double> scalarMultiple(double a, std::vector<double> x);
std::vector<double> add(std::vector<double> x, std::vector<double> y);
std::vector<double> subtract(std::vector<double> x, std::vector<double> y);
std::vector<double> cross(std::vector<double> x, std::vector<double> y);
std::vector<double> rotateAroundAxis(std::vector<double> vecToRotate, std::vector<double> axis, double angle);
std::vector<double> projVecToVec(std::vector<double> x, std::vector<double> ontoY);
std::vector<double> projVecToPlaneThroughOrigin(std::vector<double> x, std::vector<double> planeNormal);
