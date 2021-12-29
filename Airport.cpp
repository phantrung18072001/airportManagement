#include <iostream>
#include "Airport.h"
#include "Plane.h"

using namespace std;

Airport::Airport(string MSB, float mass, float runwayLength, int spaceOfPlane, int spaceOfHelicopter) {
	this->MSB = MSB;
	this->mass = mass;
	this->runwayLength = runwayLength;
	this->spaceOfPlane = spaceOfPlane;
	this->spaceOfHelicopter = spaceOfHelicopter;
}

// chua xet truong hop gia tri thay doi be hon thi co cac may bay khong thoa man
void Airport::updateAirport(string MSB, float mass, float runwayLength, int spaceOfPlane, int spaceOfHelicopter) {
	this->MSB = MSB;
	this->mass = mass;
	this->runwayLength = runwayLength;
	this->spaceOfPlane = spaceOfPlane;
	this->spaceOfHelicopter = spaceOfHelicopter;
}

void Airport::addPlane(Plane p) {
	planes.push_back(p);
}

void Airport::addHelicopter(Helicopter h) {
	helicopters.push_back(h);
}

Airport::~Airport(){}
