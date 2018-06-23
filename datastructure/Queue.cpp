#include "stdafx.h"
#include <optional>
#include <vector>
#include <utility>
#include <array>
#include <string>
#include <iostream>
#include <cassert>





template <class T, int DefaultSize = 1024>
class SampleQueue
{
public:

	SampleQueue(): tailIndex (0),headIndex (0)
	{
	}

	bool push (const T& val)
	{	
		if (isFull())
			return false;
		else
		{
			vStorage[tailIndex++] = val;
			return true;
		}
	}

	std::optional<T> pop()
	{		
		if (isEmpty())
			return std::nullopt;
		else
		{
			auto item = vStorage[headIndex];
			headIndex ++;
			return item;
		}
	}

	std::optional<T> top()
	{
		if (isEmpty())
			return std::nullopt;
		else
			return vStorage[headIndex];
	}

	unsigned int size()
	{
		if (tailIndex > headIndex)
			return tailIndex - headIndex;
		else
			return tailIndex - headIndex + DefaultSize;
	}

	bool isEmpty()
	{
		return headIndex == tailIndex;
	}

	bool isFull()
	{
		return tailIndex == headIndex - 1;
	}

private:
	std::array<T,DefaultSize> vStorage;

	int headIndex;
	int tailIndex;
};

int main()
{
	SampleQueue <std::string> stringQ;


	std::string s1 = "This is a hash table for testing!";
	std::string s2 = "another test";
	std::string s3 = "latest test";

	stringQ.push(s1);
	stringQ.push(s2);
	stringQ.push(s3);

	
	assert(stringQ.size() == 3);
	assert(stringQ.top() == s1);
	assert(stringQ.size() == 3);

	assert(stringQ.pop() == s1);
	assert(stringQ.size() == 2);

	stringQ.pop();
	stringQ.pop();

	assert(stringQ.pop() == std::nullopt);




	return 0;
}
