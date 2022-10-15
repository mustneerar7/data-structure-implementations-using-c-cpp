#include <iostream>
#include "stack.h"

using namespace std;

int main(){

	// initializing stack object
	StackClass<int> stack(2);

	// pushes values to stack
	stack.push(10);
	stack.push(5);

	// pops values from stack
	cout << stack.pop();

	return 0;
}