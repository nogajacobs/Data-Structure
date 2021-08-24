# Data-Structure
#include <iostream>
#include <list>
#include <string>
#include "tree.h"
#include<iterator>
#include "treeList.h"
using namespace std;

void treeList::addNewTree(string val)//Enters the end of the list of discussions
{
	tree* t = new tree(val);
	tl.push_front(*t);
}

bool treeList::addResponse(string title, string father, string val)//add respone to his father in the asked title 
{
	tree* tTitle = findRoot(title);
	if (tTitle == NULL)
	{
		return false;
	}
	return tTitle->addNode(father, val);
}

tree* treeList::findRoot(string title) //search the titles in the list of the trees 
{
	tree* temp = new tree();
	for (list<tree>::iterator place = tl.begin(); place != tl.end(); place++)
	{
		if ((*place).getSubject() == title)
		{
			return &(*place);
		}
	}
	return NULL;
}

void treeList::delT(node* root) //delete tree
{
	tl.erase(findIt(*root));
}

list<tree>::iterator treeList::findIt(node rt)//Searches for the title of the forum you want in the discussion list
{
	for (list<tree>::iterator it = tl.begin(); it != tl.end(); it++)
		if (it->getRoot()->getContent() == rt.getContent())
			return it;
}

bool treeList::delResponse(string title, string val) //delete sub tree
{
	if (title == val)
	{
		for (list<tree>::iterator place = tl.begin(); place != tl.end(); place++)
		{
			if (place->getSubject() == title)
			{
				tl.erase(place);
				return true;
			}
		}
	}
	if (this->findRoot(title) != NULL)
		return (this->findRoot(title))->delSubTree(val);
	return false;
}

void treeList::printAllTrees()//Prints all the trees
{
	int i = 1;
	for (list<tree>::iterator place = tl.begin(); place != tl.end(); place++, i++)
	{
		cout << "tree #" << i << endl;
		(*place).printIt();
		cout << endl;
	}
}

bool treeList::searchAndPrint(string val) //search this string un all of the trees & print routs&subtrees
{
	bool flag = false;
	for (list<tree>::iterator place = tl.begin(); place != tl.end(); place++)
		if ((*place).findNode(val) != NULL)
		{
			place->printSubT(val);
			place->printRout(val);
			cout << endl << endl;
			flag = true;
		}
	return flag;
}

void treeList::printTree(string title)//Prints the desired wood
{
	tree* t = findRoot(title);
	t->printIt();
}

void treeList::printSubTree(string title, string val)//Prints the desired subwood
{
	tree* t = findRoot(title);
	if (t != NULL && t->findNode(val))
	{
		t->printSubT(val);
		if (title != val)
			t->printRout(val);
	}
}
