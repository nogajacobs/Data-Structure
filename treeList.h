# Data-Structure
#include <iostream>
#include <list>
#include <string>
#include "tree.h"
#include<iterator>
#pragma once
using namespace std;
class treeList
{
	std::list <tree> tl;
public:
	//constructor
	treeList() { list<tree> tl; };
	//Destructor
	~treeList() { tl.clear(); };

	list<tree> getTreeList() { return tl; };
	/*
	Creating a new discussion tree: 
	Absorbing a string that will be at the root of the tree 
	(beginning of the discussion).
	*/
	void addNewTree(string val);
	/*
	Add a comment to the discussion:
Absorption of S1 string of the discussion root,
Absorption of S2 string of current response
  And absorbing the required response S3.
	*/
	bool addResponse(string title, string father, string val);//add respone to his father in the asked title 
	tree* findRoot(string title); //search the titles in the list of the trees 
	void delT(node* root); //delete tree
	list<tree>::iterator findIt(node rt);
	/*Deleting a sub - tree: 
	Absorbs the S1 string of a discussion root, 
	and a S2 string of current sub - discussion content, 
	and deletes the entire sub - thread of the discussion that begins with the S2 string within the tree rooted in the S1 string.
	*/
	bool delResponse(string title, string val); //delete sub tree
	//Print all discussion trees:
	void printAllTrees();
	/*
	String search in discussions:
Absorbing a particular string and printing the places where that
string is in the discussion trees.
For each string found,
  Print the entire route from the tree root to the string and 
  print the entire sub-tree of the sub-thread starting with that string.
	*/
	bool searchAndPrint(string val); //search this string un all of the trees & print routs&subtrees
	
	void printTree(string title);
	/*
	Sub-Tree Discussion Printing:
	Absorbing the S1 string of the beginning of a discussion, 
	S2 string of the current response in the discussion, 
	and printing in a standing form of each discussion sub-tree starting with the S2 response within the rooted tree contains the S1 string.
	*/
	void printSubTree(string title, string val);
	
};
