# Data-Structure
#include "node.h"
#include <iostream>
#include <list>
#include <string>

list<node> node::getResponses()//Returns the pointer to the delayed response
{
	return responses;
}

string node::getContent()//Returns the requested string
{
	return content;
}

void node::setContent(string val)//Changes the string
{
	content = val;
}

node* node::findResponse(string val, node* title) //search a response with the asked string and return her pointer, else- return null
{
	if (getContent() == val)
		return this;
	node* temp, * tmp2;
	list<node>::iterator place;
	for (place = responses.begin(); place != responses.end(); place++)
	{
		temp = &(*place);
		if ((*temp).getContent() == val)
			return temp;
		if (!(*temp).getResponses().empty())
		{
			tmp2 = (*temp).findResponse(val, title);
			if (tmp2 != NULL)
				return tmp2;
		}
	}
	return NULL;
}	

void node::addR(string val)//add response
{
	node tmp(val);
	responses.push_back(tmp);
}

void node::print()
{
	int count = 0;
	this->printTree(count);
}

void node::printTree(int count)//Prints the desired tree
{
	cout << (*this).getContent() << endl; //print the content 

	if (!(*this).getResponses().empty()) //if there are responses(sons)
	{
		for (list<node>::iterator place = responses.begin(); place != responses.end(); place++) //ֳ ֳ­ ֳ©ֳ¹ ֳ ֳ¹ֳ®ֳ§ ֳ¹ֳ¬ ֳ÷ֳ¢ֳ¥ֳ¡ֳ¥ֳ÷ - ֳ ֳ¦ ֳ¸ֳµ ֳ²ֳ¬ ֳ₪ֳ¸ֳ¹ֳ©ֳ®ֳ₪ ֳ¹ֳ¬ֳ₪
		{
			count++;
			for (int i = 0; i < count; i++)
			{
				cout << "   "; //print the space according to the level
			}
			place->printTree(count); //calling the funk for the son
			count--;
		}
	}
}

void node::printRoutN(string val, node* title)
{
	for (list<node>::iterator place = responses.begin(); place != responses.end(); place++) //ֳ ֳ­ ֳ©ֳ¹ ֳ ֳ¹ֳ®ֳ§ ֳ¹ֳ¬ ֳ÷ֳ¢ֳ¥ֳ¡ֳ¥ֳ÷ - ֳ ֳ¦ ֳ¸ֳµ ֳ²ֳ¬ ֳ₪ֳ¸ֳ¹ֳ©ֳ®ֳ₪ ֳ¹ֳ¬ֳ₪
	{
		if (place->findResponse(val, title) != NULL /*&& place->findResponse(val, title) != &(*place)*/) //^^^^^^^^^^
			{
			place->printRoutN(val, title);
			cout << place->getContent() << "=>";
			break;
			}

		}
}

node* node::findFather(string val)//Returns a pointer to the father of the requested value
{
	node* temp;
	for (list<node>::iterator place = responses.begin(); place != responses.end(); place++)
	{

		temp = &(*place);
		if ((*temp).getContent() == val)
			return this;
		if (!(*temp).getResponses().empty())
			return (*temp).findFather(val);
	}
	return NULL;
}

bool node::delR(string val) //delete sub tree
{
	node* father = findFather(val);
	if (father != NULL)
	{
		for (list<node>::iterator place = father->responses.begin(); place != father->responses.end(); place++)
		{
			if (place->content == val)
			{
				father->responses.erase(place);
				return true;
			}
		}
	}
	return false;
}
