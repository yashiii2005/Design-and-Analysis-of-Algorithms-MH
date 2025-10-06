#include <iostream>
#include <queue>
using namespace std;

#define N 5  // Number of nodes in the graph

// Function to display graph data using BFS traversal
void bfs(int start, int graph[N][N]) {
    bool visited[N] = {false}; // Track whether a node has been visited
    queue<int> q;              // Queue to maintain BFS order

    visited[start] = true;     // Mark the start node as visited
    q.push(start);             // Enqueue the start node

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();  // Get node from the front of the queue
        q.pop();               // Remove it from the queue

        // Display the node (shows the data stored in graph)
        cout << node << " ";

        // Check all possible neighbors
        for (int i = 0; i < N; i++) {
            // If there is an edge and neighbor is not visited
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true; // Mark neighbor visited
                q.push(i);         // Enqueue neighbor
            }
        }
    }
    cout << endl;
}

int main() {
    // Adjacency matrix representing the graph
    int graph[N][N] = {
        {0, 1, 1, 0, 0}, // edges from node 0
        {1, 0, 0, 1, 0}, // edges from node 1
        {1, 0, 0, 0, 1}, // edges from node 2
        {0, 1, 0, 0, 0}, // edges from node 3
        {0, 0, 1, 0, 0}  // edges from node 4
    };
    /*
      Graph structure:
        0 -- 1 -- 3
        |    |
        2 -- 4
    */

    // Display the stored data in the graph (via BFS traversal)
    bfs(0, graph); // Starting BFS from node 0

    return 0;
}

