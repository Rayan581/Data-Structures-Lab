#include <iostream>

using namespace std;

// Class to implement list based graph
class Graph
{
private:
    class List
    {
    private:
        struct Node
        {
            int vertex;
            Node *next;
        };
        Node *head;

    public:
        List()
        {
            head = NULL;
        }

        // Adds a vertex to the list
        void addVertex(int vertex)
        {
            Node *newNode = new Node();
            newNode->vertex = vertex;
            newNode->next = head;
            head = newNode;
        }

        // Prints the list
        void print()
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->vertex;
                if (temp->next)
                    cout << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    };

    int V;     // Number of vertices
    List *adj; // Array of adjacency lists

public:
    Graph(int v)
    {
        V = v;
        adj = new List[V];
    }

    // Adds an edge to the graph
    void addEdge(int v, char w)
    {
        adj[v - 1].addVertex(w);
        adj[w - 1].addVertex(v);
    }

    // Prints the adjacency list of the graph
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Adjacency list of vertex " << (i + 1) << " -> ";
            adj[i].print();
        }
        cout << endl;
    }
};

int main()
{
    // {{1, 2},
    //  {2, 3},
    //  {4, 5},
    //  {1, 5},
    //  {6, 1},
    //  {7, 4},
    //  {3, 8}};

    Graph graph(8);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(4, 5);
    graph.addEdge(1, 5);
    graph.addEdge(6, 1);
    graph.addEdge(7, 4);
    graph.addEdge(3, 8);

    graph.print();

    return 0;
}
