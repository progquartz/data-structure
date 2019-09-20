#pragma once
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class DoubleArrayStack {
private:
	int top;
	double data[MAX_STACK_SIZE];
public:
	DoubleArrayStack();
	bool isEmpty() const;
	bool isFull() const;
	void push(const double& e);
	double pop();
	double peek();
	int size() const;
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
