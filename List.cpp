#include "List.h"

List::List()
{
	this->head = NULL;
	this->curr = NULL;
	this->temp = NULL;
}
void List::addNodeFirst(std::string newKey, std::string newValue)
{
	nodePtr n = new node;
	n->key = newKey;
	n->value = newValue;
	n->next = this->head;
	this->head = n;
}
void List::addNodeBefore(std::string newKey, std::string newValue, nodePtr Node)
{
	if (this->head->key == Node->key && this->head->value == Node->value)
	{
		this->addNodeFirst(newKey, newValue);
	}
	else
	{
		nodePtr n = new node;
		n->key = newKey;
		n->value = newValue;
		this->temp = this->head;
		bool wasAdded = false;
		while (this->temp != NULL && wasAdded == false)
		{
			if (this->temp->next->key == Node->key && this->temp->next->value == Node->value)
			{
				n->next = this->temp->next;
				this->temp->next = n;
				wasAdded = true;
			}
			else
				this->temp = this->temp->next;

		}

	}
}

void List::addNodeEnd(std::string newKey, std::string newValue)
{
	nodePtr n = new node;
	n->key = newKey;
	n->value = newValue;
	n->next = NULL;
	this->temp = this->head;
	while (this->temp->next != NULL)
		this->temp = this->temp->next;
	this->temp->next = n;
}

List::nodePtr List::searchNode(std::string newKey, std::string newValue)
{
	if (this->head->key == newKey && this->head->value == newValue)
		return this->head;
	else
	{
		this->temp = this->head->next;
		while (this->temp != NULL)
		{
			if (this->temp->key == newKey && this->temp->value == newValue)
			return this->temp;
			else
			this->temp = this->temp->next;
			
		}
		return NULL;
	}
}
void List::delNode(std::string newKey, std::string newValue)
{
	if (this->head->key == newKey && this->head->value == newValue)
		this->head = this->head->next;
	else
	{
		this->curr = this->head;
		this->temp = this->head->next;
		bool deleted = false;
		while (this->temp != NULL &&  deleted == false)
		{
			if (this->temp->key == newKey && this->temp->value == newValue)
			{
				this->curr->next = this->temp->next;
				deleted = true;
			}
			else
			{
				this->curr = this->curr->next;
				this->temp = this->temp->next;
			}

		}
	}
}
