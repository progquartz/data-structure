#include "IntArrayStack.h"
#include "CharArrayStack.h"
#include "DoubleArrayStack.h"
#include "StudentArrayStack.h"

int main() {
	testIntArrayStack();

}
void testIntArrayStack() {
	IntArrayStack s;
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	for (int i = 10; i < 25; i++) {
		s.push(i);
	}
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	cout << s.pop();
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	s.push(2);
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	cout << "if the s is empty, it will display 1 (" << s.isEmpty() << ")" << endl;
	cout << "if s is full, it will dislplay 1 (" << s.isFull() << ")" << endl;
}

void testStudentArrayStack() {
	StudentArrayStack s;
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	for (int i = 10; i < 25; i++) {
		s.push(Student());
	}
	s.push(Student(123, "abc", "def"));
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	cout << s.pop();
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	s.push(Student(123123, "asdfsdf" , "asdasd"));
	cout << "# of elements in the Stack" << s.size() << ":" << s;
	cout << "if the s is empty, it will display 1 (" << s.isEmpty() << ")" << endl;
	cout << "if s is full, it will dislplay 1 (" << s.isFull() << ")" << endl;
}