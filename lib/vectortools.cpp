#include <cmath>
#include <iostream>
#include <vector>



double dot(std::vector<double> x, std::vector<double> y) {
	double sum = 0;
	for (int i = 0; i < x.size(); i++) {
		sum += x[i] * y[i];
	}
	return sum;
};

double norm(std::vector<double> x) {
	return sqrt(dot(x, x));
};

std::vector<double> scalarMultiple(double a, std::vector<double> x) {
	std::vector<double> newx(x.size());
	for (int i = 0; i < x.size(); i++) {
		newx[i] = x[i] * a;
	}
	return newx;
};

std::vector<double> add(std::vector<double> x, std::vector<double> y) {
	std::vector<double> vecSum;
	for (int i = 0; i < x.size(); i++) {
		vecSum[i] = x[i] + y[i];
	}
	return vecSum;
};

std::vector<double> subtract(std::vector<double> x, std::vector<double> y) {
	return add(x, scalarMultiple(-1, y));
};

std::vector<double> cross(std::vector<double> x, std::vector<double> y) {
	std::vector<double> crossProd =
	{ x[1] * y[2] - x[2] * y[1], x[2] * y[0] - x[0] * y[2], x[0] * y[1] - x[1] * y[0] };
	return crossProd;
};

double angleBtwnVectors(std::vector<double> x, std::vector<double> y) {
	double xdoty = dot(x, y);
	return acos(xdoty / norm(x) / norm(y));
};

std::vector<double> projVecToVec(std::vector<double> x, std::vector<double> ontoY) {
	std::vector<double> unitY = scalarMultiple(1 / norm(ontoY), ontoY);
	return scalarMultiple(dot(x, unitY), unitY);
};

std::vector<double> projVecToRemoteOriginPlane(std::vector<double> vec,
											   std::vector<double> origin,
											   std::vector<double> planeNormal) {
	std::vector<double> apparentVec = subtract(vec, origin);
	std::vector<double> normalPart = projVecToVec(subtract(vec, origin), planeNormal);
	return subtract(apparentVec, normalPart);
};


std::vector<double> rotateAroundAxis(std::vector<double> vecToRotate, std::vector<double> axis, double angle) {
	std::vector<double> term1 = scalarMultiple( cos(angle), vecToRotate );
	std::vector<double> term2 = scalarMultiple( sin(angle), cross(axis, vecToRotate) );
	std::vector<double> term3 = scalarMultiple( (1 - cos(angle)) * dot(axis, vecToRotate), axis );

	std::vector<double> rotatedVector = add(term1, add(term2, term3));
	return rotatedVector;
};