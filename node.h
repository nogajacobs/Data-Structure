# Data-Structure
#include <iostream>
#include <list>
#include <string>
#pragma once
using namespace std;
class node
{
	string content;
	list<node> responses;
public:
	//constructor
	node()
	{
		content = '\0';
		list<node> responses;
	};
	//constructor
	node(string val) { content = val; };
	//Destructor
	~node()
	{
		if (!responses.empty())
		{
			responses.clear();
		}
	};

	list<node> getResponses();//Returns the pointer to the delayed response
	string getContent();//Returns the requested string
	void setContent(string val);//Changes the string
	node* findResponse(string val, node* title); //search a response with the asked string and return her pointer, else- return null
	void addR(string val);//add response
	void print();//Prints the desired tree
	void printTree(int count);//Recursive call
	void printRoutN(string val, node* title);
	bool delR(string val); //delete sub tree
	node* findFather(string val);//Returns a pointer to the father of the requested value
};
