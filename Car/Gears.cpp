#include "Gears.h"


//Todo: Implement the methods for switching gears and getting the current gear number (1-6)
//Gears are used to change the speed of the car. The gears are numbered 1-6, with 1 being the lowest gear and 6 being the highest gear.
//A specific percentage of the engine's power is transferred to the wheels, depending on the gear.
#
#include "Gears.h"

Car::Gears::Gears() : currentGear(1), gearRatios({ -0.5,0.8, 1.4, 2.2, 3.0, 3.8, 4.6 })
{

	// Initialize with default gear ratios
}

Car::Gears::~Gears()
{
	// Nothing to clean up
}

void Car::Gears::SwitchGear(int gear)
{
	if (gear == -1) {
		currentGear = 0;
		return;
	}
	else {
		if (gear >= 1 && gear <= 6) {
			currentGear = gear;
		}
	}
}

int Car::Gears::GetCurrentGear()
{
	return currentGear;
}

float Car::Gears::GetGearRatio()
{
	return gearRatios[currentGear - 1];
}
