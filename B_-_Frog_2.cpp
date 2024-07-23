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
 int n;cin>>n;int k;cin>>k;int arr[n+1];
 for(int i=1;i<=n;i++)cin>>arr[i];
 ll dp[n+1];
 for(int i=0;i<=n;i++)dp[i] = LLONG_MAX;
 
 dp[1] = 0; 
 for(int i=2;i<=n;i++){
    for(int j=i-1;j>=max(i-k , 1);j--){
       dp[i] = min(dp[j] + abs(arr[i] - arr[j]) , dp[i] );
    }
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