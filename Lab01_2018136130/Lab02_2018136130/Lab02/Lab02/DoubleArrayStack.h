#pragma once
#pragma once
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class DoubleArrayStack {
private:
	int top;
	double data[MAX_STACK_SIZE];
public:
	// 
	DoubleArrayStack();
	bool isEmpty() const;
	bool isFull() const;

	void push(double e);
	double pop();
	double peek();
	int size()const;
	friend ostream& operator<<(ostream& os, const DoubleArrayStack& ias);
};

ostream& operator<<(ostream& os, const DoubleArrayStack& ias) {
	os << endl;
	for (int i = 0; i < ias.top + 1; i++) {
		cout << " <" << ias.data[i] << "> ";
	}
	os << endl;
	return os;
}

DoubleArrayStack::DoubleArrayStack() { top = -1; }

bool DoubleArrayStack::isEmpty()const {
	return top == -1;
}

bool DoubleArrayStack::isFull()const {
	return top == MAX_STACK_SIZE - 1;
}

void DoubleArrayStack::push(double e) {
	if (isFull()) {
		cout << "Stack is Full..";
		exit(1);
	}
	data[++top] = e;
}

double DoubleArrayStack::pop() {
	if (isEmpty()) {
		cout << "Stack is Empth ...";
		exit(1);
	}
	return data[top--];
}

double DoubleArrayStack::peek() {
	if (isEmpty()) {
		cout << "Stack is empty";
		exit(1);
	}
	return data[top];
}

int DoubleArrayStack::size()const {
	return top + 1;
}
