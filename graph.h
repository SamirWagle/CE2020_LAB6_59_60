#ifndef GRAPH_H
#define GRAPH_H
class node
{
public:
    node *next;
    int data;
    node *neighbour;
    node(int key = 0, node *n1 = nullptr, node *n2 = nullptr) : data(key), next(n1), neighbour(n2) {}
};
class graph
{
public:
    node *head;
    bool directed;
    graph(node* node=nullptr,bool direction=true) : head(node),directed(direction){}
    bool isEmpty();
    bool isDirected();
    void addVertex(int key);
    void addEdge(int key1,int key2);
    void removeVertex(int key);
    void removeEdge(int key1,int key2);
    int numEdges();
    int numVertices();
    



};

#endif