#include<bits/stdc++.h>
using namespace std;
#define ll long long
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9+7;
ll inv(ll a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)

void shortest_path(ll dist[] , int id , vector<int>adj[] , int n , ll factor[] , vector<vector<ll>>&weight){
  set<pair<ll,ll>>s;
  vector<ll>dist2(n+1,LLONG_MAX);
  vector<ll>newfactor(n+1);
  for(int i=1;i<=n;i++)newfactor[i] = factor[i];
  s.insert({dist[id] , id});
  dist2[id] = dist[id];
  vector<int>vis(n+1,0);
  while(!s.empty()){
    auto top = *s.begin();
    s.erase(s.begin());
    if(vis[top.second]){continue;}
    vis[top.second] = 1;
    for(auto j:adj[top.second]){
        if(dist2[j] > dist2[top.second] + weight[j][top.second]*newfactor[top.second]){
            dist2[j] = dist2[top.second] + weight[j][top.second]*newfactor[top.second];
            newfactor[j] = min(newfactor[j],newfactor[top.second]);
            s.insert({dist2[j], j});
        }
    }
  }
  for(int i=1;i<=n;i++){
    dist[i] = min(dist[i] , dist2[i]);
  }
}
void solve(){
    ll n;cin>>n;
    ll m;cin>>m;
    vector<vector<ll>>weight(n+1 , vector<ll>(n+1));
    ll dist[n+1];   
    for(int i=1;i<=n;i++){
      dist[i] = 1e15;
    }    
    dist[1] = 0;
    vector<int>adj[n+1];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            weight[i][j] = INT_MAX;
        }
    }
    for(int i=0;i<m;i++) {
        ll a, b, c;cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weight[a][b] = min(weight[a][b] , c);
        weight[b][a] = min(weight[b][a] , c);
    }
    ll s[n+1];
    for(int i=1;i<=n;i++)cin>>s[i];
     
    int vis[n+1];
    for(int i=1;i<=n;i++){
        vis[i] = 0;
    }
    for(int i=1;i<=n;i++){
        int id = 0;ll mn = LLONG_MAX;
        for(int j=1;j<=n;j++){
            if(vis[j]==0 && dist[j]<=mn){
                 id = j; mn = dist[j];
            }
        }
        vis[id] = 1;
        if(id!=0)
       shortest_path(dist , id , adj , n , s , weight);
    }

    cout<<dist[n]<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
        solve();
    }
}