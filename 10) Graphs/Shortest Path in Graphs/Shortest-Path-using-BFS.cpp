#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

void bfsShortestPath(vector<vector<int>>& adj, int source, int n) {
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    distance[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (distance[neighbor] == INT_MAX) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Shortest path from node " << source << " to node " << i << " is: ";
        if (distance[i] == INT_MAX)
            cout << "Not Reachable" << endl;
        else
            cout << distance[i] << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v format, zero-based index):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source;
    cout << "Enter source node: ";
    cin >> source;
    bfsShortestPath(adj, source, n);
    return 0;
}
