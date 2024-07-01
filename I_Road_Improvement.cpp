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
vector<pair<int,int>>adj[200005];
void solve(){
 int n;cin>>n;
  
 for(int i=1;i<n;i++){
  int a, b;cin>>a>>b;
  adj[a].push_back({b,i});
  adj[b].push_back({a,i});
 }
 
 vector<vector<int>>ans;int sz= 0;
 set<int>prs[n+1];
 int vis[n+1];
 for(int i=1;i<=n;i++)vis[i]=0;
  
 for(int i=1;i<=n;i++){
    int k= 0;
  for(auto j:adj[i]){
     
     if(vis[j.second]==0){
        vis[j.second]=1;
        while(k<sz && (prs[k].find(i)!=prs[k].end() || prs[k].find(j.first)!=prs[k].end()))k++;
        if(k>=sz){
            vector<int>temp;
            ans.push_back(temp);
            sz = ans.size();
        }
        prs[k].insert(i);
        prs[k].insert(j.first);
        ans[k].push_back(j.second);
        k=0;
     } 
   }
 }
  
 cout<<ans.size()<<endl;
 for(auto i:ans){
    cout<<i.size()<<" ";
    for(auto j:i){
        cout<<j<<" ";
    }cout<<endl;
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}