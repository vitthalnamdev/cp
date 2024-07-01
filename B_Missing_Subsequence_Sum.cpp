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
 int n, k;cin>>n>>k;
 int curr = 1;ll sum = 0;
 ll prevsum = 0;
 vector<int>ans;
 bool f= 0;bool ff= 0;
 while(sum<=n){ 
    
    if(k>sum && k<=prevsum+1){
       curr = k - 1 - sum;
       if(ans.size()>0 && sum + curr>ans.back()){
         ans.push_back(sum + curr);
         prevsum+=(ans.back());
       }
       ans.push_back( sum + curr + 2);
       prevsum+=(ans.back());
       f=1;
    }
        sum = prevsum + 1 - 2*ff;
        ans.push_back(sum);
        prevsum +=sum;ff = f;
 }
 cout<<ans.size()<<endl;
 for(auto i:ans)cout<<i<<" ";cout<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}