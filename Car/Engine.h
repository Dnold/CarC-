#pragma once
#include <string>
namespace Car
{
	class Engine
	{
	protected:
		std::string producer;
		float horsePower;
		bool isRunning = false;
		float acceleration;
	public:
		Engine(std::string producer, float horsePower,float acceleration) : producer(producer), horsePower(horsePower),acceleration(acceleration) {}
		void virtual StartMotor() = 0;
		void virtual StopMotor() = 0;
		float virtual GoBrr();
		float GetHorsePower();
		void SetHorsePower(float horsePower);
		std::string GetProducer();
		void SetProducer(std::string producer);
		bool isMotorRunning();
		float GetAcceleration();
		void SetAcceleration(float acceleration);
	};
}
	



