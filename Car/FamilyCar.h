#pragma once
#include "BaseCar.h"
class FamilyCar : public BaseCar
{
public:
	FamilyCar(std::string name, std::string color, float tuningRate);
	FamilyCar(std::string name, std::string color);

};

