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
vector<int>adj[100005];
int vis[100005];
int dp[100005];
void dfs(int node){
  vis[node] = true;
  for(auto i: adj[node]){
     if(!vis[i]){
       dfs(i);
       dp[node] = max(dp[node] , dp[i] + 1);
     }else{
        dp[node] = max(dp[node] , dp[i]+1);
     }
  }
}
void solve(){
 int n,m;cin>>n>>m;
 for(int i=0;i<m;i++){
   int a, b;cin>>a>>b;
   adj[a].push_back(b);
 }
 for(int i = 1; i <=n;i++){
    if(!vis[i]){
        dfs(i);
    }
 }
 int answer = 0;
 for(int i= 1;i<=n;i++)answer = max(answer , dp[i]);
 cout<<answer<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}