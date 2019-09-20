#pragma once

#include <iostream>

#define MAX_STACK_SIZE 100

using namespace std;

class intArrayClass {
private:
	int top;
	int m_size;
	int m_top;
	int *m_buffer;
	int data[MAX_STACK_SIZE];

public:
	intArrayClass();
	~intArrayClass();
	bool isEmpty();
	bool isFull();
	void Initialize(int size = 10);
	void RemoveAll();
	void Push(int val);
	int Pop();

};

intArrayClass::intArrayClass() {//스택 생성
	m_top = -1;
}

void intArrayClass::RemoveAll() {//스택 초기화, 삭제
	m_size = 0;
	m_top = -1;
	delete[] m_buffer;
	m_buffer = NULL;
}

void intArrayClass::Push(int val) {
	if (m_top >= n - 1) {
		cout << "Stack Overflow" << endl;
	}
	else {
		m_top++;
		data[m_top] = val;
	}
}
int intArrayClass::Pop() {
	if (m_top <= -1) {
		cout << "Stack Underflow" << endl;
		return 0;
	}
	else {
		cout << "The popped element is " << data[m_top] << endl;
		return data[m_top--];
	}
}