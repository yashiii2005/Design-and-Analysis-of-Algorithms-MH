#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;

    // Utility function for DFS
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i : adj[v]) {
            if (!visited[i])
                DFSUtil(i, visited);
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // DFS traversal starting from v
    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2);
    cout << endl;

    return 0;
}

