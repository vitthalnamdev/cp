#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
// int mod = 1e9+7;
// ll inv(ll a) {
// return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
// }
// #define cntone(x) __builtin_popcountll(x)
// #define trailzero(x) __builtin_clzll(x)
// #define trailone(x) __builtin_ctzll(x)
vector<int>adj[200010];
vector<int>dp(200010);
vector<int>ans(200010);
int  dfs(int node , int parent ){
    if(dp[node]!=0)return dp[node];
    int curr = 0;
    for(auto i: adj[node]){
        if(i==parent)continue;
        curr = max( curr , 1 + dfs( i , node)) ;
    }
    return dp[node] = curr;
}
void dfs2(int node , int parent){
 
    if(parent==-1)ans[node] = dp[node];
    else
    ans[node] = max( dp[node] ,1 +  dp[parent]);
    vector<int>check;
    for(auto i: adj[node]){
       int now = dp[i] + 1;
       
       check.push_back(now);
    }
    sort(check.begin() , check.end());

    int sz = check.size()-1;
    for(auto i: adj[node]){
        int temp = dp[node];
        if(dp[i] == check[sz]-1){
          dp[node] = (sz-1>=0?check[sz - 1]:0);
        
        }else dp[node] = check[sz];
        if(i==parent)continue;
        dfs2(i , node );
        dp[node] = temp;
    }
}
void solve(){
 int n;cin>>n;
 for(int i=1;i<n;i++){
    int a , b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
 }
  dfs(1 , -1);
  dfs2(1 , -1);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t = 1;
while(t--){
solve();
}
}