#include <iostream>
using namespace std;

#define V 6 
#define INF 999999 

int minDistance(int dist[], bool visited[]) {
int min = INF, min_index;
for (int v = 0; v < V; v++)
if (!visited[v] && dist[v] <= min) {
min = dist[v];
min_index = v;
}
return min_index;
}

void printSolution(int dist[]) {
cout << "Vertex \tDistance from Source\n";
for (int i = 0; i < V; i++)
cout << i << "\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src) {
int dist[V]; 
bool visited[V]; 

for (int i = 0; i < V; i++) {
dist[i] = INF;
visited[i] = false;
}

dist[src] = 0;

for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, visited);
visited[u] = true;

for (int v = 0; v < V; v++) {
if (!visited[v] && graph[u][v] && dist[u] != INF &&
dist[u] + graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v];
}
}
}
printSolution(dist);
}
int main() {
int graph[V][V] = {
{0, 4, 0, 0, 0, 0},
{4, 0, 8, 0, 0, 0},
{0, 8, 0, 7, 0, 4},
{0, 0, 7, 0, 9, 14},
{0, 0, 0, 9, 0, 10},
{0, 0, 4, 14, 10, 0}
};
int source;
cout << "Enter source vertex (0 to " << V-1 << "): ";
cin >> source;
cout << "\nShortest paths from vertex " << source << ":\n";
dijkstra(graph, source);
return 0;
}
	

