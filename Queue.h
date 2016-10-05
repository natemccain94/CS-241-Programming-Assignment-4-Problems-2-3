//
// Queue.h
// COMP241
// Fall 2015
// PA4 Problem 2
// 19 November, 2015
// Nate McCain

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FullQueue
{};
class EmptyQueue
{};

struct NodeType;

class QueType
{
public:
    QueType();
    ~QueType();
    void makeEmpty();
    void Enqueue(string item);
    void Dequeue(string &item);
    bool IsEmpty() const;
    bool IsFull() const;
    
    // Read the file.
    void readFile(string fileName);
    void print();
    
private:
    NodeType *front;
    NodeType *rear;
};

struct NodeType
{
    string info;
    NodeType *next;
};

#endif