//
// Queue.cpp
// COMP241
// Fall 2015
// PA4 Problem 2
// 19 November, 2015
// Nate McCain


#include <iostream>
#include "Queue.h"
#include <fstream>
#include <string>

using namespace std;

QueType::QueType()
{
    front = NULL;
    rear = NULL;
}

void QueType::makeEmpty()
{
    NodeType *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

QueType::~QueType()
{
    makeEmpty();
}

bool QueType::IsFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

bool QueType::IsEmpty() const
{
    return (front == NULL);
}

void QueType::Enqueue(string item)
{
    if (IsFull())
    {
        throw FullQueue();
    }
    else
    {
        NodeType *newNode = new NodeType;
        newNode->info = item;
        newNode->next = NULL;
        if (rear == NULL)
        {
            front = newNode;
        }
        else
        {
            rear->next = newNode;
        }
        rear = newNode;
    }
}

void QueType::Dequeue(string &item)
{
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    else
    {
        NodeType *temp = front;
        item = front->info;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
    }
}


void QueType::readFile(string fileName)
{
    fstream inFile;
    string readMe;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        exit(0);
    }
    while (!inFile.eof())
    {
        inFile >> readMe;
        Enqueue(readMe);
    }
    inFile.close();
}

void QueType::print()
{
    string item;
    while (!IsEmpty())
    {
        Dequeue(item);
        cout << item << endl;
    }
}
















