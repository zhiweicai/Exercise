#include "stackmin.h"
#include <iostream>
#include <cassert>


const  int testConst = 100;
void main()
{
	stackmin<int> testStack;

	for (int i = 0; i < testConst; ++i)
		testStack.push(i);

	assert (testStack.getMin() == 0);

	for (int i = testConst-1; i >=0; --i)
		assert (testStack.pop() == i);
	
	for (int i = 0; i < testConst; ++i)
		testStack.push(testConst - i);

	for (int i = 1; i < testConst; ++i)
	{
		assert(testStack.getMin() == i);
		assert(testStack.pop() == i);
	}

	std::cout << "End" << std::endl; 

}