#include "MonsterTruck.h"
#include "V8Engine.h"

// Constructor for MonsterTruck with tuningRate
MonsterTruck::MonsterTruck(std::string name, std::string color, float tuningRate)
{
	engine =std::make_shared<V8Engine>(V8Engine("V8 Motor", 1000.0f*tuningRate,3.0f));
	frame = std::make_shared<Frame>(Frame(name,600/tuningRate));
	tires = std::make_shared<Tires>(Tires("Terra Five",2000,4));
	gears = std::make_shared<Gears>(Gears());
	suspension = std::make_shared<Suspension>(Suspension());
	brakes = std::make_shared<Brakes>(Brakes("Bosch",300*tuningRate));
	this->name = name;
	baseMass = 5000.0f/tuningRate;
	currentSpeed = 0.0f;
	this->maxSpeed = 100.0f*tuningRate;


}
// Constructor for MonsterTruck without tuningRate
MonsterTruck::MonsterTruck(std::string name, std::string color)
{
	engine = std::make_shared<V8Engine>(V8Engine("V8 Motor", 1000.0f,0.8f));
	frame = std::make_shared<Frame>(Frame("Blauer Hintergrund mit USA Flagge und Flammen", 600 / 4));
	tires = std::make_shared<Tires>(Tires("Terra Five", 2000, 4));
	gears = std::make_shared<Gears>(Gears());
	suspension = std::make_shared<Suspension>(Suspension());
	brakes = std::make_shared<Brakes>(Brakes("Bosch", 300000));
	baseMass = 5000.0f;
	maxSpeed = 180.0f;
	this->name = name;
	currentSpeed = 0.0f;


}