#pragma once
#include "List.h"
#include <vector>
class SortedMultiMap
{
private:
	List* elems;
	int nrofpairs;
	int capacity;
	bool (*Relation)(std::string,std::string);
	int hashFunction(std::string newKey);
public:
	SortedMultiMap(bool (*R)(std::string, std::string));
	~SortedMultiMap();
	void add(std::string newKey, std::string newValue);
	void remove(std::string newKey, std::string newValue);
	bool search(std::string newKey, std::vector<std::string>& l);
	void keys(std::vector<std::string>& l);
	void values(std::vector<std::string>& l);
	void pairs(std::vector<std::string>& k, std::vector<std::string>& v);
	static bool Alphabetical(std::string Key1, std::string Key2);
	int getCapacity() { return capacity; };
	int size() { return nrofpairs; };
	List* getElems() { return elems; }

};

class Iterator
{
private:
	int pos;
	List::nodePtr currentPos;
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
public:
	Iterator(SortedMultiMap s);
	void next();
	bool valid();
	List::nodePtr getCurrent();
}; 
	