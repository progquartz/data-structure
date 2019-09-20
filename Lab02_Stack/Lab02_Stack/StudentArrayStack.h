#pragma once
#include "Student.h"
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class StudentArrayStack{
private:
	int top;
	Student data[MAX_STACK_SIZE];
public:
	StudentArrayStack();
	bool isEmpty() const;
	bool isFull() const;
	void push(const Student& e);
	Student pop();
	Student peek();
	int size() const;
	friend ostream& operator<<(ostream& os, const StudentArrayStack& ias);
};

ostream& operator<<(ostream& os, const StudentArrayStack& ias) {
	os << endl;
	for(int i=0;i<=ias.top; i++)
		os << " <" << ias.data[i] << "> " << endl;
	return os;
}

StudentArrayStack::StudentArrayStack() {top=-1;}
bool StudentArrayStack::isEmpty() const {return top==-1;}
bool StudentArrayStack::isFull() const {return top==MAX_STACK_SIZE-1;};
void StudentArrayStack::push(const Student& e) {
	if(isFull()) {
		cerr << "Stack is Full...";
		exit(1);
	}
	data[++top]=e;
}
Student StudentArrayStack::pop() {
	if(isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top--];
}
Student StudentArrayStack::peek() {
	if(isEmpty()) {
		cerr << "Stack is Empty...";
		exit(1);
	}
	return data[top];
}
int StudentArrayStack::size() const {
	return top + 1;
}