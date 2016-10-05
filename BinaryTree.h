//
// BinaryTree.h
// COMP241
// Fall 2015
// PA4 Problem 2
// 19 November, 2015
// Nate McCain

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <string>
#include <iostream>
#include "Queue.h"



struct BinNode;

class BinType
{
public:
    BinType();
    ~BinType();
    void makeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int GetLength() const;
    int GetItem(int item, bool &found);
    void DeleteItem(int item);
    void Print() const;
    
    // Problem Two Function
    void unorderBin(QueType list, string readFile);
    void IsBST();
    void treeHeight();
    
private:
    BinNode *root;
    BinNode *head;
    int min;
    int max;
};

struct BinNode
{
    int info;
    BinNode *left;
    BinNode *right;
    BinNode *parent;
    
};



#endif /* BinaryTree_h */
