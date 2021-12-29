#pragma once

#include "Plane.h"
#include "Helicopter.h"
#include <vector>

class Airport {
	public:
		Airport(std::string MSB, float mass, float runwayLength, int spaceOfPlane, int spaceOfHelicopter);
		std::string MSB;
		float sumMass = 0;
		float mass;
		float runwayLength;
		int spaceOfPlane;
		int spaceOfHelicopter;
		std::vector<Plane> planes;
		std::vector<Helicopter> helicopters;
		void updateAirport(std::string MSB, float mass, float runwayLength, int spaceOfPlane, int spaceOfHelicopter);
		void addPlane(Plane p);
		void addHelicopter(Helicopter h);
		~Airport();
};
