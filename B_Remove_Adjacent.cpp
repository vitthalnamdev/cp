#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
//(popcount) in the below GCC target.
#pragma GCC target()
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
 int n;cin>>n;
 string s;cin>>s;



 for(int i='z';i>'a';i--){
    for(int k=0;k<s.size();k++){
        if(s[k]==i && (s[k-1]==i-1 || s[k+1]==i-1)){
            s.erase(k,1);k=-1;           
        }   
    }
 }
  cout<<n-s.size()<<endl;
 
 
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}