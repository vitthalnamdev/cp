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
void solve(){
   int n;cin>>n;int curr = 2;
   vector<pair<int,int>>f(n+10);
   int state[n+10][2];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=1;j++){
         state[i][j] = 0;
       }
    }
    state[1][0] = 0;state[1][1] = 1;
   f[1].first = 0;f[1].second = 1;
   for(int i=0;i<n;i++){
       char a;cin>>a;
       if(a=='+'){
          int v , w;cin>>v>>w;
          if(w==1){
              state[curr][0] = min(0,state[v][0] + 1);
              state[curr][1] = state[v][1] + 1;
          }else{
             
              state[curr][1] = max(0,state[v][1] - 1);
              state[curr][0] = state[v][0] - 1;
          }
          f[curr].first = min(state[curr][0] , f[v].first );
          f[curr].second = max(state[curr][1] , f[v].second );
          curr++;
       }else{
           int u, v,k;cin>>u>>v>>k;	
           if(f[v].first<=k && f[v].second>=k){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
       }
   }
   
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}