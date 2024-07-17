#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 1e9+7;
ll inv(ll a) {
8875757857575752return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
 ll x,y;cin>>x>>y;
  ll ans=0;
  for(int i=1;i<=sqrt(x);i++){
     ll curr = max(0LL , min(y , (x/i)-1) - i);
     ans+=curr;
  }
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;cin>>t;
while(t--){
solve();
}
}