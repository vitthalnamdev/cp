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
template<typename T>
void input(T arr , int n){
  for(int i=0;i<n;i++)cin>>arr[i];
}
template<typename T>
void output(T arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void solve(){
  ll n;cin>>n;
  ll arr[n];
  input(arr , n);
  map<tuple<ll,ll,ll>,ll>count;
  ll ans = 0;
  for(ll i=0;i<n-2;i++){
     ans+=(count[{arr[i], arr[i+1] , 0}] + count[{0, arr[i+1] ,arr[i+2]}]  + count[{arr[i] , 0 , arr[i+2]}]);
     ans-=(3*(count[{arr[i] , arr[i+1] , arr[i+2]}]));
     count[{arr[i], arr[i+1], arr[i+2]}]++;
     count[{arr[i], arr[i+1] , 0}]++;
     count[{0, arr[i+1], arr[i+2]}]++;
     count[{arr[i] , 0 , arr[i+2]}]++;
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