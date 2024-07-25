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
vector<ll>adj[200010];
vector<ll>dp(200010);
vector<ll>ans(200010);
vector<ll>Count(200010 , 1);
int  dfs(int node , int parent){
    if(dp[node]!=0)return dp[node];
   
    for(auto i: adj[node]){
        if(i==parent)continue;
        dfs(i , node);
       Count[node] += Count[i] ;
       dp[node] += (dp[i] + Count[i]);
    }
    return dp[node] ;
}
void dfs2(int node , int parent){
 
    if(parent==-1)ans[node] = dp[node];
    else
     {
        ll temp = Count[node] ;
        ans[parent] -= (dp[node] + Count[node]);
        Count[parent] -= (Count[node]);
        ans[node] = dp[node] + ans[parent] + Count[parent];
        Count[node] += Count[parent];
        ans[parent] += (dp[node] + temp);
        Count[parent] += temp;
     }
     for(auto i: adj[node]){
        if(i==parent){continue;}
        dfs2(i , node);
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
  dfs2(1 , -1 );
  
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t = 1;
while(t--){
solve();
}
}
  
 