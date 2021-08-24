# Data-Structure
#include <iostream>
#include <list>
#include <string>
#include "node.h"

using namespace std;
#pragma once
class tree
{
	node* root;
public:
	//constructor
	tree() { root = NULL; }; //empty tree
	//constructor
	tree(string subject) { root = new node(subject); }; //tree with title
	//Destructor
	~tree() { if (root) delete root; }; //d-tor

	string getSubject();//Returns the strings of the discussion tree head
	node* getRoot();//Returns the pointer of the discussion tree head
	void setRoot(node* rt);//Changes the tree top discussions to another voter
	void newRoot(string val);//The head of the tree builds new discussions
	node* findNode(string val);//find node by its content
	bool addNode(string  father, string son); //add node to the asked father
	bool delSubTree(string val);//Deletes sub-tree in discussion tree
	void printIt();////print root
	void printRout(string val);//Prints the route from the top of the tree to the desired organ
	void printSubT(string val);//Prints the sub-trees in which the desired value is found
};
