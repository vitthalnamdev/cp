#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below gcc target.
//#pragma GCC target()

int mod = 1e9+7;    
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)

ll inv(ll a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

ll value(ll a, ll b){
    return ((a-b)%mod+ mod)%mod;
}

long long binary(long long a, long long b ) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve(){
 string s;cin>>s;
 ll n = s.length();
 ll pref[n];
 for(int i=0;i<n;i++){
    pref[i] = ((i-1>=0?pref[i-1]:0)  +  ((s[i] - 'a' + 1)*binary(31LL,(ll)i))%mod )%mod;
 }
 ll ans = 0;
  if(n%2==0){
   ll string1, string2, string3, string4;
   int i = n-1;
      string1 = pref[(i)/2];
      ll num = binary(31, (i+1)/2);
      num = inv(num);
      string2 =  (value(pref[i] , pref[i/2])*(num))%mod;
      if(string1==string2)ans+=2;
 }
 for(int i=1;i<n-1;i++){
   if((i)%2 && (n-i-1)%2==0){
      int diff=(n-i-1)/2;
        
      ll string1, string2, string3, string4;
      string1 = pref[(i)/2];
       
      ll num = binary(31, (i+1)/2)%mod;
      num = (inv(num)  +  mod )%mod;
      string2 =  ((value(pref[i],pref[i/2]))*(num))%mod;
       
      num = binary(31, (i+1))%mod;
      num = inv(num)%mod;
      string3 =  (value(pref[i+diff],pref[i])*(num))%mod;
      num = binary(31,n-diff)%mod;
      num = inv(num)%mod;
      string4 =  (value(pref[n-1],pref[n-diff-1])*(num))%mod;
       
      if(string1==string2 && string3==string4){
        ans++;
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