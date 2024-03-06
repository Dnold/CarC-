#include "Frame.h"
Car::Frame::Frame(std::string color, float _weight)
{
	this->color = color;
	weight = _weight;

}
void Car::Frame::SetWeight(float weight)
{
	this->weight = weight;
}
float Car::Frame::GetWeight()
{
	return weight;
}