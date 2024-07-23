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
 ll n,w;cin>>n>>w;
 ll arr[n],value[n];
 for(int i=0;i<n;i++){
    cin>>arr[i]>>value[i];
 }
  
 vector<vector<ll>>dp(n + 1 , vector < ll > ( w+1 , 0 ));
 for(int i=0;i<n;i++){
   for(int j =0 ;j <= w ;j++){
     if(j-arr[i]>=0){
           dp[i+1][j] = max( dp[i+1][j ]  , dp[i][j-arr[i]] + value[i]);
       
     }
        dp[i+1][j] = max(dp[i+1][j] , dp[i][j]);
   }
 }
 
 cout<<*max_element(dp[n].begin(), dp[n].end());

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}