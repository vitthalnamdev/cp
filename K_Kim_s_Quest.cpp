#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod = 998244353;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
  ll n;cin>>n;
  ll arr[n];
  for(int i=0;i<n;i++)cin>>arr[i],arr[i]%=2;
  ll ans=0;
  ll zero = 0; ll one = 0;
  ll count[4]={0,0,0,0};
   
  for(int i=0;i<n;i++){
     if(arr[i]==0){
        ans+=(count[0] + count[3]);
        count[0]+=(count[0] + zero);
        count[2]+=(one + count[3]);
        ans%=mod;count[0]%=mod;count[2]%=mod;
        zero++;
     }else{
        ans+=(count[1] + count[2]);
        ans%=mod;
        count[3]+=(one + count[1]);
        count[1]+=(count[2] + zero);
        count[3]%=mod;
        count[1]%=mod;
        one++;
     }
  }
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}