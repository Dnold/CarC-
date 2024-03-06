#pragma once
#include "Engine.h"
namespace Car {
	class InlineFourEngine : public Engine
	{
	public:
		InlineFourEngine(std::string _producer, float _horsePower, float _acceleration) : Engine(_producer, _horsePower, _acceleration) {}
		void virtual StartMotor() override; //Starts the motor
		void virtual StopMotor() override; //Stops the motor
	};
}


