#include <iostream>

using namespace std;

// Class to implement list based graph
class Graph
{
private:
    class List
    {
    public:
        struct Node
        {
            char vertex;
            Node *next;
        };
        Node *head;

        List()
        {
            head = NULL;
        }

        // Adds a vertex to the list
        void addVertex(char vertex)
        {
            Node *newNode = new Node;
            newNode->vertex = vertex;
            newNode->next = head;
            head = newNode;
        }

        // Removes a vertex from beginning of the list
        char removeVertex()
        {
            if (head == NULL)
                return char();

            int vertex = head->vertex;
            Node *temp = head;
            head = head->next;
            delete temp;
            return vertex;
        }

        // Removes a vertex from end of the list
        char removeVertexEnd()
        {
            if (head == NULL)
                return char();

            if (head->next == nullptr)
            {
                char value = head->vertex;
                delete head;
                head = nullptr;
                return value;
            }

            Node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;

            char vertex = temp->next->vertex;
            Node *temp2 = temp->next;
            temp->next = NULL;
            delete temp2;
            return vertex;
        }

        // Returns true if the list is empty
        bool isEmpty()
        {
            return head == NULL;
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
    void addEdge(char v, char w)
    {
        adj[v - 'A'].addVertex(w);
    }

    // Prints the path from one vertex to another using BFS
    void BFS(char start, char end)
    {
        cout << "BFS: ";
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        visited[start - 'A'] = true;
        List queue;
        queue.addVertex('A');
        while (!queue.isEmpty())
        {
            char u = queue.removeVertex();
            cout << u << " -> ";
            if (u == end)
            {
                delete[] visited;
                cout << endl
                     << endl;
                return;
            }
            List::Node *temp = adj[u - 'A'].head;
            while (temp)
            {
                if (!visited[temp->vertex - 'A'])
                {
                    visited[temp->vertex - 'A'] = true;
                    queue.addVertex(temp->vertex);
                }
                temp = temp->next;
            }
        }
    }

    // Prints the path from one vertex to another using DFS
    void DFS(char start, char end)
    {
        cout << "DFS: ";
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        visited[start - 'A'] = true;
        List stack;
        stack.addVertex('A');
        while (!stack.isEmpty())
        {
            char u = stack.removeVertexEnd();
            cout << u << " -> ";
            if (u == end)
            {
                delete[] visited;
                cout << endl
                     << endl;
                return;
            }
            List::Node *temp = adj[u - 'A'].head;
            while (temp)
            {
                if (!visited[temp->vertex - 'A'])
                {
                    visited[temp->vertex - 'A'] = true;
                    stack.addVertex(temp->vertex);
                }
                temp = temp->next;
            }
        }
    }

    // Prints the adjacency list of the graph
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            if (adj[i].isEmpty())
                continue;

            cout << "Adjacency list of vertex " << char(i + 'A') << " -> ";
            adj[i].print();
        }
        cout << endl;
    }
};

int main()
{
    Graph graph(13);

    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('B', 'D');
    graph.addEdge('B', 'E');
    graph.addEdge('D', 'G');
    graph.addEdge('D', 'H');
    graph.addEdge('G', 'K');
    graph.addEdge('G', 'L');
    graph.addEdge('E', 'I');
    graph.addEdge('I', 'M');
    graph.addEdge('C', 'F');
    graph.addEdge('F', 'J');

    graph.BFS('A', 'G');
    graph.DFS('A', 'G');

    graph.print();

    return 0;
}
