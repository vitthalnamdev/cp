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
ll n;cin>>n;ll k;cin>>k;
ll arr[n]; 
for(int i=0;i<n;i++)cin>>arr[i];
 
sort(arr,arr+n); 
ll cnt = 0;ll curr = -1;
for(int i=n-1;i>=n-k;i--){
 if(arr[i]!=curr)curr=arr[i],cnt=1;
 else {cnt++;}
}int total = 0;
for(int i=0;i<n;i++){
 if(arr[i]==curr)total++;
} 
ll fact[n+1];
fact[0] = 1;
for(int i=1;i<=n;i++){
    fact[i] = i*fact[i-1];
    fact[i]%=mod;
}
ll inverse = (fact[cnt]+mod)*(fact[total-cnt]+mod)%mod;
inverse = inv(inverse);
inverse = (fact[total]+mod)*inverse;
inverse%=mod;
cout<<inverse<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}