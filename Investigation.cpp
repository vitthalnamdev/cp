#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
vector<pair<int,int>>adj[100005];
ll dist[100005];
int vis[100005];
int mnfli[100005];
int mxfli[100005];
ll ways[100005];
int mod = 1e9+7;
void shortest_path(){
  set<pair<ll,ll>>s;
  s.insert({0,1});
  while(!s.empty()){
    auto top = *s.begin();
    s.erase(s.begin());
    if(vis[top.second]){
      continue;
    }
    vis[top.second] = 1;
   for(auto i:adj[top.second]){
       if(dist[i.first]>i.second + top.first){
          mnfli[i.first] =  mnfli[top.second]+1;
          mxfli[i.first] =  mxfli[top.second]+1;
          ways[i.first] = ways[top.second];
          ways[i.first] %=mod;
       }
      if(dist[i.first]==i.second + top.first){
         mnfli[i.first] = min(mnfli[i.first] , mnfli[top.second] + 1);
          mxfli[i.first] = max(mxfli[i.first] , mxfli[top.second] + 1);
          ways[i.first] += ways[top.second];
          ways[i.first] %=mod;

       }
       if(dist[i.first] > i.second + top.first){
          dist[i.first] = i.second + top.first;
          s.insert({dist[i.first],i.first}); 
       }
    }
  }
}


void solve(){
  int n,m;cin>>n>>m;
  for(int i=0;i<=n;i++)dist[i]=LLONG_MAX,mnfli[i]=INT_MAX;
  dist[1]=0;mnfli[1]=0;
  ways[1] = 1;
  for(int i=0;i<m;i++){
    int a, b, c;cin>>a>>b>>c;
    adj[a].push_back(make_pair(b,c));
  }
  shortest_path();
 // cout<<dist[7]<<endl;
  //cout<<ways[7]<<endl;
  cout<<dist[n]<<" "<<ways[n]<<" "<<mnfli[n]<<" "<<mxfli[n]<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}