#include "StackPlate.h"
#include <iostream>
#include <cassert>


void main()
{
	StackPlate<int, 2> plate;

	for (int i = 0; i < 100; ++i)
	{
		plate.push(i);	
	}

	assert(plate.numOfStack() == 50);
	assert(plate.pop() == 99);
	assert(plate.numOfStack() == 50);
	assert(plate.pop() == 98);
	assert(plate.numOfStack() == 49);

	assert(plate.pop() == 97);
	assert(plate.numOfStack() == 49);

	assert(plate.popAt(0) == 1);
	assert(plate.numOfStack() == 49);


	std::cout << "Test" << std::endl;



}