#include<bits/stdc++.h>
using namespace std;

void IS_BRIDGE(int v,int to); // some function to process the found bridge
int n; // number of nodes
vector<int> adj[200005]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (auto to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main(){
     cin>>n; 
     int m;cin>>m;
     for(int i=0;i<m;i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
     }
     find_bridges();

}

void IS_BRIDGE(int v,int to){
     cout<<v<<" "<<to<<endl;
}