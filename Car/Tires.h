#pragma once
#include <string>
namespace Car
{
	class Tires
	{
	protected:
		//Tire Pressure in PSI (Pounds per Square Inch)
		//0 PSI means the tire is flat and 100 PSI is the maximum pressure
		//The tire pressure is used to calculate the speed of the car
		std::string producer;
		int tirePressure;
		int tireSize;

	public:
		Tires(std::string _producer, int tirePressure,int tireSize);
		void setTirePressure(int pressure);
		int getTirePressure();
		void setTireSize(int size);
		int getTireSize();
		void MoveVehicle(float& currentSpeed, float addedVelocity);
	};
}


