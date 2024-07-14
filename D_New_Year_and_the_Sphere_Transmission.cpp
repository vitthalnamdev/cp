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
 int n;cin>>n;
 set<ll>ans;
 for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
        ll now = n/i;
        ll sum = ((2*1 + (now-1)*i)*(now))/2;
        ans.insert(sum);
       ll j= n/i;
        now = n/j;
        sum = ((2*1 + (now-1)*j)*(now))/2;
        ans.insert(sum);     
    }
 }
  
 for(ll i:ans)cout<<i<<" ";cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}