#pragma once
#include <string>

class List
{
public:
	typedef struct node {
		std::string key;
		std::string value;
		node* next;
	}* nodePtr;
	nodePtr head;
	nodePtr curr;
	nodePtr temp;

	List();
	void addNodeFirst(std::string newKey, std::string newValue);
	void addNodeBefore(std::string newKey, std::string newValue, nodePtr Node);
	void addNodeEnd(std::string newKey, std::string newValue);
	nodePtr searchNode(std::string newKey, std::string newValue);
	void delNode(std::string newKey, std::string newValue);

};