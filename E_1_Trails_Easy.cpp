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
 ll n,m;cin>>m>>n;
 ll s[m],l[m];
 for(int i=0;i<m;i++){
    cin>>s[i];
 }
 vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
 dp[0][0] = 1;
 for(int i=0;i<m;i++){cin>>l[i];}
 for(int i=1;i<=n;i++){
   for(int j=0;j<m;j++){
    for(int k=0;k<m;k++){
       dp[i][j] += (dp[i-1][k]*(((s[j] + l[j])*(s[k]+l[k]))%mod + mod - ((l[j])*(l[k]))% mod  + mod)  + mod )%mod;
       dp[i][j]%=mod;
    }
   }
 }
 ll ans = 0;
 for(int i=0;i<m;i++){
    
    ans+=((dp[n][i]) + mod ) % mod ;
   
 } 
 
 cout<<ans%mod<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}