#include "CharArrayStack.h"
#include "intArrayStack.h"
#include "StackApplications.h"
#include "Student.h"
#include "StudentArrayStack.h"

void testStudentArrayStack() {
	StudentArrayStack ss;
	cout << "# of elemetns in the Stack" << ss.size() << ": " << ss;
	ss.push(Student());
	ss.push(Student(1, "a", "A"));
	ss.push(Student(2, "b", "B"));
	ss.push(Student(3, "c", "C"));
	cout << "# of elemetns in the Stack" << ss.size() << ": " << ss;
}

void testIntArrayStack() {
	IntArrayStack s;
	cout << "# of elemetns in the Stack" << s.size() << ": " << s;
	for (int i = 10; i<25; i++)
		s.push(i);
	cout << "# of elemetns in the Stack" << s.size() << ": " << s;
	cout << s.pop();
	cout << "# of elemetns in the Stack" << s.size() << ": " << s;
	cout << s.peek();
	cout << "# of elemetns in the Stack" << s.size() << ": " << s;
}

void main() {
	StackApplications sa;

	if (sa.checkMatching("{{{a(nnn)}}"))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;

	double a = sa.calcPostfixExpr("345++");
	cout << a;


	sa.infix2Postfix("(3+5)*6");
	
	string s = "2 + 3 * 5";

	cout << sa.calcInfixExpr(s);

}