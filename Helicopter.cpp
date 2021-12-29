#include "Helicopter.h"

using namespace std;

Helicopter::Helicopter(string MTT, float length, float width, float weight, float mass){
	this->MTT = MTT;
	this->length = length;
	this->width = width;
	this->weight = weight;
	this->mass = mass;
}

void Helicopter::updateHelicopter(string MTT, float length, float width, float weight, float mass){
	this->MTT = MTT;
	this->length = length;
	this->width = width;
	this->weight = weight;
	this->mass = mass;
}


Helicopter::~Helicopter(){}
