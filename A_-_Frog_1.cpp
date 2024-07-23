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
 int n;cin>>n;int arr[n+1];
 for(int i=1;i<=n;i++)cin>>arr[i];
 ll dp[n+1];
 for(int i=0;i<=n;i++)dp[i] = LLONG_MAX;
 dp[0] = 0;
 dp[1] = 0;dp[2] = arr[2];
 for(int i=2;i<=n;i++){
     if(i==2){dp[i] = dp[i-1] +abs( arr[i] - arr[i-1] );continue;}
     dp[i] = min(dp[i-2] + abs(arr[i] - arr[i-2]) , dp[i-1] + abs(arr[i] - arr[i-1]));
 }
 cout<<dp[n]<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}