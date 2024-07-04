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
vector<vector<int>>ans(200005);
vector<int>vis(200005 , 0 );
int sze = 0;
void dfs(int node , int parent  , int previd ){
  vis[node] = 1;
  int id = 0;
  
  for(auto i:adj[node]){
	 
     if(i.first==parent || vis[i.first]){continue;}
	 if(id==previd)id++;
	 ans[id].push_back(i.second);
     dfs(i.first,node , id);
	 id++;
  }
  sze = max(sze, id);
}
void solve(){
  int n;cin>>n;
  for(int i=1;i<=n-1;i++){
     int a, b;cin>>a>>b;
	 adj[a].push_back({b,i});
	 adj[b].push_back({a,i});
  }
  
  dfs(1 , -1 , -1);
  cout<<sze<<endl;
  for(int i=0;i<sze;i++){
	cout<<ans[i].size()<<" ";
	for(int j=0;j<ans[i].size();j++){
		cout<<ans[i][j]<<" ";
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