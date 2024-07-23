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
  ll n , w ;cin>>n>>w;
  ll weight[n] , value[n];
  int sum = 0;
  for(int i=0;i<n;i++){
    cin>>weight[i]>>value[i];
    sum+=value[i];
  }
  vector<vector<ll>>dp(n+1 , vector<ll>(sum+10 , INT_MAX));
   dp[0][0] = 0;
  for(int i=0;i<n;i++){
    dp[i][0] = 0;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=sum;j++){
        if(j+value[i]<=sum){
            dp[i+1][j+value[i]] = min(dp[i+1][j+value[i]] , dp[i][j] + weight[i]);
        }
       dp[i+1][j] = min(dp[i+1][j] , dp[i][j]);  
    }
  }
  int answer = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=sum;j++){
       if(dp[i][j]<=w){
        answer = max(answer , j);
       }
    }
  }
  cout<<answer;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}