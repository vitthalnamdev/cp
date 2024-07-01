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
 for(int i=0;i<n;i++)cin>>arr[i];

 ll prefix[n];
  prefix[n-1]=arr[n-1];
 for(int i=n-2;i>=0;i--){
    if(arr[i]>arr[i+1]){
        prefix[i] = arr[i];
        int diff = arr[i] - arr[i+1];
        int w = prefix[i+1] - arr[i+1];
        if(w>=diff){
            prefix[i] = prefix[i+1] + 1;
        }else{
            prefix[i] = arr[i];
        }
    }
    else 
    prefix[i] = prefix[i+1]+1;
 }
 ll ans = 0;
 for(int i=0;i<n;i++){
   ans= max(ans, prefix[i]);
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