// Diameter - Number of edges in the longest path in the graph/tree from any node to any other node

// ! Concept - 
// If you choose a random node (U) and find the farthest node (V) from (U), then this node (V) will always be one end of the diameter of the graph.

// The Farthest node from one end of the diameter is the other end of the diameter.

// (1) U  ------Fathest-----> A/B
// (2) B  ------Guaranteed -----> one end of the diameter 
// (3) B  ------Farthest-----> A (diameter ka dusra end)


#include<bits/stdc++.h>
using namespace std;
class Solution {

    pair<int,int> BFS_Traversal(unordered_map<int, vector<int>>& adj,int source){

        queue<int> q;

        q.push(source);

        int lastNode = source;

        unordered_map < int , bool > visited;

        visited[source] = true;

        int distance = 0;

        while(!q.empty()){

            int size = q.size();

            while(size -- ){

                int node = q.front();

                q.pop();

                lastNode = node;

                for(auto &nbr : adj[node]){

                    if(visited[nbr] == false){

                        visited[nbr] = true;

                        q.push(nbr);

                    }

                }

            }

            if(!q.empty()){
                distance++;
            }

        }

        return {lastNode , distance};
    }


    int findDiameter(unordered_map<int, vector<int>>& adj){

        auto [oneEndOfDiameter , dist] = BFS_Traversal(adj,0);

        auto [anotherEndOfDiameter , Diameter] = BFS_Traversal(adj,oneEndOfDiameter);

        return Diameter;
    }

    unordered_map<int, vector<int>> buildAdjacency(vector<vector<int>>& edges){

        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;

    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {


        unordered_map<int, vector<int>> adj1 = buildAdjacency(edges1);

        unordered_map<int, vector<int>> adj2 = buildAdjacency(edges2);

        int diameterA =  findDiameter(adj1);

        int diameterB = findDiameter(adj2);

        int combined = (diameterA + 1)/2 + (diameterB + 1)/2 + 1;

        return max({diameterA , diameterB, combined});

    }

};