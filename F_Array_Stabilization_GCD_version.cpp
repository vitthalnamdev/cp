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
int n;cin>>n;
int arr[n+1];int g = 0;
for(int i=0;i<n;i++)cin>>arr[i], g = __gcd(arr[i], g);
arr[n] = arr[0];
int gcd[n];int prev = -1;
for(int i=0;i<n;i++){
    if(arr[i]==g){gcd[i] = 0;if(prev==-1)prev = i;}
    else if(__gcd(arr[i], arr[i+1])==g){
        gcd[i] = 1;if(prev==-1)prev = i;
    }else{
        gcd[i] = -1;
    }
}
 
 int offset = gcd[prev]==0?0:1;
 prev = prev  + n;
 for(int i=0;i<n;i++)cout<<gcd[i]<<" ";cout<<endl;
  for(int i=n-1;i>=0;i--){
   
       if(gcd[i]==1){
         prev = i;offset = 1;
       }else if(gcd[i] == 0){
         prev = i;offset = 0;
       }
       else{
          gcd[i] = prev - i + offset ;
       }
  }
  int ans = 0;
  for(int i=0;i<n;i++)ans= max(ans, gcd[i]);
  cout<<ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}