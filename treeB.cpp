#include "treeB.h"
#include <cstddef>
#include "nodoB.h"
#include <iostream>
using namespace std;

void treeB::printTree(nodeB* _node)
{
    cout << endl;
    int i;
    for (i = 0; i < _node->getNumber(); i++) {
        if (!_node->getLeaf()) {
            printTree(_node->getChild(i));
        }
        cout << " " << _node->getValue(i);
    }

    if (!_node->getLeaf()) {
        printTree(_node->getChild(i));
    }
    cout << endl;
}

treeB::treeB(int grade)
{
    this->root = NULL;
    this->grade = grade;
}

bool treeB::insert(int _value)
{
    if (this->root == NULL) {
        root = new nodeB(this->grade, true);
        root->setValue(0, _value);
        root->setNumber(1);
    }
    else {
        if (root->getNumber() == 2 * this->grade - 1) {
            nodeB* newNode = new nodeB(this->grade, false);

            newNode->setChild(0, root);
            newNode->divideChild(0, this->root);

            int i = 0;
            if (newNode->getValue(0) < _value) {
                i++;
            }
            newNode->getChild(i)->insertValue(_value);   

            this->root = newNode;
            return true;
        }
        else {
            root->insertValue(_value);
        }
    }
}

void treeB::printTree()
{
    if (this->root != NULL) {
        this->printTree(this->root);
    }
}

