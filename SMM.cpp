#include "SMM.h"
#include <vector>
SortedMultiMap::SortedMultiMap(bool (*R)(std::string,std::string))
{
	this->nrofpairs = 0;
	this->capacity = 53;
	this->elems = new List[this->capacity];
	this->Relation = R;
}
SortedMultiMap::~SortedMultiMap()
{
}
void SortedMultiMap::add(std::string newKey, std::string newValue)
{
	int pos = hashFunction(newKey);
	this->elems[pos].temp = this->elems[pos].head;
	bool wasAdded = false;
	while (this->elems[pos].temp != NULL && wasAdded == false)
	{
		if( (this->Relation(newKey,this->elems[pos].temp->key) ) == true)
		{
			this->elems[pos].addNodeBefore(newKey, newValue, this->elems[pos].temp);
			wasAdded = true;
		}
		else
		this->elems[pos].temp = this->elems[pos].temp->next;
	}
	if (this->elems[pos].head == NULL)
	{
		this->elems[pos].addNodeFirst(newKey, newValue);
	}
	else if( wasAdded == false)
	{
		this->elems[pos].addNodeEnd(newKey, newValue);
	}
	this->nrofpairs++;
}

void SortedMultiMap::remove(std::string newKey, std::string newValue)
{
	int pos = hashFunction(newKey);
	this->elems[pos].delNode(newKey, newValue);
	this->nrofpairs--;
}

bool SortedMultiMap::search(std::string newKey, std::vector<std::string>& l)
{
	int pos = hashFunction(newKey);
	this->elems[pos].temp = this->elems[pos].head;
	while (this->elems[pos].temp != NULL)
	{
		if (this->elems[pos].temp->key == newKey)
		{
			l.push_back(this->elems[pos].temp->value);
		}
		this->elems[pos].temp = this->elems[pos].temp->next;
	}
	if (l.size() > 0)
		return true;
	else
		return false;


}

void SortedMultiMap::keys(std::vector<std::string>& l)
{
	for (int i = 0;i < this->getCapacity();i++)
	{
		this->elems[i].temp = this->elems[i].head;
		while (this->elems[i].temp != NULL)
		{
			bool exists = false;
			for (auto k : l)
			{
				if (k == this->elems[i].temp->key)
					exists = true;
			}
			if (exists == false)
				l.push_back(this->elems[i].temp->key);
			this->elems[i].temp = this->elems[i].temp->next;
		}
	}
}

void SortedMultiMap::values(std::vector<std::string>& l)
{
	for (int i = 0;i < this->getCapacity();i++)
	{
		this->elems[i].temp = this->elems[i].head;
		while (this->elems[i].temp != NULL)
		{
			bool exists = false;
			for (auto v : l)
			{
				if (v == this->elems[i].temp->value)
					exists = true;
			}
			if (exists == false)
				l.push_back(this->elems[i].temp->value);
			this->elems[i].temp = this->elems[i].temp->next;
		}
	}
}

void SortedMultiMap::pairs(std::vector<std::string>& k, std::vector<std::string>& v)
{
	for (int i = 0;i < this->getCapacity();i++)
	{
		this->elems[i].temp = this->elems[i].head;
		while (this->elems[i].temp != NULL)
		{
			bool exists1 = false;
			bool exists2 = false;
			for (auto a : k)
			{
				if (a == this->elems[i].temp->key)
					exists1 = true;
			}
			for (auto a : v)
			{
				if (a == this->elems[i].temp->value)
					exists2 = true;
			}
			if (exists1 == false || exists2 == false)
			{
				k.push_back(this->elems[i].temp->key);
				v.push_back(this->elems[i].temp->value);
			}
			this->elems[i].temp = this->elems[i].temp->next;
		}
	}
}



int SortedMultiMap::hashFunction(std::string newKey)
{
	std::string alphabet = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int pos = alphabet.find(newKey[0]);
	if (pos != -1)
		return pos;
	else
		return 0;

}

bool SortedMultiMap::Alphabetical(std::string Key1, std::string Key2)
{
	if (Key1 < Key2)
		return true;
	else
		return false;
}

Iterator::Iterator(SortedMultiMap s)
{
	this->pos = 0;
	this->smm = s;
	bool ok = false;
	while (ok == false && this->pos < 53)
	{
		if (s.getElems()[this->pos].head == NULL)
			this->pos++;
		else
		{
			this->currentPos = s.getElems()[this->pos].head;
			ok = true;
		}
	}
	if (this->pos >= 53)
		this->currentPos = NULL;
}

void Iterator::next()
{
	if (this->currentPos->next != NULL)
		this->currentPos = this->currentPos->next;
	else
	{
		this->pos++;
		bool ok = false;
		while (ok == false && this->pos < 53)
		{
			if (this->smm.getElems()[this->pos].head == NULL)
				this->pos++;
			else
			{
				this->currentPos = this->smm.getElems()[this->pos].head;
				ok = true;
			}
		}
		if (this->pos >= 53)
			this->currentPos = NULL;
	}
}

bool Iterator::valid()
{
	return this->currentPos != NULL;
}

List::nodePtr Iterator::getCurrent()
{
	if (this->valid())
	{	
		return this->currentPos;
	}
}
