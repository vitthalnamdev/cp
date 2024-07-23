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
vector<vector<int>>arr(n , vector<int>(3));
for(int i=0;i<n;i++){
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
}
vector<vector<ll>>dp(n+1 , vector<ll>(3,0));
for(int i=0;i<n;i++){
  dp[i+1][0] = arr[i][0] + max(dp[i][1] , dp[i][2]);
  dp[i+1][1] = arr[i][1] + max(dp[i][0] , dp[i][2]);
  dp[i+1][2] = arr[i][2] + max(dp[i][0] , dp[i][1]);
}
cout<<max(dp[n][0] , max(dp[n][1] , dp[n][2]));

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}