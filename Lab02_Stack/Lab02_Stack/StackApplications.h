#pragma once
#include <String>
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include "IntArrayStack.h"
#include "CharArrayStack.h"
#include "DoubleArrayStack.h"

// 대충 타입어레이 클래스 추가할거임.
using namespace std;

class StackApplications {
private:
public:
	void baseConversion(int num);
	bool checkMatching(string expr);
	double calcPostfixExpr(string expr);
	int precedence(char op);
	void infix2Postfix(string expr);
	double calcInfixExpr(string expr);
	bool isChar(string s);
	int solve(int op1, int op2, char ch);
};

bool StackApplications::checkMatching(string expr) {
	CharArrayStack s;
	char c1, c;
	for (int i = 0; i < expr.length(); i++) {
		c1 = expr[i];
		if (c1 == '(' || c1 == '{' || c1 == '[') {
			s.push(c1);
			continue;
		}

		switch (c1) {
		case ')':
			c = s.pop();
			if (c == '{' || c == '[') { return false;}
			break;
		case '}':
			c = s.pop();
			if (c == '(' || c == '[') { return false; }
			break;
		case ']':
			c = s.pop();
			if (c == '{' || c == '(') { return false;}
			break;
		}
	}
	return s.isEmpty();
}

void StackApplications::baseConversion(int num) {
	IntArrayStack s;
	int r;
	while (num != 0) {
		r = num % 2;
		s.push(r);
		num /= 2;
	}

	cout << "Base-2 Conversion --->";

	while (!s.isEmpty()) {
		cout << s.pop();
	}
}

double StackApplications::calcPostfixExpr(string expr) {
	DoubleArrayStack s;
	char c;
	double val = 0.0;
	double val2, val1;
	for (int i = 0; i < expr.length(); i++) {
		c = expr[i];
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			val2 = s.pop();
			val1 = s.pop();
			switch (c) {
			case '+':
				s.push(val1 + val2);
				break;
			case '-':
				s.push(val1 - val2);
				break;
			case '*':
				s.push(val1 * val2);
				break;
			case '/':
				s.push(val1 / val2);
				break;
			}

		}
		else if(c >= '0' && c <= '9'){
			val = (double)c - 48;
			s.push(val);
		}
	}
	return s.pop();
}

int StackApplications::precedence(char op) {
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '/': case '*': return 2;
	}
}

void StackApplications::infix2Postfix(string expr) {
	CharArrayStack s;
	char op, c;
	int val = 0;

	for (int i = 0; i < expr.length(); i++) {
		c = expr[i];
		if (c >= '0' && c <= '9') { 
			val = (int)(c - 48);
			cout << val;
		}
		else if(c == '('){
			s.push(c);
		}
		else if (c == ')') {
			while (!s.isEmpty()) {
				op = s.pop();
				if (op== '(') {
					break;
				}
				else {
					cout << op;
				}
			}
			
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!s.isEmpty()) {
				op = s.peek();
				if (precedence(c) <= precedence(op)) {
					cout << op;
					s.pop();
				}
				else{
					break;
				}
			}
			s.push(c);
		}
	}
	while (!s.isEmpty()) {
		cout << s.pop();
	}
	cout << endl;
}

double StackApplications::calcInfixExpr(string expr)
{
	CharArrayStack operators;
	IntArrayStack operands;

	string s;
	stringstream is	( expr );
	while (is >> s)
	{
		if (isChar(s))
		{
			if (s[0] == '(') operators.push('(');
			else if (s[0] == ')')
			{
				while (operators.peek() != '(')
				{
					char ch = operators.peek(); operators.pop();
					int op2 = operands.peek(); operands.pop();
					int op1 = operands.peek(); operands.pop();

					operands.push(solve(op1, op2, ch));
				}
				operators.pop();
			}
			else
			{
				while (!operators.isEmpty() && precedence(s[0]) <= precedence(operators.peek()))
				{
					char ch = operators.peek(); operators.pop();
					int op2 = operands.peek(); operands.pop();
					int op1 = operands.peek(); operands.pop();

					operands.push(solve(op1, op2, ch));

				}

				operators.push(s[0]);
			}

		}
		else
		{
			int op = atoi(s.c_str());
			operands.push(op);
		}

	}

	while (!operators.isEmpty())
	{
		char ch = operators.peek(); operators.pop();
		int op2 = operands.peek(); operands.pop();
		int op1 = operands.peek(); operands.pop();

		operands.push(solve(op1, op2, ch));
	}

	//cout<<operands.empty()<<" "<<operators.empty();
	return operands.peek();
	cout << "result: " << operands.peek() << endl;
}

bool StackApplications::isChar(string s) // function returns whether the middle char is an operator.
{
	if (s.size() >1) return false;

	switch (s[0]) {
	case '+': return true;
	case '-': return true;
	case '*': return true;
	case '/': return true;
	case '(': return true;
	case ')': return true;
	default: return false;
	}
}

int StackApplications::solve(int op1, int op2, char ch) // returns the value right int order.
{
	switch (ch)
	{
	case '+': return (op1 + op2);
	case '-': return (op1 - op2);
	case '*': return (op1*op2);
	case '/': return (op1 / op2);
	case '^': return pow(op1, op2);

	}
}