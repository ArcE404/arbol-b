// arbol-b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "treeB.h"

using namespace std;

int main()
{
    treeB* t = new treeB(3);
    t->insert(11);
    t->insert(9);
    t->insert(16);
    t->insert(10);
    t->insert(8);
    t->insert(17);
    t->insert(15);
    t->insert(20);
    t->insert(23);
    t->insert(18);

    cout << "The B-tree is: ";
    t->printTree();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
