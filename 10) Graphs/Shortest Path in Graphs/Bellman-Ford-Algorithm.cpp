#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, int m, vector<Edge>& edges, int source) {
    vector<int> distance(n, numeric_limits<int>::max());
    distance[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            if (distance[edge.u] != numeric_limits<int>::max() &&
                distance[edge.u] + edge.weight < distance[edge.v]) {
                distance[edge.v] = distance[edge.u] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {
        if (distance[edge.u] != numeric_limits<int>::max() &&
            distance[edge.u] + edge.weight < distance[edge.v]) {
            cout << "Negative weight cycle detected!" << endl;
            return;
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
    vector<Edge> edges(m);

    cout << "Enter " << m << " edges in format (u v w) [0-based index]:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    bellmanFord(n, m, edges, source);
    return 0;
}
