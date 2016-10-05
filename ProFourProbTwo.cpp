//
// ProFourProbTwo.cpp
// COMP241
// Fall 2015
// PA4 Problem 2
// 19 November, 2015
// Nate McCain

#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"
#include "Queue.h"

using namespace std;

void createTree();

int main()
{
    QueType test;
    BinType tree;
    tree.unorderBin(test, "tree2.txt");
    tree.Print();
    tree.IsBST();
    tree.treeHeight();
    
    return 0;
}
