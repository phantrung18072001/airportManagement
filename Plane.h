#pragma once
#include <string>

class Plane {
	public:
		Plane(std::string MMB,int capacity, float length, float width, float weight, float minLanding);
		std::string MMB;
		int capacity;
		float length;
		float width;
		float weight;
		float minLanding; /* chieu dai duong bang toi thieu */
		void updatePlane(std::string MMB, int capacity, float length, float width, float weight, float minLanding);
		~Plane();
};
