#pragma once

#include <cstdio>
#include <iostream>
#include "ArrayExample.h"
#include "Car.h"
#include "Polynomial.h"
#include "Sportcar.h"

using namespace std;
// ÁÖ ÇÔ¼ö

void testTask01() {
	ArrayExamples ae1;
	int a[] = { 1,2,3,4,5,6,7,8 };
	int maxv = ae1.findMaxValue(a, 8); // finded the maxvalue of 1 dimensional array and put it in maxv
	cout << maxv << endl;

	int b[][5] = { { 1,2,3,4,5 },{ 6,7,8,9,10 } };
	int maxp = ae1.findMaxPixel(b, 2, 5); // finded the maxpixel on 2 dimensional array and put it in maxp
	cout << maxp << endl;
}

void testPolynomial() {
	Polynomial a;
	a.read();
	a.display();
	a.display();
}

void testCar() {
	Car			yourCar(80, "your car", 4);
	SportsCar	myCar(100, "MY car", 4);

	yourCar.display();
	myCar.display();

	yourCar.speedUp();
	myCar.speedUp();
	yourCar.display();
	myCar.display();

	myCar.bTurbo = 1;
	myCar.speedUp();
	myCar.display();
}

void main()
{
	testTask01();
	testPolynomial();
	testCar();
	system("pause");
}

