#pragma once

#include <cstdio>
#include <iostream>
#define MAX_DEGREE	80

using namespace std;

class Polynomial {
	int	degree;					// 다항식의 최고 차수
	float	coef[MAX_DEGREE];	// 각 항에 대한 계수
public:
	Polynomial();

	int getDegree()const;

	float getCoef(int cn)const;

	void setCoef(int cn, float c);

	void read();

	void display();

	void add(Polynomial a, Polynomial b);

	bool isZero();

	void negate();

	friend ostream& operator<<(ostream& os, const Polynomial& pn);


};
 
 ostream& operator<<(ostream& os, const Polynomial& pn){
	 os << endl; // os is just like cout.
	 for (int i = 0; i < pn.degree; i++) {
		 os << pn.getCoef(i) << "X^" << i << "+";
	 }
	 return os;
 }

Polynomial::Polynomial() {
	degree = 0;
}
int Polynomial::getDegree() const { return degree; }

float Polynomial::getCoef(int cn)const { return coef[cn]; }

void Polynomial::setCoef(int cn, float c){ coef[cn] = c; }

void Polynomial::read() {
	cout << ("write down the highest power on polynomial : ");
	cin >> degree;
	cout << "put the numbers on each pow (total " << degree + 1 << "): ";
	for (int i = 0; i <= degree; i++)
		scanf("%f", coef + i);
}


void Polynomial::display() {
	for (int i = 0; i < degree; i++)
		cout << coef[i] << "x^" << (degree - i) << "+ ";
	cout << coef[degree] << endl;
}

void Polynomial::add(Polynomial a, Polynomial b) {
	if (a.degree > b.degree) {
		*this = a;
		for (int i = 0; i <= b.degree; i++)
			coef[i + (degree - b.degree)] += b.coef[i];
	}
	else {
		*this = b;
		for (int i = 0; i <= a.degree; i++)
			coef[i + (degree - a.degree)] += a.coef[i];
	}
}

bool Polynomial::isZero() { return degree == 0; }

void Polynomial::negate() {
	for (int i = 0; i<degree; i++)
		coef[i] = -coef[i];
}

