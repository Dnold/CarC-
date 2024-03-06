#include "FamilyCar.h"
#include "InlineFourEngine.h"

FamilyCar::FamilyCar(std::string name, std::string color, float tuningRate)
{
	engine = std::make_shared<InlineFourEngine>(InlineFourEngine("Inline Four Motor", 1000.0f * tuningRate, 3.0f));
	frame = std::make_shared<Frame>(Frame(name, 600 / tuningRate));
	tires = std::make_shared<Tires>(Tires("Continental", 600, 12));
	gears = std::make_shared<Gears>(Gears());
	suspension = std::make_shared<Suspension>(Suspension());
	brakes = std::make_shared<Brakes>(Brakes("Bosch", 300 * tuningRate));
	this->name = name;
	baseMass = 5000.0f / tuningRate;
	currentSpeed = 0.0f;
	this->maxSpeed = 100.0f * tuningRate;
}
FamilyCar::FamilyCar(std::string name, std::string color)
{
	engine = std::make_shared<InlineFourEngine>(InlineFourEngine("Inline Four Motor", 90.0f, 3.0f));
	frame = std::make_shared<Frame>(Frame(name, 600));
	tires = std::make_shared<Tires>(Tires("Continental", 600, 12));
	gears = std::make_shared<Gears>(Gears());
	suspension = std::make_shared<Suspension>(Suspension());
	brakes = std::make_shared<Brakes>(Brakes("Bosch", 23000));
	this->name = name;
	baseMass = 1500.0f;
	currentSpeed = 0.0f;
	this->maxSpeed = 100.0f;
}