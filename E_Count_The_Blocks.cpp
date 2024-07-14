#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod =998244353;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
ll n;cin>>n;
ll power[200005];
power[0] = 1;
for(int i=1;i<=n;i++){power[i]=power[i-1]*10LL; power[i]%=mod;}
for(int i=1;i<=n-1;i++){ 
  ll curr = 2*10LL*9*(power[n-i-1]);
  curr%=mod;
  curr+=((n-i-1)*((10LL*9*9*power[n-i-2])%mod));
  curr%=mod;
  cout<<curr<<" ";
}
cout<<10<<" ";
//for(int i=1;i<=n;i++){cout<<count[i]<<" ";}cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}