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
 ll arr[3];
 cin>>arr[0]>>arr[1]>>arr[2];
 sort(arr,arr+3);
 ll ans = arr[0]/3 + arr[1]/3 + arr[2]/3;
 for(int i=1;i<=3;i++){
    ll brr[3];
    brr[0]=arr[0] - i;brr[1]=arr[1] - i;brr[2]=arr[2] - i;
    if(brr[0]<0){break;}
    ans = max(ans ,i + brr[0]/3 + brr[1]/3 + brr[2]/3);
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
 