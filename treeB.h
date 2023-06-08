#include "nodoB.h"
#pragma once
class treeB {
private:
	nodeB* root;
	int grade;
	nodeB *search(int _value, nodeB* _node);
	void printTree(nodeB* _node);
public:
	treeB(int grade);
	bool insert(int _value);
	void printTree();
	nodeB search(int _value);
};
