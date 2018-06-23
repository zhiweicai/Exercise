#include "stdafx.h"
#include <optional>
#include <vector>
#include <utility>
#include <array>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>


template <class T, class Compare>
class SamplePQueue
{
public:
	SamplePQueue()
	{
		vStorage.reserve(1024);
	}


	SamplePQueue(const std::vector<T>& q)
	{
		vStorage = q;
		std::make_heap(vStorage.begin(), vStorage.end());
	}

	void push(const T& val)
	{
		vStorage.push_back(val);
		std::push_heap(vStorage.begin(), vStorage.end(), func);
	}

	std::optional<T> pop()
	{
		if (isEmpty())
			return std::nullopt;
		else
		{
			std::pop_heap(vStorage.begin(), vStorage.end(),func);
			auto item = vStorage.back();
			vStorage.pop_back();
			return item;
		}
	}

	std::optional<T> top()
	{
		if (isEmpty())
			return std::nullopt;
		else
			return vStorage.front();
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

	Compare func;
};

template<class T>
struct SampleLess
{
	bool operator()(const T& a, const T& b)
	{ 
		if (a.size() > b.size())
			return true;
		else 
			return false;
	}
};


int main()
{
	//auto anotherLess = [](const std::string& a, const std::string& b)
	//{
	//	if (a.length() >  b.length())
	//		return true;
	//	else
	//		return false;
	//};

	SamplePQueue <std::string, SampleLess<std::string>> stringQ;


	std::string s1 = "This is a hash table for testing!";
	std::string s2 = "I am the third";
	std::string s3 = "first";
	std::string s4 = "The second";

	stringQ.push(s1);
	stringQ.push(s2);
	stringQ.push(s3);
	stringQ.push(s4);


	assert(stringQ.size() == 4);
	assert(stringQ.top() == s3);
	assert(stringQ.size() == 4);

	assert(stringQ.pop() == s3);
	assert(stringQ.size() == 3);

	assert(stringQ.pop() == s4);
	assert(stringQ.pop() == s2);
	assert(stringQ.pop() == s1);

	assert(stringQ.pop() == std::nullopt);



	std::vector<std::string> vTest;
	vTest.push_back(s1);
	vTest.push_back(s2);
	vTest.push_back(s3);
	vTest.push_back(s4);

	SamplePQueue <std::string, SampleLess<std::string>> Q2(vTest);

	assert(Q2.top() == s3);


	return 0;
}
