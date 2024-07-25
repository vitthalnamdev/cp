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
int ans = 0;
int  dfs(int node , int parent ){
        
   vector<int>check;
   for(auto i: adj[node]){
     if(i==parent){continue;}  
     int now = 1 + dfs(i , node);
     check.push_back(now);
   }
    
   if(check.size()<=1){
      if(check.size()==0)return 0;
      else{
        ans = max(ans , check[0]);
        return check[0]  ;
      }
   }
   sort(check.begin(), check.end());
   int sz = check.size()-1;
   ans = max( ans , check[sz] + check[sz-1]  );
   return check[sz];
}
void solve(){
 int n;cin>>n;
 for(int i=0;i<n-1;i++){
    int a , b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
 }
 dfs(1 , -1 );
 cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}