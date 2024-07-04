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
int arr[n];
int mx = 0;
int g= 0;
for(int i=0;i<n;i++)cin>>arr[i], mx = max(mx, arr[i]) , g= __gcd(arr[i], g);
int prime[mx+10];
for(int i=0;i<=mx;i++)prime[i] = i;
for(int i=2;i<=sqrt(mx);i++){
  for(int j=i*i;j<=mx;j+=i){
       if(prime[j]==j)prime[j] = i;
  }
} 
int ans[mx+10];  
for(int i=0;i<=mx;i++)ans[i] = 0;
for(int i=0;i<n;i++){
  arr[i]/=g;
   while(arr[i]>1){
    int num = prime[arr[i]];
    while(arr[i]%num==0){
      arr[i]/=num;
    }
     ans[num]++;
   }
}
int result = 0;
for(int i=2;i<=mx;i++){
  result = max(result , ans[i]);
}
if(result == 0){
cout<<-1<<endl;
}else{
  cout<<n-result<<endl;
}
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t = 1;
while(t--){
solve();
}
}