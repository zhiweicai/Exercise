// hashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <optional>
#include <vector>
#include <utility>
#include <array>
#include <string>
#include <iostream>



template <class Key, class Value>
class HashNode
{
public:
	HashNode(const Key& k, const Value& v):
		key(k), val(v)
	{
	}

	Key getKey() const
	{
		return key;
	}

	Value getValue() const
	{
		return val;
	}

	void append(const Key& k, const Value& v)
	{
		others.push_back(std::make_pair(k, v));
	}

	std::vector<std::pair<Key, Value>>& getOther()
	{
		return others;
	}


private:
	Key key;
	Value val;
	std::vector<std::pair<Key, Value>> others;
};



template <class Key>
struct Hashkey
{
public:
	int hash (const Key& k) const
	{
		return k.size();
	}
};


template <class Key, class Value, class F = Hashkey<Key>, int nTableSize = 1024>
class SampleHashTable
{
public:

	SampleHashTable()
	{		
	}

	void insert(const Key& key, const Value& val)
	{	
		auto hashValue = hash(key);
		if (!vStorage[hashValue])
			vStorage[hashValue] = HashNode<Key,Value> (key,val);
		else
		{
			vStorage[hashValue].value().append(key, val);
		}		
	}

	void remove(const Key& key)
	{

	}

	std::optional<Value> find(const Key& key)
	{
		auto hashValue = hash(key);

		auto node = vStorage[hashValue];
		if (!node)
			return std::nullopt;
		else
		{
			auto hashnode = node.value();
			if (hashnode.getKey() == key)
				return hashnode.getValue();
			else
			{
				auto other = hashnode.getOther();
				auto it = std::find_if(other.begin(), other.end(), [&key](std::pair<Key, Value>& item)
				{
					return item.first == key;
				});

				if (it == other.end())
					return std::nullopt;
				else
					return it->second;
			}

		}

	}

	int hash(const Key& key)
	{
		return hashFun.hash(key) % nTableSize;
	}
	
	

private:
	std::array<std::optional<HashNode<Key,Value>>, nTableSize> vStorage;
	F hashFun;

};

int main()
{
	SampleHashTable <std::string, std::string> vTable;

    
	vTable.insert("test1", "This is a hash table for testing!");
	vTable.insert("test11", "Another test");
	vTable.insert("test2", "do not find the wrong item");

	auto it = vTable.find("test1");
	if (it)
		std::cout << it.value() << std::endl;

	auto it2 = vTable.find("test2");
	if (it2)
		std::cout << it2.value() << std::endl;


    return 0;
}

