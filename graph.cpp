#include<iostream>
#include"graph.h"
using namespace std;
bool graph::isEmpty()
{
    if(head==nullptr)
        return true;
    else
        return false;
};
bool graph::isDirected()
{
    return directed;
};
void graph::addVertex(const int key)
{
    node *temp=new node(key);
    if(isEmpty())
    {
        head=temp;
    }
    else
    {
        node *temp1=head;
        while(temp1->next!=nullptr)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
};

void graph::addEdge(int key1, int key2)
{
        
};
void graph::removeVertex(const int key)
{
    
};
void graph::removeEdge(const int key1,const int key2)
{
    
};
int graph::numEdges()
{
    return 0;
};
int graph::numVertices()
{
    return 0;
};
