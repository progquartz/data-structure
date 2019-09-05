#pragma once

using namespace std;

class Car {
protected:
	int 	speed; 			// �ӵ� (private)
	char	name[40]; 		// �̸� (private)
public:
	int 	gear; 			// ��� (public)
	Car() { }
	~Car() { }
	Car(int s, char* n, int g);
	void changeGear(int g);
	void speedUp();
	void display();
	void whereAmI();
};

Car::Car(int s, char* n, int g)
	: speed(s), gear(g) {
	strcpy(name, n);
}

void Car::changeGear(int g = 4) {
	gear = g;
}

void Car::speedUp() {
	speed += 5;
}

void Car::display() {
	cout << "[" << name << "] : gear = " << gear << "speed = " << speed << "kmph" << endl;
}

void Car::whereAmI() {
	cout << "object address = " << this << endl;
}

