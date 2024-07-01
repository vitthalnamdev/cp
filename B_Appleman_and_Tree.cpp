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
const int mx = 1e5 + 5;
vector<int>adj[mx] , color(mx);
vector<int>vis(mx, 0);
vector<array<ll,2>>dp(mx);
void dfs(int node){
    vis[node] = 1;
    dp[node][0] = 1;dp[node][1] = 0;
    for(auto i:adj[node])
    {
        if(!vis[i]){
          dfs(i);
          
          dp[node][1]  = (dp[node][1] * ((dp[i][0] + dp[i][1])%mod))%mod;
          dp[node][1]  = (dp[node][1]  +  (dp[node][0]*dp[i][1])%mod)%mod; 
          dp[node][0] = (dp[node][0] * (dp[i][0] + dp[i][1])%mod)%mod;
        }
    }
    if(color[node]){
        dp[node][1] = dp[node][0];
        dp[node][0]  = 0;
    }
}

void solve(){
int n;cin>>n;
for(int i=1;i<n;i++){
    int x;cin>>x;
    adj[x].push_back(i);
    adj[i].push_back(x);
}
for(int i=0;i<n;i++){
    cin>>color[i];
}
dfs(0);
cout<<dp[0][1]<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}