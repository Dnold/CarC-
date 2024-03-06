#include "Brakes.h"

Car::Brakes::Brakes(std::string producer, float breakForce)
{
	this->producer = producer;
	this->breakForce = breakForce;
}
float Car::Brakes::GetBreakForce()
{
	return breakForce;
}
void Car::Brakes::SetBreakForce(float breakForce)
{
	this->breakForce = breakForce;
}
void Car::Brakes::GoSCREEECH(float& currentspeed, float breakVelocity) { //brakeVelocity is the speed which the car will lose when braking
	
	currentspeed -= breakVelocity;
	
	
}