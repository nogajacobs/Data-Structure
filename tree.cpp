# Data-Structure
#include "tree.h"
#include <iostream>
#include <list>
#include <string>
#include "node.h"
using namespace std;

string tree::getSubject()
{
	return root->getContent();
}

node* tree::getRoot()
{
	return root;
}

void tree::setRoot(node* rt)
{
	root = rt;
}

void tree::newRoot(string val)//The head of the tree builds new discussions
{
	if (root)
		delete root;
	root = new node(val);
}

node* tree::findNode(string val) //find node by its content
{
	return this->getRoot()->findResponse(val, root);
}

bool tree::addNode(string  father, string son) //add node to the asked father
{
	node* tmp = this->findNode(father);
	if (tmp == NULL)
		return false;
	tmp->addR(son);
	return true;
}

bool tree::delSubTree(string val)//Deletes sub-tree in discussion tree
{
	return root->delR(val);
}

void tree::printIt()//print root
{
	if (root != NULL) 
		root->print();
}

void tree::printRout(string val)//Prints the route from the top of the tree to the desired organ
{
	node* tmp = findNode(val);
	root->printRoutN(val, root);
	cout << root->getContent();
}

void tree::printSubT(string val)//Prints the sub-trees in which the desired value is found
{
	node* tmp = findNode(val);
	if (tmp != NULL)
		(*tmp).print();
}
