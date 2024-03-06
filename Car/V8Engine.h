#pragma once
#include "Engine.h"
namespace Car {
	class V8Engine : public Engine
	{
	public:
		V8Engine(std::string _producer, float _horsePower,float _acceleration) : Engine(_producer, _horsePower,_acceleration) {}
		void virtual StartMotor() override;
		void virtual StopMotor() override;
	};
}
