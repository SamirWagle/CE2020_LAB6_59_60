#include "graph.h"
#include <iostream>

using namespace std;

bool graph::isEmpty()
{
    return (HEAD == nullptr) ? true : false;
};

bool graph::isDirected()
{
    return (directed) ? true : false;
};

void graph::addVertex(int vertexToAdd)
{
    Node *newNode = HEAD;
    Node *newNode1 = new Node(vertexToAdd);
    if (newNode == nullptr)
    {
        HEAD = newNode1;
        return;
    }
    while (true)
    {
        if (newNode->next == nullptr)
        {
            newNode->next = newNode1;
            break;
        }
        newNode = newNode->next;
    }
    return;
};

void graph::addEdges(int ver1, int ver2)
{
    Node *newNode = HEAD;
    Node *newNode1 = new Node(ver2);
    while (true)
    {
        if (newNode->data == ver1)
        {
            newNode1->neighbour = newNode->neighbour;
            newNode->neighbour = newNode1;
            break;
        }
        if (newNode->next == nullptr)
        {
            break;
        }
        newNode = newNode->next;
    }
    return;
};

void graph::removeVertex(int vertexToRemove)
{
    Node *newNode1 = HEAD;
    Node *newNode2;
    Node *newNode3 = nullptr;
    Node *newNode4;
    while (newNode1 != nullptr)
    {
        newNode2 = newNode1->neighbour;
        if (newNode1->data == vertexToRemove)
        {
            while (newNode1->neighbour != nullptr)
            {
                newNode2 = newNode1->neighbour;
                newNode1->neighbour = newNode2->neighbour;
                delete[] newNode2;
            }
            if (newNode3 == nullptr)
            {
                HEAD = newNode2->next;
                delete[] newNode2;
            }
            else
            {
                newNode3->next = newNode1->next;
                delete[] newNode1;
            }
        }
        newNode3 = newNode1;
        while (newNode2 != nullptr)
        {
            if (newNode2->data == vertexToRemove)
            {
                newNode3->neighbour = newNode2->neighbour;
                delete[] newNode2;
                break;
            }
            newNode2 = newNode2->neighbour;
            newNode3 = newNode3->neighbour;
        }
        newNode1 = newNode1->next;
    }
    return;
};

void graph::removeEdges(int ver1, int ver2)
{
    Node *newNode1 = HEAD;
    Node *newNode2;
    Node *newNode3;
    while (true)
    {
        if (newNode1->data == ver1)
        {
            newNode2 = newNode1->neighbour;
            newNode3 = newNode1;
            while (true)
            {
                if (newNode2->data == ver2)
                {
                    newNode3->neighbour = newNode2->neighbour;
                    delete[] newNode2;
                    return;
                }
                newNode2 = newNode2->neighbour;
                newNode3 = newNode3->neighbour;
            }
        }
        newNode1 = newNode1->next;
        if (newNode1 == nullptr)
        {
            break;
        }
    }
    return;
};

int graph::numVertex()
{
    Node *newNode = HEAD;
    int count = 0;
    while (newNode != nullptr)
    {
        count++;
        newNode = newNode->next;
    }
    return count;
};

int graph::numEdges()
{
    Node *vertex = HEAD;
    Node *neighbour1;
    int count = 0;
    while (vertex != nullptr)
    {
        neighbour1 = vertex->neighbour;
        while (neighbour1 != nullptr)
        {
            count++;
            neighbour1 = neighbour1->neighbour;
        }
        vertex = vertex->next;
    }
    return count;
};

int graph::inDegree(int ver)
{
    Node *vertex = HEAD;
    Node *neighbour1;
    int count = 0;
    while (vertex != nullptr)
    {
        neighbour1 = vertex->neighbour;
        while (neighbour1 != nullptr)
        {
            if (neighbour1->data == ver)
            {
                count++;
            }
            neighbour1 = neighbour1->neighbour;
        }
        vertex = vertex->next;
    }
    return count;
};

int graph::outDegree(int ver)
{
    Node *vertex = HEAD;
    Node *neighbour1;
    int count = 0;
    while (vertex != nullptr)
    {
        if (vertex->data == ver)
        {
            neighbour1 = vertex->neighbour;
            while (neighbour1 != nullptr)
            {
                count++;
                neighbour1 = neighbour1->neighbour;
            }
            break;
        }
    }
    return count;
};

int graph::degree(int ver)
{
    return (this->inDegree(ver) + this->outDegree(ver));
};

Node *graph::neighbours(int ver)
{
    Node *newNode = HEAD;
    while (newNode != nullptr)
    {
        if (newNode->data == ver)
        {
            return newNode->neighbour;
        }
        newNode = newNode->next;
    }
    return nullptr;
};

bool graph::isNeighbour(int ver1, int ver2)
{
    Node *newNode = HEAD;
    while (newNode != nullptr)
    {
        if (newNode->data == ver1)
        {
            while (newNode != nullptr)
            {
                newNode = newNode->neighbour;
                if (newNode->data == ver2)
                {
                    return true;
                }
            }
        }
        newNode = newNode->next;
    }
    return false;
};