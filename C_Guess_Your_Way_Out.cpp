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
ll ans = 0;
bool f=0;
ll dp[51][2];
bool path(ll ht, bool curr, ll pos , bool noww){
   if(ht==-1){
    return false;
   }
   if(ht==0 && dp[ht][noww] + 1 == pos){
     f=1;  return true;
   }
   if(dp[ht][noww] +1 > pos || (dp[ht][noww] +  (1LL<<ht)) < pos){
       ll now = (1LL<<(ht+1)) - 1;
      
       if(f==0)
       ans+=now;
        return false;
   }
     
    
   dp[ht-1][0] = dp[ht][noww];
   dp[ht-1][1] = dp[ht][noww] + (1LL<<(ht-1));
  
   int current = path(ht-1 , curr^1, pos , curr);
   if(current==1){
    ans++;
    return true;
   }
   current = path(ht-1, curr, pos , curr^1);
   if(current==true){ans++;return true;}
   return false;
}
void solve(){
  ll n, h;cin>>n>>h; 
  path(n,0,h,0);
   
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}