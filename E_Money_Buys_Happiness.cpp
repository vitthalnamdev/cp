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
ll m , x;cin>>m>>x;
vector<pair<ll,ll>>arr(m);ll sum = 0;
for(int i=0;i<m;i++){
    cin>>arr[i].first>>arr[i].second;
    sum+=(arr[i].second);
}
vector<vector<ll>>dp(m+1, vector<ll>(sum+10 , LLONG_MAX));
dp[0][0] = 0;
ll money = 0;
for(int i=0;i<m;i++){
    if(money>=arr[i].first)
    dp[i][arr[i].second] = arr[i].first;
    dp[i][0] = 0;
    for(int j=0;j<=sum;j++){
        for(int k=0;k<i;k++){
            if(dp[k][j]!=LLONG_MAX && dp[k][j] + arr[i].first <= money){
                dp[i][j + arr[i].second] =  min(dp[i][j+arr[i].second], dp[k][j] + arr[i].first);
            }
        }
    }
    money+=x;
}
int ans = 0;
for(int i=0;i<m;i++){
    for(int j=0;j<=sum;j++){
        
      if(dp[i][j]<LLONG_MAX){
          ans = max(ans , j);
      }
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