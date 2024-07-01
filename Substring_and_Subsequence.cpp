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
 string a,b;cin>>a>>b;   
 int n=a.length();int m = b.length();
 int mx = 0;
 int ans =n+m;
 int pref[n];
 for(int i=0;i<m;i++){
    int p1 = i;int count=0;
   for(int j=0;j<n;j++){
    if(p1>=m){
        break;
    }
     if(a[j]==b[p1]){p1++;count++;}
   }
   mx = max(mx, count);
 }
  for(int i=m-1;i>=0;i--){
     
    int p1 = i;int count = 0;
    for(int j=n-1;j>=0;j--){
       if(p1<0){
        break;
        }
     if(a[j]==b[p1]){p1--;count++;}
    }
    mx = max(mx, count);
  } 
   
cout<<ans-mx<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}