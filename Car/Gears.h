#pragma once
#include <vector>

namespace Car {
	class Gears
	{
	private:
		int currentGear;
		std::vector<float> gearRatios; // Ratios for each gear
	public:
		Gears();
		~Gears();
		void SwitchGear(int gear); // Switch to a specific gear
		int GetCurrentGear(); // Get the current gear number
		float GetGearRatio(); // Get the ratio for the current gear
	};
}