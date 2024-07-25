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
vector<int>dp(200005 , 0 );
vector<int>vis(200005 , 0);
void dfs(int node , vector<int>adj[]){
 vis[node] = 1;
 for(auto i: adj[node]){
    if(!vis[i]){
        dfs(i  , adj);
        dp[node] += dp[i] + 1;
    }
 }
}
void solve(){
   int n;cin>>n;
   int arr[n+1];
   for(int i=2;i<=n;i++)cin>>arr[i];
   vector<int>adj[n+1];
   for(int i=2;i<=n;i++){
     adj[arr[i]].push_back(i);
   }
   dfs(1 , adj);
   for(int i=1;i<=n;i++){
    cout<<dp[i]<<" ";
   }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}


