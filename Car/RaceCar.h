#pragma once
#include "BaseCar.h"
#include "V8Engine.h"
class RaceCar : public BaseCar 
{
public:
	RaceCar(std::string name, std::string color, float tuningRate);
	RaceCar(std::string name, std::string color);
};

