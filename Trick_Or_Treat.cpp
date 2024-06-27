#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below gcc target.
//#pragma GCC target()
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
int n;cin>>n;int k;cin>>k;
int frst[n];int secod[101];
for(int i=0;i<n;i++){
  int x;cin>>x;frst[i]=x;
  frst[i]=(k-frst[i]%k)%k;
}
for(int i=0;i<=100;i++)secod[i]=0;
for(int i=0;i<n;i++){
 int x;cin>>x;x%=k;
  secod[x]++; 
}
ll ans =0;
for(int i=0;i<n;i++){
   // cout<<frst[i]<<endl;
    ans+=(secod[frst[i]]);
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