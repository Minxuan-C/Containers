/* 
main file to test stack class
*/
#include <iostream> 
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"
using namespace std;

int main() {
	/*test basic functionalities*/
	Stack<int,3> intstk; //initialize an int stack of size 3 - parameterized constructor
	intstk.Push(5); //push some values
	intstk.Push(10);
	intstk.Push(14);
	Stack<int,3> intstk2 = intstk; //copy constructor
	cout << "last item stack 1: " << intstk.Pop() << endl; //pop and print some values
	cout << "second last item stack 1: " << intstk.Pop() << endl;
	cout << "fist item stack 1: " << intstk.Pop() << endl;

	cout << "last item stack 2: " << intstk2.Pop() << endl; //test copy constructor
	Stack<int,3> intstk3; //initialize another int stack
	intstk3.Push(1); //push some values
	intstk3.Push(2);
	intstk3.Push(3);
	intstk2 = intstk3; //assignment operator
	cout << "last item new stack 2: " << intstk2.Pop() << endl; //test assignment operator


	/*test exception handling of new template*/
	Stack<int,1> intstk4; //initialize an int stack of size 1 - parameterized constructor; now the stack is empty

	try {
		cout << "first pop: " << intstk4.Pop() << endl;
	}
	catch (StackException& ex) { //polymorphism by setting the type to be base class reference
		cout << ex.GetMessage();
	}

	intstk4.Push(123);//now the stack is full

	try {
		intstk4.Push(456);
	}
	catch (StackException& ex) { //polymorphism by setting the type to be base class reference
		cout << ex.GetMessage();
	}

	return 0;
}