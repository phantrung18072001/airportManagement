#include "Plane.h"

using namespace std;

Plane::Plane(string MMB,int capacity, float length, float width, float weight, float minLanding){
	this->MMB = MMB;
	this->capacity = capacity;
	this->length = length;
	this->width = width;
	this->weight = weight;
	this->minLanding = minLanding;
}

void Plane::updatePlane(string MMB, int capacity, float length, float width, float weight, float minLanding){
	this->MMB = MMB;
	this->capacity = capacity;
	this->length = length;
	this->width = width;
	this->weight = weight;
	this->minLanding = minLanding;
}


Plane::~Plane(){}
