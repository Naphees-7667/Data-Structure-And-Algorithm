#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<vector<int>> &bridge) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (auto it : adj[node]) {
        if (it == parent) continue;
        
        if (!vis[it]) { 
            dfs(it, node, vis, adj, tin, low, bridge);
            low[node] = min(low[node], low[it]);

            // Check if it forms a bridge
            if (low[it] > tin[node]) {
                bridge.push_back({node, it});
            }
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }
}

int main() {
    int V = 12 , E = 14;

    vector<int> adj[V] = {{1,3}, {0,2}, {1,3}, {0,2,4}, {3,5}, {4,6,8}, {5,7}, {6,8,9}, {5,7}, {7,10,11}, {9,11}, {9,10}};

    vector<int> tin(V, -1);
    vector<int> low(V, -1);
    vector<int> vis(V, 0);
    vector<vector<int>> bridge;

    // Run DFS for each component (in case the graph is disconnected)
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, adj, tin, low, bridge);
        }
    }

    // Output all bridges found
    cout << "Bridges in the graph are:\n";
    for (auto it : bridge) {
        cout << it[0] << " - " << it[1] << "\n";
    }

    return 0;
}