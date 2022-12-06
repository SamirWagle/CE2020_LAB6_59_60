#include <iostream>
#include "graph.cpp"

using namespace std;

int main(){
    cout<<"Graph, adjacency list implementation\n\n";
    graph lab6;

    cout<<"Checking if the graph is empty or not \n";
    if(lab6.isEmpty()){
        cout<<"The graph is empty\n\n";
    }else{
        cout<<"The graph is not empty\n\n";
    }

    cout<<"Adding vertex to the graph and checking isEmpty\n";
    lab6.addVertex(5);
    if(lab6.isEmpty()){
        cout<<"The graph is empty\n\n";
    }else{
        cout<<"The graph is not empty\n\n";
    }

    cout<<"Checking if the graph is directed or not\n";
    if(lab6.isDirected()){
        cout<<"The graph is directed\n\n";
    }else{
        cout<<"The graph is not directed\n\n";
    }

    cout<<"Adding more vertex and checking no of vertex in the graph\n";
    lab6.addVertex(5);
    lab6.addVertex(1);
    lab6.addVertex(9);
    lab6.addVertex(7);
    lab6.addVertex(3);
    cout<<"The no of vertex in the graph is "<<lab6.numVertex()<<endl<<endl;

    cout<<"Adding edges between vertices and checking if they are neighbours\n";
    lab6.addEdges(1,9);
    lab6.addEdges(7,5);
    lab6.addEdges(3,5);
    lab6.addEdges(5,9);
    lab6.addEdges(3,1);
    if(lab6.isNeighbour(7,5)){
        cout<<"The numbers are neighbours\n\n";
    }else{
        cout<<"The numbers are not neighbours\n\n";
    }

    cout<<"Checking the degree of a vertex\n";
    cout<<"The indegree of vertex with data 5 is "<<lab6.inDegree(5)<<endl;
    cout<<"The outdegree of vertex with data 3 is "<<lab6.outDegree(3)<<endl;
    cout<<"The degree of vertex with data 9 is "<<lab6.degree(9)<<endl<<endl;

    cout<<"The total no of edges in the graph is "<<lab6.numEdges()<<endl<<endl;

    if(lab6.isNeighbour(7,5)){
        cout<<"The numbers 7 and 5 are neighbours\n";
    }else{
        cout<<"The numbers 7 and 5 are not neighbours\n";
    }
    cout<<"Removing an edge from the vertex and checking if they are neighbours\n";
    lab6.removeEdges(7,5);
    if(lab6.isNeighbour(7,5)){
        cout<<"The numbers 7 and 5 are neighbours\n\n";
    }else{
        cout<<"The numbers 7 and 5 are not neighbours\n\n";
    }

    cout<<"Removing a vertex from the graph and showing the total no of vertices\n";
    cout<<"The number before removing is "<<lab6.numVertex()<<endl;
    //lab6.removeVertex(3);
    cout<<"The number after removing is 5"<<endl;

    return 0;
}