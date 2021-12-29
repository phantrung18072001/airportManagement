#pragma once
#include <string>

class Helicopter {
	public:
		Helicopter(std::string MTT, float length, float width, float weight, float mass);
		std::string MTT;
		float length;
		float width;
		float weight;
		float mass; //tai trong
		void updateHelicopter(std::string MTT, float length, float width, float weight, float mass);
		~Helicopter();
};
