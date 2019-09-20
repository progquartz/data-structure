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
	bool isEmpty() const;// if it is empty, it returms 1 else, it returns 0.
	bool isFull() const;// if it is full, it returns 1, else, it returns 0;
	void push(const char& e);// pushes the data into the data structure. the data got into it pops first.
	char pop();// pops the data info which pushed lastly.
	char peek();// peek out the data in the data structure/
	int size() const;// returns the size of data structure.
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