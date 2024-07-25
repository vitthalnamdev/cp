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
vector<int>adj[200010];
vector<vector<int>>dp(200010 , vector<int>(2 , 0));

int dfs(int node , int take , int parent ){

  if(dp[node][take]!=-1)return dp[node][take];
  if(dp[node][0]==-1){
    for(auto i: adj[node]){
        if(i==parent)continue;
        int curr = dfs( i , 1 , node);
        if(dp[node][0]==-1)dp[node][0] = curr;
        else dp[node][0]+=curr;
    }
  }
  if(take==1){
    int curr = 0;
    for(auto i: adj[node]){
        if(i==parent)continue;
        int now = dfs( i , 1 , node );
        int now2 = 1 + dfs( i , 0 , node);
        curr = max(curr , dp[node][0] - now + now2);
    }
    dp[node][take] = curr;
  }

  return max(dp[node][take] , 0);
}

void solve(){
 int n;cin>>n;
 for(int i=1;i<=n-1;i++){
    int a, b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
 }
 for(int i=1;i<=n;i++){
    dp[i][0] = -1;
    dp[i][1] = -1;
 }
 
 dfs(1 , 0 , -1 ); 
 dfs(1 , 1 , -1 );
 cout<<max(dp[1][0] , dp[1][1])<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}