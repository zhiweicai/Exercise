#include "stdafx.h"
#include <optional>
#include <vector>
#include <utility>
#include <array>
#include <string>
#include <iostream>
#include <cassert>





template <class T>
class SampleStack
{
public:
	SampleStack()
	{
		vStorage.reserve(1024);
	}

	void push(const T& val)
	{
		vStorage.push_back(val);
	}

	std::optional<T> pop()
	{
		if (isEmpty())
			return std::nullopt;
		else
		{
			auto item = vStorage[vStorage.size() -1];
			vStorage.pop_back();
			return item;
		}
	}

	std::optional<T> top()
	{
		if (isEmpty())
			return std::nullopt;
		else
			return vStorage[vStorage.size() - 1];
	}

	unsigned int size()
	{
		return vStorage.size();
	}

	bool isEmpty()
	{
		return vStorage.size() == 0;
	}	

private:
	std::vector<T> vStorage;
};

int main()
{
	SampleStack <std::string> stringQ;


	std::string s1 = "This is a hash table for testing!";
	std::string s2 = "another test";
	std::string s3 = "latest test";

	stringQ.push(s1);
	stringQ.push(s2);
	stringQ.push(s3);


	assert(stringQ.size() == 3);
	assert(stringQ.top() == s3);
	assert(stringQ.size() == 3);

	assert(stringQ.pop() == s3);
	assert(stringQ.size() == 2);

	stringQ.pop();
	stringQ.pop();

	assert(stringQ.pop() == std::nullopt);




	return 0;
}
