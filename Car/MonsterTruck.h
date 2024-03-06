#pragma once
#include "BaseCar.h"
#include <string>
class MonsterTruck : public BaseCar
{
public:
	//MonsterTruck(std::string name, std::string color, float tuningRate);
	MonsterTruck(std::string name,std::string color,float tuningRate);
	MonsterTruck(std::string name, std::string color);
};

