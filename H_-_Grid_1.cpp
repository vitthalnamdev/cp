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
 int n,m;cin>>n>>m;
 vector<string>arr(n);
 for(int i=0;i<n;i++)cin>>arr[i];
 vector<vector<ll>>dp(n+1 , vector<ll>(m+1,0));
 dp[0][0] = 1;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i-1>=0 && arr[i-1][j]=='.')dp[i][j] += (dp[i-1][j]);
        dp[i][j]%=mod;
        if(j-1>=0 && arr[i][j-1]=='.')dp[i][j] += (dp[i][j-1]);
        dp[i][j]%=mod;
    }
 }
 cout<<dp[n-1][m-1]%mod;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}