#include "SMM.h"
#include <assert.h>
#include "Test.h"

void Test::testAdd_and_Iterator()
{
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
	Iterator j{ smm };
	assert(j.valid() == false);
	assert(smm.size() == 0);
	smm.add("ana", "hi ana");
	assert(smm.size() == 1);
	smm.add("ada", "hi ada");
	assert(smm.size() == 2);
	smm.add("axa", "hi axa");
	assert(smm.size() == 3);
	smm.add("benny", "cool");
	smm.add("bailey", "Email");
	smm.add("bd", "test");
	smm.add("bda", "test2");
	assert(smm.size() == 7);
	int nr = 0;
	Iterator i{ smm };
	while (i.valid())
	{
		if (nr == 0)
			assert(i.getCurrent()->key == "ada" && i.getCurrent()->value == "hi ada");
		if (nr == 1)
			assert(i.getCurrent()->key == "ana" && i.getCurrent()->value == "hi ana");
		if (nr == 2)
			assert(i.getCurrent()->key == "axa" && i.getCurrent()->value == "hi axa");
		if (nr == 3)
			assert(i.getCurrent()->key == "bailey" && i.getCurrent()->value == "Email");
		if (nr == 4)
			assert(i.getCurrent()->key == "bd" && i.getCurrent()->value == "test");
		if (nr == 5)
			assert(i.getCurrent()->key == "bda" && i.getCurrent()->value == "test2");
		if (nr == 6)
			assert(i.getCurrent()->key == "benny" && i.getCurrent()->value == "cool");
		i.next();
		nr++;
	}
}

void Test::testRemove()
{
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
	smm.add("ana", "hi ana");
	smm.add("ada", "hi ada");
	smm.add("axa", "hi axa");
	smm.add("benny", "cool");
	smm.add("bailey", "Email");
	smm.remove("axa", "hi axa");
	assert(smm.size() == 4);
	smm.remove("ada", "hi ada");
	assert(smm.size() == 3);
	smm.remove("bailey", "Email");
	assert(smm.size() == 2);
	int nr = 0;
	Iterator i{ smm };
	while (i.valid())
	{
		if (nr == 0)
			assert(i.getCurrent()->key == "ana" && i.getCurrent()->value == "hi ana");
		if (nr == 1)
			assert(i.getCurrent()->key == "benny" && i.getCurrent()->value == "cool");
		i.next();
		nr++;
	}
}

void Test::testSearch()
{
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
	smm.add("ana", "hi ana");
	smm.add("ana", "hello ana");
	smm.add("ana", "hey there ana");
	smm.add("benny", "cool");
	smm.add("bailey", "Email");
	std::vector<std::string> l;
	smm.search("ana", l);
	int nr = 0;
	for (auto email : l)
	{
		if (nr == 0)
			assert(email == "hi ana");
		if (nr == 1)
			assert(email == "hello ana");
		if (nr == 2)
			assert(email == "hey there ana");
		nr++;
	}
	std::vector<std::string> k;
	smm.search("10ana", k);
	assert(k.size()==0);
}

void Test::testKeys()
{
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
	smm.add("ana", "hi ana");
	smm.add("ana", "hello ana");
	smm.add("ana", "hey there ana");
	smm.add("benny", "cool");
	smm.add("bailey", "Email");
	std::vector<std::string> l;
	smm.keys(l);
	int nr = 0;
	for (auto key : l)
	{
		if (nr == 0)
			assert(key == "ana");
		if (nr == 1)
			assert(key == "bailey");
		if (nr == 2)
			assert(key == "benny");
		nr++;
	}
}

void Test::testValues()
{
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
	smm.add("ana", "hi");
	smm.add("ana", "hi");
	smm.add("ana", "hey");
	smm.add("benny", "cool");
	smm.add("bailey", "Email");
	std::vector<std::string> l;
	smm.values(l);
	int nr = 0;
	for (auto value : l)
	{
		if (nr == 0)
			assert(value == "hi");
		if (nr == 1)
			assert(value == "hey");
		if (nr == 2)
			assert(value == "Email");
		if (nr == 3)
			assert(value == "cool");
		nr++;
	}
}

void Test::testPairs()
{
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
	smm.add("ana", "hi");
	smm.add("ana", "hi");
	smm.add("ana", "hey");
	smm.add("benny", "cool");
	smm.add("bailey", "Email");
	std::vector<std::string> k;
	std::vector<std::string> v;
	smm.pairs(k, v);
	
	for (int i=0;i<k.size();i++)
	{
		if (i == 0)
			assert(k[i]=="ana" && v[i] =="hi");
		if (i == 1)
			assert(k[i] == "ana" && v[i] == "hey");
		if (i == 2)
			assert(k[i] == "bailey" && v[i] == "Email");
		if (i == 3)
			assert(k[i] == "benny" && v[i] == "cool");
		
	}
}

void Test::testAll()
{
	testAdd_and_Iterator();
	testRemove();
	testSearch();
	testKeys();
	testValues();
	testPairs();
}



