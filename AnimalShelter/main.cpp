#include "AnimalShelter.h"
#include <iostream>


void main()
{
	Shelter<Animal> TheShelter;

	Dog one;
	Dog a;
	Cat b;
	Dog c;
	Dog d;

	TheShelter.enqueue(&one);
	TheShelter.enqueue(&a);
	TheShelter.enqueue(&b);
	TheShelter.enqueue(&c);
	TheShelter.enqueue(&d);

	Cat* p = TheShelter.dequeue<Cat>();

	if (p == &b)
	{
		std::cout << "Great!" << std::endl;
	}
	else
	{
		std::cout << "OOPS!" << std::endl;
	}

	Dog* pDog = TheShelter.dequeue<Dog>();
	if (pDog == &one)
	{
		std::cout << "Great!" << std::endl;
	}


	std::cout << "End!" << std::endl;

}