#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii; //(weight, node)

//Function to find the Minimum Spanning Tree using Prim's Algorithm
void primMST(int n, vector<vector<pii>>& graph) {
    vector<bool> inMST(n, false);   //Track nodes included in MST
    vector<int> key(n, numeric_limits<int>::max());  //Store min weights
    vector<int> parent(n, -1);  //Store MST structure
    priority_queue<pii, vector<pii>, greater<pii>> pq;  //Min-heap for edges

    key[0] = 0;   //Start from node 0
    pq.push(make_pair(0, 0));  //Push (weight, node)

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (size_t i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].second;
            int weight = graph[u][i].first;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    //Print MST edges
    cout << "Minimum Spanning Tree (MST) Edges:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
            totalWeight += key[i];
        }
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);

    cout << "Enter " << m << " edges in format (u v weight) [0-based index]:\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(weight, v));
        graph[v].push_back(make_pair(weight, u));
    }

    primMST(n, graph);
    return 0;
}
