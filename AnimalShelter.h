#include <deque>
#include <vector>


class Animal 
{
public:
	virtual void hello() {};
};

class Dog : public Animal {};

class Cat : public Animal {};


template <class U>
class  Shelter
{
private:
	std::deque<U*> m_animalQueue;

public:
	void enqueue(U* p)
	{
		m_animalQueue.push_back(p);
	}
	U* dequeueAny()
	{
		if (m_animalQueue.empty())
			return nullptr;
		U* p = m_animalQueue.front();
		m_animalQueue.pop_front();
		return p;
	}

	template <class T>  T* dequeue()
	{
		std::vector<U*>  vTmp;
		T* pFound = nullptr;
		while (!m_animalQueue.empty())
		{
			Animal* pAnimal = dequeueAny();
			if (dynamic_cast<T*> (pAnimal) != nullptr)
			{
				pFound = static_cast<T*> (pAnimal);
				break;
			}
			else
				vTmp.push_back(pAnimal);
		}

		for (auto& it = vTmp.rbegin(); it != vTmp.rend(); ++it)
		{
			m_animalQueue.push_front(*it);
		}

		return pFound;
	}
};
