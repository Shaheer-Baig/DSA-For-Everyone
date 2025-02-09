#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> pii;

void bfsShortestPath(vector<vector<pii>>& adj, int source, int n) {
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    distance[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neighbor : adj[node]) {
            int v = neighbor.first, weight = neighbor.second;
            if (distance[node] + weight < distance[v]) {
                distance[v] = distance[node] + weight;
                q.push(v);
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
    vector<vector<pii>> adj(n);
    cout << "Enter edges (u v w format, zero-based index):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }
    int source;
    cout << "Enter source node: ";
    cin >> source;
    bfsShortestPath(adj, source, n);
    return 0;
}
