#pragma once
#include <iostream>
#include <String>

using namespace std;

class Student {
private:
	int id;
	string name;
	string dept;
public:
	Student(int i, string name, string dept);
	Student();
	friend ostream& operator<<(ostream& os, const Student s);
};

ostream& operator<<(ostream& os, const Student s) {
	cout << s.id << " " << s.name << " " << s.dept;
}

Student::Student() {
	id = 0;
	this->name = "default name";
	this->dept = "default dept";
}

Student::Student(int i, string name, string dept) {
	id = i;
	this->name = name;
	this->dept = dept;
}



