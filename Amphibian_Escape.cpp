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
ll n, h, k;cin>>n>>k>>h;
 ll ans = 0;
 ll val = h/k;
 ll rem = h%k;
 for(int i=n;i>=1;i--){
     if(i>=h){
        ans+=(n);
     }else{
        ll j =  h - i;
        int rem = (j%(k-1));
        rem  = rem > 0;
        ll l = i - j / (k- 1 ) - rem ;
 
        l= max(l,0LL);
        ans+=l; 
     }
 }
 cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}