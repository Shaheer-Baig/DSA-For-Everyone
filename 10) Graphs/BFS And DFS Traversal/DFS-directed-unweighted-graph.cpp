#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//Function to perform DFS from a given node
void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited) {
    visited[node] = 1;  //Mark the node as visited
    ans.push_back(node);  //Add the node to the result

    //Explore all adjacent nodes
    for (int j = 0; j < adj[node].size(); j++) {
        if (!visited[adj[node][j]]) {  // If the adjacent node is not visited
            DFS(adj[node][j], adj, ans, visited);
        }
    }
}

//Function to perform DFS traversal of a graph
vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, 0);//initially marked all the verteces 0
    vector<int> ans;  //To store the DFS result
    DFS(0, adj, ans, visited);  //Start DFS from node 0
    return ans;
}

int main() {
    int V = 9;  
    vector<vector<int>> adj(V);  // Adjacency list

    // Adjacency list given by user
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(5);
    adj[1].push_back(7);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[5].push_back(6);
    adj[7].push_back(8);

    vector<int> result = dfsOfGraph(V, adj);

    // Print the DFS result
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
