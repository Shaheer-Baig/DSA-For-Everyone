#include <iostream>
#include <vector>
using namespace std;

bool CycleDetect(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int j = 0; j < adj[node].size(); j++) {
        if (adj[node][j] == parent)  //Skip the parent node
            continue;
        if (visited[adj[node][j]])  //If the adjacent node is already visited, cycle is detected
            return true;
        if (CycleDetect(adj[node][j], node, adj, visited))  //Recursively call DFS for all neighbors until no neighbor is left 
            return true;
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);  

    //Check for cycle in each component (if graph is disconnected)
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {  //If this node hasn't been visited start DFS from here
            if (CycleDetect(i, -1, adj, visited)) {  // -1 indicates no parent for the starting node
                return true;  //Cycle found
            }
        }
    }

    return false;  //No cycle found in any component
}

int main() {
    int V = 4;  //Number of vertices
    vector<vector<int>> adj(V);  //Adjacency list

    //Adjacency list for the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    //Check for cycle in the graph
    if (isCycle(V, adj)) {
        cout << "Cycle detected!" << endl;
    }
    else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
