#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

//Comparator function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

//Disjoint Set Union (DSU) with Path Compression & Union by Rank
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  //Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges); //Sort edges by weight
    DSU dsu(n);
    vector<Edge> mst;
    int mstWeight = 0;

    for (auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) { //Check if adding edge creates a cycle
            dsu.unite(edge.u, edge.v);
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }

    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (auto& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    cout << "Total MST Weight: " << mstWeight << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges in format (u v weight) [0-based index]:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskalMST(n, edges);
    return 0;
}
