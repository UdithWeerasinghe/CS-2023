#include <iostream>
#include <vector>

using namespace std;

// Representation of the adjacency list 
struct Node {
    int data;
    Node* next;
};

class Graph {
private:
    int numVertices;
    vector<Node*> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices, nullptr);
    }

    void addEdge(int src, int dest) {
        // Add edge from src to dest
        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // Note that : to add edge from dest to src for undirected graph uncomment the code below 
        /*
        newNode = new Node;
        newNode->data = src;
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
        */
    }

    void print() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << " connected to: ";
            Node* temp = adjList[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    // 3).Create graph object
    Graph graph(8);

    // Add edges to the graph (Fig. 1)
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 6);
    graph.addEdge(2, 3);
    graph.addEdge(3, 5);
    graph.addEdge(3, 6);
    graph.addEdge(3, 7);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(4, 7);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);

    // Print the adjacency list
    graph.print();

    return 0;
}
