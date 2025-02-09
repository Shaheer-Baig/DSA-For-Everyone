#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii;

void dijkstraShortestPath(const vector<vector<pii>>& adj, int source, int n) {
    vector<int> distance(n, numeric_limits<int>::max());
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distance[source] = 0;
    pq.push({ 0, source });

    while (!pq.empty()) {
        int dist = pq.top().first, node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue;

        for (const auto& neighbor : adj[node]) {
            int v = neighbor.first, weight = neighbor.second;
            if (distance[node] + weight < distance[v]) {
                distance[v] = distance[node] + weight;
                pq.push({ distance[v], v });
            }
        }
    }

    cout << "Shortest path distances from source node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To node " << i << ": ";
        if (distance[i] == numeric_limits<int>::max())
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

    cout << "Enter " << m << " edges in format (u v w) [0-based index]:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstraShortestPath(adj, source, n);
    return 0;
}
