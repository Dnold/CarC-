#pragma once
#include <string>
namespace Car
{

	class Frame
	{
	public:
		Frame(std::string _color,float weight);
		std::string color;
		float weight; // in kg
		float GetWeight();
		void SetWeight(float weight);
	};
}


