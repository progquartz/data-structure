#pragma once
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class IntArrayStack{// Stack Data Structure made for array of int
private:
	int top;
	int data[MAX_STACK_SIZE];
public:
	IntArrayStack();
	bool isEmpty() const;		// if it is empty, it returms 1 else, it returns 0.
	bool isFull() const;		// if it is full, it returns 1, else, it returns 0;
	void push(const int& e);// pushes the data into the data structure. the data got into it pops first.
	int pop();// pops the data info which pushed lastly.
	int peek();// peek out the data in the data structure/
	int size() const;// returns the size of data structure.
	friend ostream& operator<<(ostream& os, const IntArrayStack& ias);
};

ostream& operator<<(ostream& os, const IntArrayStack& ias) {
	os << endl;
	for(int i=0;i<=ias.top; i++)
		os << " <" << ias.data[i] << "> ";
	os << endl;
	return os;
}

IntArrayStack::IntArrayStack() {top=-1;}
bool IntArrayStack::isEmpty() const {return top==-1;}
bool IntArrayStack::isFull() const {return top==MAX_STACK_SIZE-1;};
void IntArrayStack::push(const int& e) {
	if(isFull()) {
		cerr << "Stack is Full...";
		exit(1);
	}
	data[++top]=e;
}
int IntArrayStack::pop() {
	if(isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top--];
}
int IntArrayStack::peek() {
	if(isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top];
}
int IntArrayStack::size() const {
	return top + 1;
}