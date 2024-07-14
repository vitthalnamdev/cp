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
int last;
int len;
bool ans = false;
bool dfs(int node, int k , vector<int>&vis1 , vector<int>&vis2 , vector<int>adj[]){
   
  vis1[node] = 1; vis2[node] = 1;
  bool now = 0;
  for(auto i: adj[node]){
    if(!vis1[i]){
     now |=  dfs(i , k , vis1, vis2 , adj);
    }else if(vis1[i] && vis2[i]){
       last = i; now=1;
    }
   }
  vis2[node]= 0;
  if(now){len++;
      if(node==last){
         last = 0;now =0; 
         ans = (len!=k);
         len = 0;
      }
  }
   return now;
}

void solve(){
   ans = 0;last = 0 ;len = 0;
   int n;cin>>n;int k;cin>>k;    
   int arr[n+1];
   for(int i=1;i<=n;i++)cin>>arr[i];
  if(k==1){
    for(int i=1;i<=n;i++){
      if(arr[i]!=i){cout<<"NO"<<endl;return;}
    }     
    cout<<"YES"<<endl;return;
  }
   vector<int>adj[n+1];
   for(int i=1;i<=n;i++){
      adj[i].push_back(arr[i]);
   }
   vector<int>vis1(n+1,0);
   vector<int>vis2(n+1,0);
    
   for(int i=1;i<=n;i++){
    if(!vis1[i]){
       dfs(i,k,vis1,vis2, adj);
      if(ans==true){
       //ans = true when len%k!=0
       break;
      }
    }
   }
   if(ans){
    cout<<"NO"<<endl;
}else cout<<"YES"<<endl;
    
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}