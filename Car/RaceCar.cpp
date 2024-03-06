#include "RaceCar.h"
RaceCar::RaceCar(std::string name, std::string color, float tuningRate) {
	engine = std::make_shared<V8Engine>(V8Engine("V8 Motor Bugatti", 650.0f*tuningRate, 2.0f));
	frame = std::make_shared<Frame>(Frame(color, 600 / tuningRate));
	tires = std::make_shared<Tires>(Tires("Continental SportContact 7", 2000, 4));
	gears = std::make_shared<Gears>(Gears());
	suspension = std::make_shared<Suspension>(Suspension());
	brakes = std::make_shared<Brakes>(Brakes("Bosch", 300000));
	baseMass = 765.0f;
	maxSpeed = 400.0f*tuningRate;
	this->name = name;
	currentSpeed = 0.0f;
}
RaceCar::RaceCar(std::string name, std::string color) {
		engine = std::make_shared<V8Engine>(V8Engine("V8 Motor Bugatti", 650.0f, 2.0f));
	frame = std::make_shared<Frame>(Frame(color, 600 / 1));
	tires = std::make_shared<Tires>(Tires("Continental SportContact 7", 2000, 4));
	gears = std::make_shared<Gears>(Gears());
	suspension = std::make_shared<Suspension>(Suspension());
	brakes = std::make_shared<Brakes>(Brakes("Bosch", 300000));
	baseMass = 765.0f;
	maxSpeed = 400.0f;
	this->name = name;
	currentSpeed = 0.0f;
}