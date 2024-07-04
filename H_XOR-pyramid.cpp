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
int dp[5005][5005];
void solve(){
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  for(int i=0;i<n;i++)dp[0][i] = arr[i];
  for(int i=1;i<n;i++){
     for(int j=0;j<=n-i;j++){
        dp[i][j] = dp[i-1][j] ^ dp[i-1][j+1];
     }
  }
  
  for(int j=n-1;j>=0;j--){
     for(int i=0;i<=n-j;i++){   
        dp[i][j] = max(dp[i][j], max((i-1>=0?dp[i-1][j]:0) ,(i-1>=0? dp[i-1][j+1]:0)));
     }
  } 
  int q;cin>>q;
  while(q--)
  {
    int l,r;cin>>l>>r;l--;
   
    cout<<dp[r-l-1][l]<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}