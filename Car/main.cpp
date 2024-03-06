#include <iostream>
#include <thread>
#include <atomic>
#include <windows.h>
#include <memory>
#include <chrono>
#include "MonsterTruck.h"
#include "BaseCar.h"
#include "RaceCar.h"
#include "FamilyCar.h"

enum GameState {
	STARTING,
	RUNNING,
	PAUSED,
	STOPPED
};

using namespace std::chrono;
std::atomic<bool> running(true);
std::atomic<bool> shouldAccelerate(false);
std::atomic<bool> shouldDecelerate(false);
std::atomic<int> gear(2);
GameState gameState = GameState::STARTING;
std::string currentStatus = "Starting...               ";

// Check if a key is pressed
void CheckKeyPress() {

	while (running) {
		//Windows API function to check if a key is pressed
		if (GetAsyncKeyState('A') & 0x8000) {
			shouldAccelerate = true;
			shouldDecelerate = false;
			currentStatus = "Accelerating...          ";
		}
		else if (GetAsyncKeyState('S') & 0x8000) {
			shouldAccelerate = false;
			shouldDecelerate = false;
			currentStatus = "Idle...               ";
		}
		else if (GetAsyncKeyState('B') & 0x8000) {
			shouldDecelerate = true;
			shouldAccelerate = false;
			currentStatus = "Braking...               ";
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { //exit the game
			running = false;
		}
		else {

			for (char key = '0'; key <= '5'; ++key) {
				if (GetAsyncKeyState(key) & 0x8000) {
					gear = key - '0' + 1; //Das fühlt sich so illegal an
					currentStatus = "Gear " + std::to_string(gear - 1) + "...";
					break; // Exit the loop once a gear change is detected
				}
			}
		}
		std::this_thread::sleep_for(milliseconds(100));
	}
}
//Wähle deinen Schlitten
BaseCar* selectCar() {
	std::cout << "Welcome to the Car Simulator" << std::endl;
	std::cout << "Please select a car" << std::endl;
	std::cout << "1. Monster Truck" << std::endl;
	std::cout << "2. Race Car" << std::endl;
	std::cout << "3. Family Car" << std::endl;
	int c;
	std::cin >> c;
	BaseCar* car;
	switch (c) {
	case 1: // Monster Truck, Alter!
		car = new MonsterTruck("Monster Truck", "Red");
		break;
	case 2:
		car = new RaceCar("Race Car", "Blue", 1.5f);
		break;
	case 3:
		car = new FamilyCar("Family Car", "Green");
		break;
	default:
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	return car;
}
//Update the car status based on the input
void updateCarStatus(BaseCar* car, float deltaTime) {
	car->SwitchGear(gear); // Change the gear to the selected gear
	if (shouldAccelerate && !shouldDecelerate) {
		car->Accelerate(deltaTime); // Accelerate the car if the accelerate key is pressed
	}
	else if (!shouldAccelerate && shouldDecelerate) {
		car->Decelerate(deltaTime); // Decelerate the car if the brake key is pressed
	}
}

void printStatus(BaseCar* car) {
	// Print the current status of the car to the console
	std::string statusAndSpeed = currentStatus;
	statusAndSpeed += "Current Speed: " + std::to_string(car->GetCurrentSpeed()) + " km/h" + std::string(10, ' ');
	std::cout << "\r" << statusAndSpeed << std::flush; //Print and flush the output buffer
}
BaseCar* SetupCar() {
	BaseCar* car = selectCar(); //wähle deinen Schlitten
	car->StartMotor(); //Starte den Motor
	system("cls"); //Clear the console
	std::cout << "Press A to accelerate, S to Idle, B to brake, 0-5 to change gear, ESC to exit" << std::endl;
	std::cout << "Note: Gear 0 is reverse. you cannot change into reverse while moving forward" << std::endl;
	return car;

}
int main() {
	auto lastTime = high_resolution_clock::now();
	BaseCar* car = SetupCar(); // Select the car
	gameState = GameState::RUNNING;
	std::thread inputThread(CheckKeyPress); // Start the input thread to check for key presses

	while (running) {
		auto currentTime = high_resolution_clock::now(); // Get the current time
		auto deltaTime = duration_cast<duration<float>>(currentTime - lastTime).count(); // Calculate the time difference
		lastTime = currentTime; // Update the last time

		updateCarStatus(car, deltaTime);
		printStatus(car);

		// Sleep for a short duration to avoid 100% CPU usage
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	inputThread.join(); // Wait for the input thread to finish
	delete car;// Free the memory allocated for the car
	return 0;
}
