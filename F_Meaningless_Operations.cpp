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
 bool f=0;int num1 = 0;
 
 for(int i=26;i>=0;i--){
   if(((1<<i)&n)){
     num1=((1<<(i+1))-1);
     break;
   }
 }
  int check = (num1&n);
  if(check==num1){
    int ans = 1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            ans = max(n/i , i);break;
        }
    }
    cout<<ans<<endl;
  }else{
    cout<<num1<<endl;
  }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}