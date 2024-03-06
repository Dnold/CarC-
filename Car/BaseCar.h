#pragma once
#include "Engine.h"
#include "Suspension.h"
#include "Gears.h"
#include "Brakes.h"
#include "Frame.h"
#include "Tires.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <memory>

using namespace Car;
class BaseCar
{
protected:
	float currentSpeed;
	float baseMass;
	std::string name;
	float maxSpeed;

public:
	//Car Components
	std::shared_ptr<Engine> engine;
	std::shared_ptr<Suspension> suspension;
	std::shared_ptr<Frame> frame;
	std::shared_ptr<Gears> gears;
	std::shared_ptr<Brakes> brakes;
	std::shared_ptr<Tires> tires;

	//Virtual Functions
	void virtual StartMotor();
	void virtual StopMotor();
	void virtual Accelerate(float deltaTime);
	void virtual Decelerate(float deltaTime);
	void virtual TurnLeft(); //TODO: Implement
	void virtual TurnRight(); //TODO: Implement
	
	void SwitchGear(int gear);
	
	//Getters and Setters
	float GetCurrentSpeed();
	float GetWeight();
	void SetMaxSpeed(float maxSpeed);
};



