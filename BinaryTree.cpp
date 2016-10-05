//
// BinaryTree.cpp
// COMP241
// Fall 2015
// PA4 Problem 2
// 19 November, 2015
// Nate McCain

#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Queue.h"

using namespace std;


// Constructor
BinType::BinType()
{
    root = new BinNode;
    head = root;
}

// Destroy Function
void Destroy(BinNode *&tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

// Destructor
BinType::~BinType()
{
    Destroy(root);
}

// Counting Nodes
int CountNodes(BinNode *tree)
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
int BinType::GetLength() const
{
    return CountNodes(root);
}

// Retrieve Function
void Retrieve(BinNode *tree, int &item, bool &found)
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
int BinType::GetItem(int item, bool &found)
{
    Retrieve(root, item, found);
    return item;
}

//*****************************
void addNode(BinNode *&tree, int item);
//*****************************

void BinType::unorderBin(QueType list, string readFile)
{
    BinNode *moving;
    string convertMe;
    int conversion;
    list.readFile(readFile);
    
    // First insertion must be outside of.he while loop.
    list.Dequeue(convertMe);
    conversion = stoi(convertMe);
    addNode(root, conversion);
    moving = root;
    
    // For my checkBST function, it needs an updated min and max.
    min = conversion;
    max = conversion;
    
    // After the very first node is inserted.
    while (!(list.IsEmpty()))
    {
        list.Dequeue(convertMe);
        // It should go to the left child
        if (convertMe != "null")
        {
            if (root->left != NULL)
            {
                conversion = stoi(convertMe);
                root->right = new BinNode;
                root = root->right;
                addNode(root, conversion);
                root->parent = moving;
                moving = root;
                if (conversion > max)
                {
                    max = conversion;
                }
            }
            
            // It should go to the right child
            else
            {
                conversion = stoi(convertMe);
                root->left = new BinNode;
                root = root->left;
                addNode(root, conversion);
                root->parent = moving;
                moving = root;
                
                if (conversion < min)
                {
                    min = conversion;
                }

            }
        }
        // It is null
        else
        {
            // If we are not at the end of the list, dequeue again
            if (!list.IsEmpty())
            {
                list.Dequeue(convertMe);
                // If it is not null, move to the right child
                if (convertMe != "null")
                {
                    conversion = stoi(convertMe);
                    root->right = new BinNode;
                    root = root->right;
                    addNode(root, conversion);
                    root->parent = moving;
                    moving = root;
                    
                    if (conversion > max)
                    {
                        max = conversion;
                    }
                    
                }
            
                else
                {
                    if (!list.IsEmpty())
                    {
                        root = root->parent;
                        while(root->right != NULL && root != head)
                        {
                            root = root->parent;
                        }
                        // This checks to see if it is a valid binary tree
                        if (root->right != NULL && root == head)
                        {
                            cout << "The file does not contain a valid binary tree. Goodbye." << endl;
                            exit(0);
                        }
                        moving = moving->parent;
                    }
                    else
                    {
                        
                    }
                
                }
            }
        }
        
        
    }
    cout << "This is a valid binary tree. " << endl;
    root = head;
}

void addNode(BinNode *&tree, int item)
{
    if (tree == NULL)
    {
        tree = new BinNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else
    {
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }

}


void PrintBin(BinNode *tree)
{
    if (tree != NULL)
    {
        cout << tree->info << endl;
        PrintBin(tree->left);
        PrintBin(tree->right);
    }
}

// Call to print function
void BinType::Print() const
{
    cout << "Now performing a pre-order traversal for the print function." << endl;
    PrintBin(root);
}

bool checkBST(BinNode *node, int min, int max)
{
    // if empty tree, which is technically a BST
    if (node == NULL)
    {
        return true;
    }
    
    // If this check fails, it is not a BST
    if (node->info >= min && node->info <= max)
    {
        return (checkBST(node->left, min, node->info) && checkBST(node->right, node->info, max));
    }
    // Recursive step, keep checking the other subtrees
    else
    {
        return false;
    }
}


void BinType::IsBST()
{
    bool x = checkBST(head, min, max);
    if (x == true)
    {
        cout << "This tree is a valid binary search tree." << endl;
    }
    else
    {
        cout << "This tree is not a valid binary search tree." << endl;
    }
}


int findHeight(BinNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        int leftSub = findHeight(node->left);
        int rightSub = findHeight(node->right);
        if (leftSub > rightSub)
        {
            return 1 + leftSub;
        }
        else
        {
            return 1 + rightSub;
        }
    }
}

void BinType::treeHeight()
{
    cout << "The height of this tree is: " << findHeight(head) << endl;
}



















