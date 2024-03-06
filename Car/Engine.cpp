#include "Engine.h"
float Car::Engine::GetHorsePower()
{
	return horsePower;
}
void Car::Engine::SetHorsePower(float horsePower)
{
	this->horsePower = horsePower;
}
std::string Car::Engine::GetProducer()
{
	return producer;
}
void Car::Engine::SetProducer(std::string producer)
{
	this->producer = producer;
}
float Car::Engine::GoBrr() //Gibt die Kraft zurück die auf das Auto wirkt
{
	return  acceleration * this->GetHorsePower();

}
bool Car::Engine::isMotorRunning()
{
	return isRunning;
}
float Car::Engine::GetAcceleration()
{
	return acceleration;
}
void Car::Engine::SetAcceleration(float acceleration)
{
	this->acceleration = acceleration;
}
