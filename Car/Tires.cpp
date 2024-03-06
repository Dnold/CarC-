#include "Tires.h"
void Car::Tires::MoveVehicle(float& currentSpeed, float addedVelocity)
{
	currentSpeed += addedVelocity *(float)(tirePressure / 4);
}
Car::Tires::Tires(std::string _producer, int _tirePressure, int _tireSize)
{
	producer = _producer;
	tirePressure = _tirePressure;
	tireSize = _tireSize;
}
int Car::Tires::getTirePressure()
{
	return tirePressure;
}
void Car::Tires::setTirePressure(int pressure)
{
	tirePressure = pressure;
}
int Car::Tires::getTireSize()
{
	return tireSize;
}
void Car::Tires::setTireSize(int size)
{
	tireSize = size;
}

