#include "graph.h"
#include <iostream>

using namespace std;

bool graph::isEmpty(){
    if(head==nullptr){
        return true;
    }
    return false;
};

bool graph::isDirected(){
    return directed;
};

void graph::addVertex(int key){
    node* temp = head;
    node*temp1=new node(key);
    if(temp==nullptr){
        head = temp1;
        return;
    }
    while (true){
        if(temp->next==nullptr){
            temp->next=temp1;
            break;
        }
        temp=temp->next;
    }
    return;
};

void graph::addEdges(int key1, int key2){
    node* temp = head;
    node* temp1=new node(key2);
    while(true){
        if(temp->data==key1){
            temp1->neighbour=temp->neighbour;
            temp->neighbour = temp1;
            break;
        }
        if(temp->next==nullptr){break;}
        temp=temp->next;
    }
    return;
};

void graph::removeVertex(int key){
    node *temp1 = head;
    node *temp2;
    node *temp3 = nullptr;
    node *temp4;
    while(temp1!=nullptr){
        temp2=temp1->neighbour;
        if(temp1->data==key){
            while(temp1->neighbour!=nullptr){
                temp2=temp1->neighbour;
                temp1->neighbour=temp2->neighbour;
                delete[]temp2;
            }
            if(temp3==nullptr){
                head = temp2->next;
                delete[]temp2;
            }else{
                temp3->next=temp1->next;
                delete[]temp1;
            }
        }
        temp3=temp1;
        while(temp2!=nullptr){
            if(temp2->data==key){
                temp3->neighbour=temp2->neighbour;
                delete [] temp2;
                break;
            }
            temp2 = temp2->neighbour;
            temp3 = temp3->neighbour;
        }
        temp1=temp1->next;
    }
    return;
};

void graph::removeEdges(int key1, int key2){
    node *temp1 = head;
    node *temp2;
    node *temp3;
    while(true){
        if(temp1->data==key1){
            temp2=temp1->neighbour;
            temp3=temp1;
            while(true){
                if(temp2->data==key2){
                    temp3->neighbour=temp2->neighbour;
                    delete [] temp2;
                    return;
                }
                temp2 = temp2->neighbour;
                temp3 = temp3->neighbour;
            }
        }
        temp1=temp1->next;
        if(temp1==nullptr){
            break;
        }
    }
    return;
};

int graph::numVertex(){
    node * temp = head;
    int count = 0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
};

int graph::numEdges(){
    node *vertex = head;
    node *neighbour1;
    int count = 0;
    while(vertex!=nullptr){
        neighbour1=vertex->neighbour;
        while (neighbour1!=nullptr){
            count++;
            neighbour1=neighbour1->neighbour;
        }
        vertex = vertex->next;
    }
    return count;
};

int graph::indegree(int key){
    node *vertex = head;
    node *neighbour1;
    int count = 0;
    while(vertex!=nullptr){
        neighbour1=vertex->neighbour;
        while (neighbour1!=nullptr){
            if(neighbour1->data==key){
                count++;
            }
            neighbour1=neighbour1->neighbour;
        }
        vertex = vertex->next;
    }
    return count;
};

int graph::outdegree(int key){
    node *vertex = head;
    node *neighbour1;
    int count = 0;
    while(vertex!=nullptr){
        if(vertex->data==key){
            neighbour1 = vertex->neighbour;
            while(neighbour1!=nullptr){
                count++;
                neighbour1=neighbour1->neighbour;
            }
            break;
        }
    }
    return count;
};

int graph::degree(int key){
    return (this->indegree(key)+this->outdegree(key));
};

node* graph::neighbours(int key){
    node *temp = head;
    while(temp!=nullptr){
        if(temp->data==key){
            return temp->neighbour;
        }
        temp=temp->next;
    }
    return nullptr;
};

bool graph::isNeighbour(int key1,int key2){
    node* temp = head;
    while(temp!=nullptr){
        if(temp->data==key1){
            while(temp!=nullptr){
                temp=temp->neighbour;
                if(temp->data==key2){
                    return true;
                }
            }
        }
        temp=temp->next;
    }
    return false;
};