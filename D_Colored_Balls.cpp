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
 ll sum = 0;
 for(int i=0;i<n;i++){
  cin>>arr[i];
  sum+=arr[i];
 }
sort(arr,arr+n);
 ll answer = 0;
 ll dp[sum+10]; 
 for(int i=0;i<=sum;i++)dp[i]=0;

  dp[0] = 1; 
 for(int i=0;i<n;i++){
    for(int j=sum-arr[i];j>=0;j--){
       dp[j+arr[i]] += dp[j] ;
       dp[j+arr[i]]%=mod;
    }
  }
  for(ll i=0;i<=sum;i++){
    answer += (dp[i] * ((i+1)/2));
    answer%=mod;
  }  
  for(int i=0;i<n;i++){
    for(int j=0;j<arr[i];j++){
          
          answer +=(( arr[i] - (arr[i] + j+1)/2 )*dp[j]);
          answer%=mod;
    }
  }
  cout<<answer<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}