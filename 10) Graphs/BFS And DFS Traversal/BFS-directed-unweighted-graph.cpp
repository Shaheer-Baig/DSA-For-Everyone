#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform BFS traversal of a graph
vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
    queue<int> q;
    q.push(0);  //Start BFS from node 0
    vector<bool> visted(V, 0);  //To keep track of visited nodes
    visited[0] = 1;

    vector<int> ans;
    int node;
    while (!q.empty()) {  
        node = q.front();
        q.pop();
        ans.push_back(node);  //visted element pushed in queue

        //Loop to check the adjacent of current node
        //row we know column check karay ga adjacent
        for (int j = 0; j < adj[node].size(); j++) {
            if (!visited[adj[node][j]]) {  // If adjacent node not visited
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;  // Return the BFS result
}

int main() {
    int V = 9;  
    vector<vector<int>> adj(V);  //Adjacency list

    //adjacency list given by user 
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(5);
    adj[1].push_back(7);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[5].push_back(6);
    adj[7].push_back(8);

    vector<int> result = bfsOfGraph(V, adj);

    //Print the result
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
