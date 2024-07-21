#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
//#pragma GCC target()
int mod =3;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
const int mx = 1000001;
int prime[mx+10];
void sieve(){
  for(int i=1;i<=mx;i++){
    prime[i] = i;
  }
  for(int i=2;i*i<=mx;i++){
    for(int j=i*i;j<=mx;j+=i){
      if(prime[j]==j)prime[j] = i;
    }
  }
}
void solve(){
 ll n,k;cin>>n>>k;
 int arr[n];
 for(int i=0;i<n;i++)cin>>arr[i];
 ll lcm = 1;vector<ll>cnt(1000001,0);
 for(int i=0;i<n;i++){
  map<ll,ll>temp;
   while(arr[i]>1){
    temp[prime[arr[i]]]++;
    arr[i]/=prime[arr[i]];
   }
   for(auto i:temp){   
     cnt[i.first] = max(cnt[i.first] ,temp[i.first]);
   }
 }
 for(ll i=1;i<=mx;i++){
     ll curr = 1;
     for(int j=1;j<=cnt[i];j++){
      curr*=i;
     }
    curr = __gcd(k , curr);
    k/=curr;
 }  
   
 if(k==1){
  cout<<"Yes"<<endl;
 }else{
  cout<<"No"<<endl;
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
sieve();
while(t--){
solve();
}
}