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
  double coins[n];
  for(int i=0;i<n;i++){
    cin>>coins[i];
  }
  // dp[j+1] denotes j+1 heads , when we reach until i , j<i
  vector<double>dp(n+1 , 0);
  dp[0] = 1;
  for(int i=0;i<n;i++){
    dp[i+1] = dp[i]*coins[i];
    for(int j = i-1;j>=0;j--){
         dp[j+1] = dp[j+1]*(1-coins[i]) + dp[j]*coins[i];
    }
    dp[0]*=(1-coins[i]);
  }
  double answer = 0;
  for(int i=n/2+1;i<=n;i++){
     answer += (dp[i]);
  }
  cout<<setprecision(14)<<fixed;
  cout<<answer;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}