#pragma once
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class DoubleArrayStack {// Stack Data Structure made for array of double.
private:
	int top;
	double data[MAX_STACK_SIZE];
public:
	DoubleArrayStack();
	bool isEmpty() const;// if it is empty, it returms 1 else, it returns 0.
	bool isFull() const;// if it is full, it returns 1, else, it returns 0;
	void push(const double& e);// pushes the data into the data structure. the data got into it pops first.
	double pop();// pops the data info which pushed lastly.
	double peek();// peek out the data in the data structure/
	int size() const;// returns the size of data structure.
	friend ostream& operator<<(ostream& os, const DoubleArrayStack& ias);
};

ostream& operator<<(ostream& os, const DoubleArrayStack& ias) {
	os << endl;
	for (int i = 0; i <= ias.top; i++)
		os << " <" << ias.data[i] << "> ";
	os << endl;
	return os;
}

DoubleArrayStack::DoubleArrayStack() { top = -1; }
bool DoubleArrayStack::isEmpty() const { return top == -1; }
bool DoubleArrayStack::isFull() const { return top == MAX_STACK_SIZE - 1; };
void DoubleArrayStack::push(const double& e) {
	if (isFull()) {
		cerr << "Stack is Full...";
		exit(1);
	}
	data[++top] = e;
}
double DoubleArrayStack::pop() {
	if (isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top--];
}
double DoubleArrayStack::peek() {
	if (isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top];
}
int DoubleArrayStack::size() const {
	return top + 1;
}
