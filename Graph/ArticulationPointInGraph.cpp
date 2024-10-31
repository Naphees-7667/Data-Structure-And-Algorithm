#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int>& vis,int tin[],int low[],vector<int>& mark,vector<int> adj[],int& timer){
    vis[node] = 1;
    tin[node] = low[node] = ++timer;
    int child = 0;
    for(auto it : adj[node]){
        if(it == parent)continue;
        if(!vis[it]){
            dfs(it,node,vis,tin,low,mark,adj,timer);
            low[node] = min(low[node],low[it]);
            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node],tin[it]);
        }
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
    return;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        vector<int> adj[N];
        for(int i=1;i<=M;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<int> visited(N,0);
        vector<int> mark(N,0);
        int tin[N];
        int low[N];
        int timer = 0;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i,-1,visited,tin,low,mark,adj,timer);
            }
        }
        int cnt = 0;
        for(int i=0;i<N;i++){
            if(mark[i] == 1){
                cout<<i+1<<" ";
                cnt++;
            }
        }
        if(cnt == 0){
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}