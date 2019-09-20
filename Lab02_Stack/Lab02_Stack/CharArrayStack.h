#pragma once
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class CharArrayStack { // making char array stack.
private:
	int top; // private 
	char data[MAX_STACK_SIZE];
public:
	CharArrayStack();
	bool isEmpty() const;
	bool isFull() const;
	void push(const char& e);
	char pop();
	char peek();
	int size() const;
	friend ostream& operator<<(ostream& os, const CharArrayStack& ias);
};

ostream& operator<<(ostream& os, const CharArrayStack& ias) {
	os << endl;
	for (int i = 0; i <= ias.top; i++)
		os << " <" << ias.data[i] << "> ";
	os << endl;
	return os;
}

CharArrayStack::CharArrayStack() { top = -1; }
bool CharArrayStack::isEmpty() const { return top == -1; }
bool CharArrayStack::isFull() const { return top == MAX_STACK_SIZE - 1; };
void CharArrayStack::push(const char& e) {
	if (isFull()) {
		cerr << "Stack is Full...";
		exit(1);
	}
	data[++top] = e;
}
char CharArrayStack::pop() {
	if (isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top--];
}
char CharArrayStack::peek() {
	if (isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top];
}
int CharArrayStack::size() const {
	return top + 1;
}