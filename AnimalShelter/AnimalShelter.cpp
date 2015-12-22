#include "AnimalShelter.h"



void Shelter::enqueue(Animal* p)
{
	m_animalQueue.push_back(p);
}


Animal* Shelter::dequeueAny()
{
	if (m_animalQueue.empty()) 
		return nullptr;
	Animal* p = m_animalQueue.front();
	m_animalQueue.pop_front();
	return p;
}






