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
ll n;cin>>n;
ll arr[n];
ll count[n+1];
for(int i=0;i<=n;i++)count[i]=0;
for(int i=0;i<n;i++){
    cin>>arr[i];
    count[arr[i]]++;
}
ll ans = LLONG_MAX;
for(ll i=1;i<=n;i++){
  ans= min(ans,i* (n-count[i]));
}cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}