#include <iostream>
#include "graph.cpp"

using namespace std;

int main(){
    cout<<"Graph Adjacency List\n\n";
    graph g1;

    cout<<"Is our graph empty??? \n";
    if(g1.isEmpty()){
        cout<<"The graph is empty\n\n";
    }else{
        cout<<"The graph is not empty\n\n";
    }

    cout<<"Adding vertex to the graph \n\n And checking isEmpty\n";
    g1.addVertex(5);
    if(g1.isEmpty()){
        cout<<"Graph is empty\n\n";
    }else{
        cout<<"Graph is not empty\n\n";
    }

    cout<<"Is the graph Directed???\nLet's check\n\n";
    if(g1.isDirected()){
        cout<<"The graph is directed\n\n";
    }else{
        cout<<"The graph is not directed\n\n";
    }

    cout<<"Adding more vertex and checking no of vertex in the graph\n";
    g1.addVertex(100);
    g1.addVertex(50);
    g1.addVertex(40);
    g1.addVertex(30);
    g1.addVertex(5);
    cout<<"The number of vertex in the graph is "<<g1.numVertex()<<endl<<endl;

    cout<<"Adding edges between vertices\n\n Checking if they are neighbours or not\n";
    g1.addEdges(50,40);
    g1.addEdges(30,100);
    g1.addEdges(5,100);
    g1.addEdges(100,40);
    g1.addEdges(5,50);
    if(g1.isNeighbour(30,100)){
        cout<<"The numbers are neighbours of each other\n\n";
    }else{
        cout<<"The numbers are not neighbours\n\n";
    }

    cout<<"Checking the Degree of a Vertex\n";
    cout<<"Indegree of vertex 100 is "<<g1.inDegree(5)<<endl;
    cout<<"Outdegree of vertex 5 is "<<g1.outDegree(3)<<endl;
    cout<<"Degree of vertex 40 is "<<g1.degree(9)<<endl<<endl;

    cout<<"The total number of edges in the graph "<<g1.numEdges()<<endl<<endl;

    if(g1.isNeighbour(30,100)){
        cout<<"30 and 100 are neighbours\n";
    }else{
        cout<<"30 and 100 are not neighbours\n";
    }
    cout<<"Removing an edge from the vertex and checking if they are neighbours\n";
    g1.removeEdges(30,100);
    if(g1.isNeighbour(30,100)){
        cout<<"30 and 100 are neighbours\n\n";
    }else{
        cout<<"30 and 100 are not neighbours\n\n";
    }

    cout<<"Removing a vertex from the graph and showing the total no of vertices\n";
    cout<<"The number before removing is "<<g1.numVertex()<<endl;
   
    cout<<"The number after removing is "<<endl;
 g1.removeVertex(3);
    return 0;
}