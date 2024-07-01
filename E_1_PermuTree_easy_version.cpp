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
ll vertex[5001];
vector<int>adj[5001];
int vis[5001];
ll ans = 0;
void dfs(int node){
  vis[node] = 1;
  vertex[node] = 0;
  vector<ll>versums;
  for(auto i:adj[node]){
    if(!vis[i]){
       dfs(i);
       vertex[node] +=vertex[i];
       versums.push_back(vertex[i]);
    }
  }
  int sz = versums.size();
  ll dp[sz+1][vertex[node]+5];
  
  for(int i=0;i<=vertex[node];i++){
    dp[0][i] = i*(vertex[node]-i);
  }
  
   for(int i=1;i<=sz;i++){
    for(int j=0;j<=vertex[node];j++){
        dp[i][j] = max(dp[i-1][j] , (j+versums[i-1]<=vertex[node]?dp[i-1][j+versums[i-1]]:0));
    }
}
 
  vertex[node]++;
   ans+=(dp[sz][0]);
}
void solve(){
int n;cin>>n;
for(int i=2;i<=n;i++){
  int x;cin>>x;
  adj[x].push_back(i);
  adj[i].push_back(x);
}
dfs(1);
 
cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}