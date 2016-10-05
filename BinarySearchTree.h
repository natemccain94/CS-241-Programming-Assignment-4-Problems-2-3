//
//  BinarySearchTree.h
//  Programming Assignment 4
//
//  Created by Nate McCain on 11/12/15.
//  Copyright © 2015 Nate McCain. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include <iostream>
#include "Queue.h"

using namespace std;


struct TreeNode;

class TreeType
{
public:
    TreeType();
    ~TreeType();
    TreeType(const TreeType &originalTree);
    void operator=(const TreeType &originalTree);
    void makeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int GetLength() const;
    int GetItem(int item, bool &found);
    void PutItem(int item);
    void DeleteItem(int item);
    void Print() const;
    
    
private:
    TreeNode *root;
};

struct TreeNode
{
    int info;
    TreeNode *left;
    TreeNode *right;
};


#endif /* BinarySearchTree_h */
