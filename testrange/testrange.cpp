// testrange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>



template <class T>
class num_iterator 
{
	T i;

public:

	explicit num_iterator(T position = 0) : i{ position } {}
	T operator*() const { return i; }
	num_iterator& operator++() 
	{
		++i;
		return *this;
	}

	bool operator!=(const num_iterator &other) const 
	{
		return i != other.i;
	}

	bool operator==(const num_iterator &other) const { return !(*this != other); }
};

template <class T>
class num_range
{
	T a;
	T b;

public:
	num_range(T from, T to)
		: a{ from }, b{ to }
	{}
	num_iterator<T> begin() const { return num_iterator<T>{ a }; }
	num_iterator<T> end()   const { return num_iterator<T>{ b }; }
};



namespace std
{
	template <class T>
	struct iterator_traits<num_iterator<T>>
	{
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using difference_type = T;
	};
}


int main()
{
	auto x = num_range<long long> { 1, 100000 };

	long long goal = 10000;
	auto it = std::lower_bound(std::begin(x), std::end(x), goal, [](const auto& item,const long long& goal) {
		auto result = item * item;
		return result < goal;
	});

	std::cout << *it << std::endl;


}
