#pragma once
#include <string>
namespace Car
{
	class Brakes
	{
	protected:
		std::string producer;
		float breakForce;
		
	public:
		Brakes(std::string producer, float breakForce);
		void virtual GoSCREEECH(float& currentVelocity, float breakVelocity);
		float GetBreakForce();
		void SetBreakForce(float breakForce);
	};
}


