
class Node
{
public:
    Node *next;
    int data;
    Node *neighbour;
    Node(int key = 0, Node *node1 = nullptr, Node *node2 = nullptr)
    {
        data = key;
        next = node1;
        neighbour = node2;
    }
};

class graph
{
public:
    Node *HEAD;
    bool directed;

    graph(Node *Node = nullptr, bool direction = true) : HEAD(Node), directed(direction) {}

    bool isEmpty();
    bool isDirected();
    void addVertex(int vertexToAdd);
    void addEdges(int ver1, int ver2);
    void removeVertex(int vertexToRemove);
    void removeEdges(int ver1, int ver2);
    int numVertex();
    int numEdges();
    int indegree(int ver);
    int outdegree(int ver);
    int degree(int ver);
    Node *neighbours(int ver);
    bool isNeighbour(int ver1, int ver2);
};