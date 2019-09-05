#pragma once

#include "Car.h"
using namespace std;

class SportsCar : public Car
{
public:
	bool bTurbo;
	SportsCar() {}
	SportsCar(int s, char* n, int g);
	void setTurbo(bool bTur);
	void speedUp();
};

SportsCar::SportsCar(int s, char* n, int g) : Car(s, n, g) {}
void SportsCar::setTurbo(bool bTur) { bTurbo = bTur; }

void SportsCar::speedUp() {
	if (bTurbo) speed += 20;
	else Car::speedUp();
}