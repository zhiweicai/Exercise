#pragma once

#include <vector>
#include <stack>

template <class T,std::size_t N>
class StackPlate
{
private: std::vector <std::stack<T>> m_vPlates;

public:
	void push(T t)
	{
		if (m_vPlates.empty())
		{
			std::stack<T> mystack;
			mystack.push(t);
			m_vPlates.push_back(mystack);			
		}
		else
		{
			std::stack<T>& currentStack = m_vPlates[m_vPlates.size() - 1];

			if (currentStack.size() == N)
			{
				std::stack<T> mystack;
				mystack.push(t);
				m_vPlates.push_back(mystack);
			}
			else
			{
				currentStack.push(t);
			}

		}		
		
	}

	T pop()
	{
		if (m_vPlates.empty())
		{
			throw "Empty stack!";
		}
		else
		{
			std::stack<T>& currentStack = m_vPlates[m_vPlates.size() - 1];
			T t = currentStack.top();
			currentStack.pop();

			if (currentStack.empty())
				m_vPlates.pop_back();

			return t;
		}
	}


	T popAt(int index)
	{
		if (m_vPlates.size() < index)
			throw "No such index!";


		std::stack<T>& currentStack = m_vPlates[index];
		T t = currentStack.top();
		currentStack.pop();

		if (currentStack.empty())
			m_vPlates.erase(m_vPlates.begin() + index);

		return t;
	}



	int numOfStack()
	{
		return m_vPlates.size();
	}

};

