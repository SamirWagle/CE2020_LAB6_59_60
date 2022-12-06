
class node
{
public:
    node *next;
    int data;
    node *neighbour;
    node(int key = 0, node *node1 = nullptr, node *node2 = nullptr)
    {
        data = key;
        next = node1;
        neighbour = node2;
    }
};

class graph
{
public:
    node *head;
    bool directed;

    graph(node *node = nullptr, bool direction = true) : head(node), directed(direction) {}

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
    node *neighbours(int ver);
    bool isNeighbour(int ver1, int ver2);
};