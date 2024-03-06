#include "BaseCar.h"

//Getters and Setters
float BaseCar::GetCurrentSpeed()
{
	return this->currentSpeed;
}
float BaseCar::GetWeight()
{
	return this->baseMass;
}
void BaseCar::SetMaxSpeed(float maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

//Virtual Functions standard implementations
void BaseCar::Accelerate(float deltaTime) {
	if (engine->isMotorRunning() == false) {
		return; //early return if the motor is not running
	}
	if (GetCurrentSpeed() >= maxSpeed) { 
		currentSpeed = maxSpeed; //early return if the speed is already at max
		return;
	}
	if (GetCurrentSpeed() < -maxSpeed) {
		currentSpeed = -maxSpeed;
		return; //early return if the speed is already at max
	}
	float mass = baseMass + frame->GetWeight(); //Calculate the mass of the car
	float force = engine->GoBrr() * gears->GetGearRatio(); //Calculate the force that the engine applies to the car
	float acceleration = force / mass; //Calculate the acceleration of the car
	tires->MoveVehicle(currentSpeed, (acceleration * deltaTime)); //Move the car
}

void BaseCar::Decelerate(float deltaTime) {

	if (std::abs(currentSpeed) < 14) { // If the speed is close to zero, stop the car
		//float sind halt sehr ungenau
		currentSpeed = 0;
		return;
	}
	float mass = baseMass + frame->GetWeight(); //Calculate the mass of the car
	float averageBreakForce = brakes->GetBreakForce(); //Calculate the average break force

	float deceleration = averageBreakForce / mass; //Calculate the deceleration of the car
	if (GetCurrentSpeed() < 0)
	{
		deceleration = -deceleration; //If the car is driving backwards, the deceleration is negative
	}
	brakes->GoSCREEECH(currentSpeed, (deceleration * deltaTime)); //Brake with the calculated deceleration



}
void BaseCar::StartMotor()
{
	engine->StartMotor();
}
void BaseCar::StopMotor()
{
	engine->StopMotor();
}
void BaseCar::TurnLeft() {
	std::cout << "Turning left" << std::endl;
}
void BaseCar::TurnRight() {
	std::cout << "Turning right" << std::endl;
}

//SwitchGear function
void BaseCar::SwitchGear(int gear)
{
	if (gear > 0 && gear <= 5 && std::abs(GetCurrentSpeed()) >= 0) { //Check if the gear is valid
		gears->SwitchGear(gear);
	}
	else if (gear == 0 && GetCurrentSpeed() <= 0) { //Check if its reverse gear
		gears->SwitchGear(0);
	}
	else {
		//"Invalid gear or speed is negative."
	}

}

