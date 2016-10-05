//
//  BinarySearchTree.cpp
//  Programming Assignment 4
//
//  Created by Nate McCain on 11/12/15.
//  Copyright © 2015 Nate McCain. All rights reserved.
//

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

// Constructor
TreeType::TreeType()
{
    root = NULL;
}

// Destroy Function
void Destroy(TreeNode *&tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

// Destructor
TreeType::~TreeType()
{
    Destroy(root);
}

// Counting Nodes
int CountNodes(TreeNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        return (CountNodes(tree->left)+CountNodes(tree->right)+1);
    }
}

// Get Length Function
int TreeType::GetLength() const
{
    return CountNodes(root);
}

// Retrieve Function
void Retrieve(TreeNode *tree, int &item, bool &found)
{
    if (tree == NULL)
    {
        found = false;
    }
    else if (item < tree->info)
    {
        Retrieve(tree->left, item, found);
    }
    else if (item > tree->info)
    {
        Retrieve(tree->right, item, found);
    }
    else
    {
        item = tree->info;
        found = true;
    }
}

// Get Item Function
int TreeType::GetItem(int item, bool &found)
{
    Retrieve(root, item, found);
    return item;
}

// Insert Function
void Insert(TreeNode *&tree, int item)
{
    if (tree == NULL)
    {
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
    {
        Insert(tree->left, item);
    }
    else
    {
        Insert(tree->right, item);
    }
}

// Put Item Function
void TreeType::PutItem(int item)
{
    Insert(root, item);
}

// Get Predecessor
void GetPredecessor(TreeNode *tree, int &data)
{
    while (tree->right != NULL)
    {
        tree = tree->right;
        data = tree->info;
    }
}


//*************************
void Delete(TreeNode *&tree, int item);

// Delete Node Function
void DeleteNode(TreeNode *&tree)
{
    int data;
    TreeNode *temp = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete temp;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete temp;
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}

void Delete(TreeNode *&tree, int item)
{
    if (item < tree->info)
    {
        Delete(tree->left, item);
    }
    else if (item > tree->info)
    {
        Delete(tree->right, item);
    }
    else
    {
        DeleteNode(tree);
    }
}

// Main caller for delete function
void TreeType::DeleteItem(int item)
{
    Delete(root, item);
}

// Print Function
void PrintTree(TreeNode *tree)
{
    if (tree != NULL)
    {
        cout << tree->info << endl;
        PrintTree(tree->left);
        //cout << tree->info << endl;
        PrintTree(tree->right);
    }
}

// Call to print function
void TreeType::Print() const
{
    PrintTree(root);
}

// Copy Tree Function
void CopyTree(TreeNode *&copy, const TreeNode *originalTree)
{
    if (originalTree == NULL)
    {
        copy = NULL;
    }
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}


// Operator=
void TreeType::operator=(const TreeType &originalTree)
{
    if (&originalTree == this)
    {
        return;
    }
    Destroy(root);
    CopyTree(root, originalTree.root);
}

TreeType::TreeType(const TreeType &originalTree)
{
    CopyTree(root, originalTree.root);
}



//**********************************************










