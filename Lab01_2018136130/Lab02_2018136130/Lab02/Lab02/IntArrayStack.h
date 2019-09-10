#pragma once
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class IntArrayStack{
private:
	int top;
	int data[MAX_STACK_SIZE];
public:
	// 
	IntArrayStack();
	bool isEmpty() const;
	bool isFull() const;

	void push(int e);
	int pop();
	int peek();
	int size()const;
	friend ostream& operator<<(ostream& os, const IntArrayStack& ias);
};

ostream& operator<<(ostream& os, const IntArrayStack& ias) {
	os << endl;
	for (int i = 0; i < ias.top + 1; i++) {
		cout << " <" << ias.data[i] << "> "; 
	}
	os << endl;
	return os;
}

IntArrayStack::IntArrayStack() { top = -1; }

bool IntArrayStack::isEmpty()const {
	return top == -1;
}

bool IntArrayStack::isFull()const {
	return top == MAX_STACK_SIZE - 1;
}

void IntArrayStack::push(int e) {
	if (isFull()) {
		cout << "Stack is Full..";
		exit(1);
	}
	data[++top] = e;
}

int IntArrayStack::pop() {
	if (isEmpty()) {
		cout << "Stack is Empth ...";
		exit(1);
	}
	return data[top--];
}

int IntArrayStack::peek() {
	if (isEmpty()) {
		cout << "Stack is empty";
		exit(1);
	}
	return data[top];
}

int IntArrayStack::size()const {
	return top + 1;
}
