#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	int id;
	string name;
	string dept;
public:
	Student(int sid=0, string sname="", string sdept="");
	friend ostream& operator<<(ostream& os, const Student& s);
};
ostream& operator<<(ostream& os, const Student& s) {
	os << "ID: " << s.id << " name: " << s.name << " Department: " << s.dept;
	return os;
}

Student::Student(int sid, string sname, string sdept):id(sid), name(sname), dept(sdept) {}